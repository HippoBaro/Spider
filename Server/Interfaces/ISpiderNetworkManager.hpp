//
// Created by hippolyteb on 11/7/16.
//

#ifndef SPIDER_SERVER_ISPIDERNETWORKMANAGER_HPP
#define SPIDER_SERVER_ISPIDERNETWORKMANAGER_HPP

#include "../Includes/ZeroMQ/zmq.hpp"

class ISpiderNetworkManager {
public:
    virtual void Run() = 0;
    virtual void SendMessage(std::string id, std::string data) = 0;
};

#endif //SPIDER_SERVER_ISPIDERNETWORKMANAGER_HPP
