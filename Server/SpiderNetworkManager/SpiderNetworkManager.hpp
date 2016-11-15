//
// Created by hippolyteb on 11/7/16.
//

#ifndef SPIDER_SERVER_SPIDERNETWORKMANAGER_HPP
#define SPIDER_SERVER_SPIDERNETWORKMANAGER_HPP

#include <thread>
#include <map>
#include "../Interfaces/ISpiderNetworkManager.hpp"
#include "../SpiderEventManager/SpiderEventEmitter.hpp"
#include "../SpiderEventManager/SpiderEventListener.hpp"
#include "../SpiderSocket/ZeroMQ/ZeroMQSocketPoller.hpp"
#include "../ProtoEnvelopes/Proto/SpiderEnveloppe.pb.h"
#include "../Serialization/SpiderDeserializer.hpp"
#include "../Interfaces/ISpiderCryptographicAgent.hpp"
#include "RSACryptographicAgent.hpp"
#include "../SpiderSocket/ZeroMQ/ZeroMQSecureSocket.hpp"
#include "../Interfaces/ISpiderServer.hpp"
#include "../SpiderSocket/ZeroMQ/ZeroMQEventMonitor.hpp"
#include "../SpiderSocket/ZeroMQ/ZeroMQCommanderSocket.hpp"

class SpiderNetworkManager : public ISpiderNetworkManager {
private:
    std::unique_ptr<std::thread> _networkMenagerThread;
    std::unique_ptr<std::thread> _networkMenagerCommanderThread;
    std::unique_ptr<std::thread> _networkMenagerMonitorThread;

    std::shared_ptr<ISpiderSocket> _socket;
    std::unique_ptr<ZeroMQEventMonitor> _monitor;

    std::shared_ptr<zmq::socket_t> _monitorSocket;
    std::shared_ptr<ISpiderSocket> _commanderSocket;
    std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(new SpiderEventEmitter());
    std::unique_ptr<ISpiderEventEmitter> _commandEmitter = std::unique_ptr<ISpiderEventEmitter>(new SpiderEventEmitter());
    std::unique_ptr<ISpiderEventListener<SpiderEnveloppe>> _eventListener = std::unique_ptr<ISpiderEventListener<SpiderEnveloppe>>(new SpiderEventListener<SpiderEnveloppe>());
    std::unique_ptr<ISpiderEventListener<SpiderEnveloppe>> _eventCommanderListener = std::unique_ptr<ISpiderEventListener<SpiderEnveloppe>>(new SpiderEventListener<SpiderEnveloppe>());

    std::map<std::string, std::unique_ptr<ISpiderSocket>> _socketPool;

private:

    void HandleMessage(std::string message) {
        SpiderEnveloppe envelope;
        try {
            envelope = SpiderDeserializer::GetEnvelopeFromMessage(message);
            _eventEmitter->RouteToModules(envelope); //Dispatch message to inner communication service.
        }
        catch (const std::runtime_error& e) {
            std::cout << "Error : " << e.what() << std::endl;
            return;
        }
    }
    void HandleCommandMessage(std::string message) {
        SpiderEnveloppe envelope;
        try {
            envelope = SpiderDeserializer::GetEnvelopeFromMessage(message);
            _commandEmitter->RouteToModules(envelope); //Dispatch message to inner communication service.
        }
        catch (const std::runtime_error& e) {
            std::cout << "Error : " << e.what() << std::endl;
            return;
        }
    }

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

    void RunReceive() {
        std::unique_ptr<ISpiderSocketPoller> poller = std::unique_ptr<ISpiderSocketPoller>(new ZeroMQSocketPoller());
        while (true) {
            std::vector<ISpiderSocket *> sockets;
            for(std::map<std::string, std::unique_ptr<ISpiderSocket>>::iterator it = _socketPool.begin(); it != _socketPool.end(); ++it )
                sockets.push_back(it->second.get());
            auto msg = poller->ReceivePoller(_socket.get(), sockets);
            HandleMessage(std::get<1>(msg));
        }
    }

    void RunCommanderReceive() {
        while (true) {
            auto msg = _commanderSocket->Receive();
            HandleCommandMessage(msg);
        }
    }
#pragma clang diagnostic pop

public:
    SpiderNetworkManager() {
        _socket = std::shared_ptr<ISpiderSocket>(new ZeroMQSecureSocket<Server>("JTKVSB%%)wK0E.X)V>+}o?pNmC{O&4W4b!Ni{Lh6"));

        _monitorSocket = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_PAIR));
        _commanderSocket = std::shared_ptr<ISpiderSocket>(new ZeroMQCommanderSocket());
    }

    virtual ~SpiderNetworkManager() {
        _socket->Disconnect();
        _commanderSocket->Disconnect();
    }

    void Run() override final {
        _socket->Bind("tcp://*:5432");
        _commanderSocket->Bind("tcp://*:9876");

        _networkMenagerThread = std::unique_ptr<std::thread>(new std::thread(std::bind(&SpiderNetworkManager::RunReceive, this)));
        _networkMenagerCommanderThread = std::unique_ptr<std::thread>(new std::thread(std::bind(&SpiderNetworkManager::RunCommanderReceive, this)));
        _eventListener->Register("SpiderNetworkManager", [&](std::string clientId, SpiderEnveloppe &enveloppe) {
            std::string enveloppe_data;
            enveloppe.SerializeToString(&enveloppe_data);
            _socket->Send(enveloppe.clientid(), enveloppe_data);
        });
        _eventCommanderListener->Register("Commander:SpiderNetworkManager", [&](std::string clientId, SpiderEnveloppe &enveloppe) {
            std::string enveloppe_data;
            enveloppe.SerializeToString(&enveloppe_data);
            _commanderSocket->Send(enveloppe.clientid(), enveloppe_data);
        });
    }
};

#endif //SPIDER_SERVER_SPIDERNETWORKMANAGER_HPP
