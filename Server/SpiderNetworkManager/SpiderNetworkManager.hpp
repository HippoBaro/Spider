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

class SpiderNetworkManager : public ISpiderNetworkManager {
private:
    std::unique_ptr<std::thread> _networkMenagerThread;
    std::unique_ptr<std::thread> _networkMenagerCommanderThread;

    std::shared_ptr<ISpiderSocket> _socket;
    std::shared_ptr<zmq::socket_t> _commanderSocket;

    std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(new SpiderEventEmitter());
    std::unique_ptr<ISpiderEventListener> _eventListener = std::unique_ptr<ISpiderEventListener>(new SpiderEventListener());

    std::map<std::string, std::unique_ptr<ISpiderSocket>> _socketPool;

private:
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    static void RunReceive(ISpiderSocket *socket, std::map<std::string, std::unique_ptr<ISpiderSocket>> *pool, ISpiderEventEmitter *eventEmitter) {
        std::unique_ptr<ISpiderSocketPoller> poller = std::unique_ptr<ISpiderSocketPoller>(new ZeroMQSocketPoller());
        while (true) {
            std::vector<ISpiderSocket *> sockets;
            for(std::map<std::string, std::unique_ptr<ISpiderSocket>>::iterator it = pool->begin(); it != pool->end(); ++it ) {
                sockets.push_back(it->second.get());
            }
            auto msg = poller->ReceivePoller(socket, sockets);
            auto payload = std::get<0>(msg) + ":" + std::get<1>(msg);
            eventEmitter->Emit("OutputSTDIN", payload);
            //std::cout << "Message from ID : " <<  << " Payload is : " << std::get<1>(msg) << std::endl;
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

        _networkMenagerThread = std::unique_ptr<std::thread>(new std::thread(RunReceive, _socket.get(), &_socketPool, _eventEmitter.get()));
    }

    void SendMessage(std::string id, std::string data) {
    }
};

#endif //SPIDER_SERVER_SPIDERNETWORKMANAGER_HPP
