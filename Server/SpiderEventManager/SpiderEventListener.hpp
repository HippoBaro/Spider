//
// Created by hippolyteb on 11/8/16.
//

#ifndef SPIDER_SERVER_SPIDEREVENTLISTENER_HPP
#define SPIDER_SERVER_SPIDEREVENTLISTENER_HPP

#include <thread>
#include "../Interfaces/Event/ISpiderEventListener.hpp"
#include "../Interfaces/ISpiderServer.hpp"
#include "../ProtoEnvelopes/Proto/SpiderEnveloppe.pb.h"

template<class TPayload>
class SpiderEventListener : public ISpiderEventListener<TPayload> {
private :
    std::function<void(std::string clientId, TPayload &)> _onMessage;
    std::function<void(std::string clientId, SpiderEnveloppe &)> _onMessageNoUnpack;
    std::unique_ptr<std::thread> _eventListenerThread;
    std::shared_ptr<zmq::socket_t> _socketSUB = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderServer::Context, ZMQ_SUB));

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    static void RunReceive(zmq::socket_t *socketSub, std::function<void(std::string clientId, TPayload &)> *onMessage) {
        while (true) {
            zmq::message_t msg;
            socketSub->recv(&msg);
            socketSub->recv(&msg);
            std::string rpl = std::string(static_cast<char*>(msg.data()), msg.size());
            SpiderEnveloppe enveloppe;

            if (!enveloppe.ParseFromString(rpl))
                continue;
            TPayload payload;
            enveloppe.payload().UnpackTo(&payload);
            (*onMessage)(enveloppe.clientid(), payload);
        }
    }

    static void RunReceiveNoUnpack(zmq::socket_t *socketSub, std::function<void(std::string clientId, SpiderEnveloppe &)> *onMessage) {
        while (true) {
            zmq::message_t msg;
            socketSub->recv(&msg);
            socketSub->recv(&msg);
            std::string rpl = std::string(static_cast<char*>(msg.data()), msg.size());
            SpiderEnveloppe enveloppe;

            if (!enveloppe.ParseFromString(rpl))
                continue;
            (*onMessage)(enveloppe.clientid(), enveloppe);
            continue;
        }
    }
#pragma clang diagnostic pop

public:
    virtual void Register(std::string payloadType, std::function<void(std::string clientId, TPayload &)> onMessage) override final{
        _socketSUB->setsockopt(ZMQ_SUBSCRIBE, payloadType.c_str(), payloadType.size());
        _onMessage = onMessage;
        _eventListenerThread = std::unique_ptr<std::thread>(new std::thread(RunReceive, _socketSUB.get(), &_onMessage));
    }

    virtual void RegisterNoUnpack(std::string payloadType, std::function<void(std::string clientId, SpiderEnveloppe &)> onMessage) override final{
        _socketSUB->setsockopt(ZMQ_SUBSCRIBE, payloadType.c_str(), payloadType.size());
        _onMessageNoUnpack = onMessage;
        _eventListenerThread = std::unique_ptr<std::thread>(new std::thread(RunReceiveNoUnpack, _socketSUB.get(), &_onMessageNoUnpack));
    }

    SpiderEventListener() {
        _socketSUB->connect("inproc://EventEmitter");
    }
};

#endif //SPIDER_SERVER_SPIDEREVENTLISTENER_HPP
