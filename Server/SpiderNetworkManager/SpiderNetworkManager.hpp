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
#include "../SpiderSocket/ZeroMQ/ZeroMQSocket.hpp"
#include "../SpiderSocket/ZeroMQ/ZeroMQSocketPoller.hpp"
#include "../ProtoEnvelopes/Proto/SpiderEnveloppe.pb.h"
#include "../Serialization/SpiderDeserializer.hpp"
#include "../Interfaces/ISpiderCryptographicAgent.hpp"
#include "RSACryptographicAgent.hpp"

class SpiderNetworkManager : public ISpiderNetworkManager {
private:
    std::unique_ptr<std::thread> _networkMenagerThread;
    std::unique_ptr<std::thread> _networkMenagerCommanderThread;

    std::shared_ptr<ISpiderSocket> _socket;
    std::shared_ptr<zmq::socket_t> _commanderSocket;
    std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(new SpiderEventEmitter());
    std::unique_ptr<ISpiderEventListener<SpiderEnveloppe>> _eventListener = std::unique_ptr<ISpiderEventListener<SpiderEnveloppe>>(new SpiderEventListener<SpiderEnveloppe>());
    std::unique_ptr<ISpiderEventListener<SpiderEnveloppe>> _eventListenerNoEncrypt = std::unique_ptr<ISpiderEventListener<SpiderEnveloppe>>(new SpiderEventListener<SpiderEnveloppe>());

    std::map<std::string, std::unique_ptr<ISpiderSocket>> _socketPool;

private:

    bool hasEnding (std::string const &fullString, std::string const &ending) {
        if (fullString.length() >= ending.length()) {
            return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
        } else {
            return false;
        }
    }

    void HandleMessage(std::string clientId, std::string message) {
        SpiderEnveloppe envelope;

        if (!hasEnding(clientId, "authorisation")) {
           //todo decrypt AES
        }

        try {
            envelope = SpiderDeserializer::GetEnvelopeFromMessage(message);
        }
        catch (const std::runtime_error& e) {
            std::cout << "Error : " << e.what() << std::endl;
            return;
        }
        if (!hasEnding(clientId, "authorisation"))
            _eventEmitter->RouteToModules(envelope); //Dispatch message to inner communication service.
        else
            _eventEmitter->Emit("SpiderAuthenticationPayload", envelope);
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
            HandleMessage(std::get<0>(msg), std::get<1>(msg));
        }
    }
#pragma clang diagnostic pop

public:
    SpiderNetworkManager() {
        _socket = std::shared_ptr<ISpiderSocket>(new ZeroMQSocket());
        _commanderSocket = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_REP));
    }

    virtual ~SpiderNetworkManager() {
        _socket->Disconnect();
        _commanderSocket->close();
    }

    void Run() override final {
        _socket->Bind("tcp://*:5432");
        _commanderSocket->bind("tcp://*:9876");

        _networkMenagerThread = std::unique_ptr<std::thread>(new std::thread(std::bind(&SpiderNetworkManager::RunReceive, this)));
        _eventListener->RegisterNoUnpack("SpiderNetworkManager", [&](std::string clientId, SpiderEnveloppe &enveloppe) {
            std::string enveloppe_data;
            enveloppe.SerializeToString(&enveloppe_data);
            _socket->Send(enveloppe.clientid(), enveloppe_data);
        });
        _eventListenerNoEncrypt->RegisterNoUnpack("NoEncryption:SpiderNetworkManager", [&](std::string clientId, SpiderEnveloppe &enveloppe) {
            std::string enveloppe_data;
            enveloppe.SerializeToString(&enveloppe_data);
            _socket->Send(enveloppe.clientid(), enveloppe_data);
        });
    }
};

#endif //SPIDER_SERVER_SPIDERNETWORKMANAGER_HPP
