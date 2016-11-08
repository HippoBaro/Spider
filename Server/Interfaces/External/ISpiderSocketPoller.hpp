//
// Created by hippolyteb on 11/8/16.
//

#ifndef SPIDER_SERVER_ISPIDERSOCKETPOLLER_HPP
#define SPIDER_SERVER_ISPIDERSOCKETPOLLER_HPP

#include <vector>
#include "ISpiderSocket.hpp"

class ISpiderSocketPoller {
public:
    virtual std::tuple<std::string, std::string> ReceivePoller(ISpiderSocket *master, std::vector<ISpiderSocket *>) = 0;
};

#endif //SPIDER_SERVER_ISPIDERSOCKETPOLLER_HPP
