//
// Created by hippolyteb on 11/7/16.
//

#ifndef SPIDER_SERVER_SPIDERNETWORKMANAGER_HPP
#define SPIDER_SERVER_SPIDERNETWORKMANAGER_HPP

#include <thread>
#include "../Interfaces/ISpiderNetworkManager.hpp"
#include "../Includes/ZeroMQ/zmq.hpp"
#include "../SpiderEventManager/SpiderEventEmitter.hpp"
#include "../SpiderEventManager/SpiderEventListener.hpp"

class SpiderNetworkManager : public ISpiderNetworkManager {
private:
    std::unique_ptr<std::thread> _networkMenagerThread;
    std::unique_ptr<std::thread> _networkMenagerCommanderThread;

    std::shared_ptr<zmq::socket_t> _socket;
    std::shared_ptr<zmq::socket_t> _commandrSocket;

    std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(new SpiderEventEmitter());
    std::unique_ptr<ISpiderEventListener> _eventListener = std::unique_ptr<ISpiderEventListener>(new SpiderEventListener<std::string>());

private:
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    static void RunReceive(zmq::socket_t *socket) {
        while (true) {
            zmq::message_t msg;
            socket->recv(&msg);
        }
    }
#pragma clang diagnostic pop

public:
    SpiderNetworkManager() {
        _socket = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_ROUTER));
        _commandrSocket = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_REP));
    }

    virtual ~SpiderNetworkManager() {
        _socket->close();
        _commandrSocket->close();
    }

    void Run() override final {
        _socket->bind("tcp://*:5432");
        _commandrSocket->bind("tcp://*:9876");

        _networkMenagerThread = std::unique_ptr<std::thread>(new std::thread(RunReceive, _socket.get()));
    }

    void SendMessage(std::string id, std::string data) {
    }
};

#endif //SPIDER_SERVER_SPIDERNETWORKMANAGER_HPP
