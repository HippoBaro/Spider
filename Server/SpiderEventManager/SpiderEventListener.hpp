//
// Created by hippolyteb on 11/8/16.
//

#ifndef SPIDER_SERVER_SPIDEREVENTLISTENER_HPP
#define SPIDER_SERVER_SPIDEREVENTLISTENER_HPP

#include <zmq.h>
#include <thread>
#include "../Interfaces/ISpiderEventListener.hpp"
#include "../Interfaces/ISpiderServer.hpp"

class SpiderEventListener : public ISpiderEventListener {
private :
    std::function<void(std::string, std::string)> _onMessage;
    std::unique_ptr<std::thread> _eventListenerThread;
    std::shared_ptr<zmq::socket_t> _socketSUB = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_SUB));

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    static void RunReceive(zmq::socket_t *socketSub, std::function<void(std::string, std::string)> *onMessage) {
        while (true) {
            zmq::message_t msg;
            socketSub->recv(&msg);
            std::string rpl = std::string(static_cast<char*>(msg.data()), msg.size());
            if (rpl.size() > 16)
            {
                auto token = rpl.substr(0, 16);
                auto payload = rpl.substr(17, rpl.size() - 17);
                (*onMessage)(token, payload); //todo deserialize payload
            }
        }
    }
#pragma clang diagnostic pop

public:
    virtual void Start(const std::string typeName, std::function<void(std::string, std::string)> onMessage) override final{
        _socketSUB->setsockopt(ZMQ_SUBSCRIBE, typeName.c_str(), typeName.size());
        _onMessage = onMessage;
        _eventListenerThread = std::unique_ptr<std::thread>(new std::thread(RunReceive, _socketSUB.get(), &_onMessage));
    }

    SpiderEventListener() {
        _socketSUB->connect("inproc://EventEmitter");
    }
};

#endif //SPIDER_SERVER_SPIDEREVENTLISTENER_HPP
