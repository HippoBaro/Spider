//
// Created by hippolyteb on 11/7/16.
//

#ifndef SPIDER_SERVER_ISPIDERSERVER_HPP
#define SPIDER_SERVER_ISPIDERSERVER_HPP

#include <memory>
#include "ISpiderNetworkManager.hpp"

class ISpiderServer {
public:
    static zmq::context_t *Context;

public:
    virtual void Run() = 0;
};
zmq::context_t *ISpiderServer::Context = new zmq::context_t();

#endif //SPIDER_SERVER_ISPIDERSERVER_HPP
