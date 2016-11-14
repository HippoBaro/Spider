//
// Created by hippolyteb on 11/7/16.
//

#ifndef SPIDER_SERVER_ISPIDEREVENTEMITTER_HPP
#define SPIDER_SERVER_ISPIDEREVENTEMITTER_HPP

#include <google/protobuf/any.pb.h>
#include "../../ProtoEnvelopes/Proto/SpiderEnveloppe.pb.h"

class ISpiderEventEmitter {
public:
    virtual void RouteToModules(SpiderEnveloppe const &payload) = 0;
    virtual void Emit(std::string destinator, const SpiderEnveloppe &payload) = 0;
};

#endif //SPIDER_SERVER_ISPIDEREVENTEMITTER_HPP
