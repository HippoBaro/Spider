//
// Created by hippolyteb on 11/9/16.
//

#ifndef SPIDER_SERVER_DESERIALIZER_HPP
#define SPIDER_SERVER_DESERIALIZER_HPP

#include "../ProtoEnvelopes/Proto/SpiderEnveloppe.pb.h"

class SpiderDeserializer {
public:
    static SpiderEnveloppe GetEnvelopeFromMessage(const std::string message) {
        SpiderEnveloppe envelope;
        if (envelope.ParseFromString(message)){
            if (envelope.clientid().size() == 16 && !envelope.payloadtype().empty())
                return envelope;
        }
        throw std::runtime_error("L'enveloppe n'est pas du bon format ou ne respecte pas le protocole.");
    }
};

#endif //SPIDER_SERVER_DESERIALIZER_HPP
