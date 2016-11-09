//
// Created by hippolyteb on 11/7/16.
//

#ifndef SPIDER_SERVER_ISPIDERNETWORKMANAGER_HPP
#define SPIDER_SERVER_ISPIDERNETWORKMANAGER_HPP

#include "../ProtoEnvelopes/Proto/SpiderEnveloppe.pb.h"

class ISpiderNetworkManager {
public:
    virtual void Run() = 0;
    virtual void SendMessage(SpiderEnveloppe &enveloppe) = 0;
};

#endif //SPIDER_SERVER_ISPIDERNETWORKMANAGER_HPP
