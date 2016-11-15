//
// Created by hippolyteb on 11/14/16.
//

#ifndef CONNECTIONMANAGER_HPP
#define CONNECTIONMANAGER_HPP

#include <memory>
#include "zmq.hpp"
#include "protobufMessages/SpiderEnvelop.pb.h"

class ConnectionManager {
private:
    std::unique_ptr<zmq::socket_t> _socket;
    std::unique_ptr<zmq::context_t> _context;

public:
    ConnectionManager(const std::string &endpoint) {
        _context = std::unique_ptr<zmq::context_t>(new zmq::context_t());
        _socket = std::unique_ptr<zmq::socket_t>(new zmq::socket_t(*_context, ZMQ_PAIR));

        _socket->connect(endpoint);
    }

    SpiderEnveloppe SendRequest(SpiderEnveloppe &spiderEnveloppe) {
        if (spiderEnveloppe.clientid().size() < 16)
            return SpiderEnveloppe();
        std::string payload = spiderEnveloppe.SerializeAsString();

        zmq::message_t request(payload.c_str(), payload.size());

        _socket->send(request);

        zmq::message_t response;

        _socket->recv(&response);
        std::string msg = std::string(static_cast<char*>(response.data()), response.size());

        SpiderEnveloppe ret;
        ret.ParseFromString(msg);
        return ret;
    }
};

#endif //CONNECTIONMANAGER_HPP
