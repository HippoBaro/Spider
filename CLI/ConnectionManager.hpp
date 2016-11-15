//
// Created by hippolyteb on 11/14/16.
//

#ifndef CONNECTIONMANAGER_HPP
#define CONNECTIONMANAGER_HPP

#include <memory>
#include "zmq.hpp"

class ConnectionManager {
private:
    std::unique_ptr<zmq::socket_t> _socket;
    std::unique_ptr<zmq::context_t> _context;

public:
    ConnectionManager() {
        _context = std::unique_ptr<zmq::context_t>(new zmq::context_t());
        _socket = std::unique_ptr<zmq::socket_t>(new zmq::socket_t(*_context, ZMQ_REQ));
        
    }
};

#endif //CONNECTIONMANAGER_HPP
