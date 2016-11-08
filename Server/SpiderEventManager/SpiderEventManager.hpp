//
// Created by hippolyteb on 11/7/16.
//

#ifndef SPIDER_SERVER_SPIDEREVENTMANAGER_HPP
#define SPIDER_SERVER_SPIDEREVENTMANAGER_HPP

#include <thread>
#include "../Interfaces/ISpiderEventManager.hpp"
#include "../Includes/ZeroMQ/zmq.hpp"
#include "../Interfaces/ISpiderServer.hpp"

class SpiderEventManager : public ISpiderEventManager {
private:
    std::unique_ptr<std::thread> _eventManagerThread;

    std::shared_ptr<zmq::socket_t> _socketPUB;
    std::shared_ptr<zmq::socket_t> _socketSUB;

    static void RunReceive(zmq::socket_t *socketSub, zmq::socket_t *socketPub) {
        while (true) {
            zmq::message_t msg;
            socketSub->recv(&msg);
            socketPub->send(msg);
        }
    }

public:
    SpiderEventManager() {
        _socketPUB = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_PUB));
        _socketSUB = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_SUB));
    }

public:
    void Run() override final {
        _socketPUB->bind("inproc://EventEmitter");
        _socketSUB->bind("inproc://EventListener");

        _eventManagerThread = std::unique_ptr<std::thread>(new std::thread(RunReceive, _socketSUB.get(), _socketPUB.get()));
    }
};

#endif //SPIDER_SERVER_SPIDEREVENTMANAGER_HPP
