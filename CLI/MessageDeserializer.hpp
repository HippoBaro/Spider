//
// Created by hippolyteb on 11/15/16.
//

#ifndef MESSAGEDESERIALIZER_HPP
#define MESSAGEDESERIALIZER_HPP

#include <iostream>
#include "protobufMessages/SpiderEnvelop.pb.h"
#include "protobufMessages/GetKeylogCommandResponse.pb.h"
#include "protobufMessages/ListUUIDSCommandResponse.pb.h"

class MessageDeserializer {
public:
    static void PrintResponse(SpiderEnveloppe &enveloppe) {
        std::string type = enveloppe.payloadtype();

        if (type == "GetKeylogCommandResponse") {
            GetKeylogCommandResponse response;
            enveloppe.payload().UnpackTo(&response);
            PrintKeylog(enveloppe.clientid(), response);
        }
        else if (type == "ListUUIDSCommandResponse"){
            ListUUIDSCommandResponse response;
            enveloppe.payload().UnpackTo(&response);
            PrintUUIDS(response);
        }
    }

private:
    static void PrintKeylog(const std::string &clientId, GetKeylogCommandResponse &response) {
        std::cout << "Keylog for client with ID [" << clientId << "] : " << std::endl;
        for (int i = 0; i < response.keylog_size(); ++i) {
            SpiderKeyLoggingPayload payload;
            payload = response.keylog(i);

            if (payload.context().processname() != "" || payload.context().windowsname() != "")
                std::cout << "> Context changed : " << "[ Process:\"" <<payload.context().processname() << "\"" << " Window:\"" << payload.context().windowsname() << "\"]" << std::endl;
            if (payload.plaintextkeylog() != "")
                std::cout << "==> " << payload.plaintextkeylog() << std::endl;
        }
        std::cout << "--- TOTAL of " << response.keylog_size() << " entries for client with ID [\"" << clientId << "\"] ---" << std::endl;
    }

    static void PrintUUIDS(ListUUIDSCommandResponse &response) {
        std::cout << "UUIDS : " << std::endl;
        for (int i = 0; i < response.uuid_size(); ++i) {
            std::cout << "> " << response.uuid(i) << std::endl;
        }
        std::cout << "--- TOTAL of " << response.uuid_size() << " entries for UUIDS ---" << std::endl;
    }
};

#endif //MESSAGEDESERIALIZER_HPP
