//
// Created by hippolyteb on 11/8/16.
//

#ifndef SPIDER_SERVER_SPIDEREVENTEMITTER_HPP
#define SPIDER_SERVER_SPIDEREVENTEMITTER_HPP

#include <thread>
#include <iostream>
#include "../Interfaces/Event/ISpiderEventEmitter.hpp"
#include "../Includes/ZeroMQ/zmq.hpp"
#include "../Interfaces/ISpiderServer.hpp"
#include "../Includes/ZeroMQ/zmq_addon.hpp"

class SpiderEventEmitter : public ISpiderEventEmitter {
    std::shared_ptr<zmq::socket_t> _socketPUB = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_PUB));

public:
    SpiderEventEmitter() {
        _socketPUB->connect("inproc://EventListener");
    }

    void Emit(std::string destinator, SpiderEnveloppe &payload) override final {
        zmq::multipart_t msg;
        msg.addstr(destinator);
        std::string temp = payload.SerializeAsString();
        msg.addstr(temp);
        msg.send(*_socketPUB);
    }

    void RouteToModules(SpiderEnveloppe &payload) override final {
        Emit(payload.payloadtype(), payload);
    }
};

#endif //SPIDER_SERVER_SPIDEREVENTEMITTER_HPP
