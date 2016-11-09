//
// Created by hippolyteb on 11/8/16.
//

#ifndef SPIDER_SERVER_OUTPUTSTDINMODULE_HPP
#define SPIDER_SERVER_OUTPUTSTDINMODULE_HPP

#include <bits/unique_ptr.h>
#include <iostream>
#include "../Interfaces/ISpiderBusinessModule.hpp"
#include "../Interfaces/ISpiderEventListener.hpp"
#include "../SpiderEventManager/SpiderEventListener.hpp"
#include "../ProtoEnvelopes/Proto/test.pb.h"
#include "../Serialization/SpiderSerializer.hpp"

class OutputSTDOUTModule : public ISpiderBusinessModule {
    std::unique_ptr<ISpiderEventListener<testPayload>> _eventListener = std::unique_ptr<ISpiderEventListener<testPayload>>(new SpiderEventListener<testPayload>());
    std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(new SpiderEventEmitter());
private:

public:
    OutputSTDOUTModule() {
        _eventListener->Register("testPayload", [&](std::string clientId, testPayload &payload) {
            std::cout << "Message from ID : " << clientId << " Payload is : " << payload.content() << std::endl;
            auto enveloppe = SpiderSerializer::CreateResponseFromPayload(clientId, payload);
            std::string enveloppe_data;
            enveloppe.SerializeToString(&enveloppe_data);
            _eventEmitter->Emit("SpiderNetworkManager", enveloppe);
        });
    }
};

#endif //SPIDER_SERVER_OUTPUTSTDINMODULE_HPP
