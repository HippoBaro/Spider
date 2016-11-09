//
// Created by hippolyteb on 11/8/16.
//

#ifndef SPIDER_SERVER_SPIDEREVENTEMITTER_HPP
#define SPIDER_SERVER_SPIDEREVENTEMITTER_HPP

#include <thread>
#include <iostream>
#include "../Interfaces/ISpiderEventEmitter.hpp"
#include "../Includes/ZeroMQ/zmq.hpp"
#include "../Interfaces/ISpiderServer.hpp"
#include "../Includes/ZeroMQ/zmq_addon.hpp"

class SpiderEventEmitter : public ISpiderEventEmitter {
    std::shared_ptr<zmq::socket_t> _socketPUB = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_PUB));

public:
    SpiderEventEmitter() {
        _socketPUB->connect("inproc://EventListener");
    }

    void Emit(std::string id, std::string message) override final {
        zmq::multipart_t msg;
        msg.addstr(id);
        msg.addstr(message);
        msg.send(*_socketPUB);
    }
};

#endif //SPIDER_SERVER_SPIDEREVENTEMITTER_HPP
