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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    static void RunReceive(zmq::socket_t *socketSub, zmq::socket_t *socketPub) {
        while (true) {
            zmq::multipart_t rep;
            zmq::message_t msg;
            socketSub->recv(&msg);
            std::string ret = std::string(static_cast<char*>(msg.data()), msg.size());
            rep.addstr(ret);
            zmq::message_t msg2;
            socketSub->recv(&msg2);
            ret = std::string(static_cast<char*>(msg2.data()), msg2.size());
            rep.addstr(ret);
            rep.send(*socketPub, 0);
        }
    }
#pragma clang diagnostic pop

public:
    SpiderEventManager() {
        _socketPUB = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_PUB));
        _socketSUB = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_SUB));
    }

public:
    void Run() override final {
        _socketPUB->bind("inproc://EventEmitter");
        _socketSUB->bind("inproc://EventListener");
        _socketSUB->setsockopt(ZMQ_SUBSCRIBE, "", 0);

        _eventManagerThread = std::unique_ptr<std::thread>(new std::thread(RunReceive, _socketSUB.get(), _socketPUB.get()));
    }
};

#endif //SPIDER_SERVER_SPIDEREVENTMANAGER_HPP
