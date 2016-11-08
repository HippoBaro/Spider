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

class SpiderEventEmitter : public ISpiderEventEmitter {
    std::shared_ptr<zmq::socket_t> _socketPUB = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_PUB));

public:
    SpiderEventEmitter() {
        _socketPUB->connect("inproc://EventListener");
    }

    template<typename T>
    void Emit(T message) {
        //todo serialize and push
    }
};

#endif //SPIDER_SERVER_SPIDEREVENTEMITTER_HPP
