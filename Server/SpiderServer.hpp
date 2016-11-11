//
// Created by hippolyteb on 11/7/16.
//

#ifndef SPIDER_SERVER_SPIDERSERVER_HPP
#define SPIDER_SERVER_SPIDERSERVER_HPP

#include "Interfaces/ISpiderServer.hpp"
#include "SpiderNetworkManager/SpiderNetworkManager.hpp"
#include "BusinessManager/SpiderBusinessManager.hpp"
#include "Interfaces/ISpiderEventManager.hpp"
#include "SpiderEventManager/SpiderEventManager.hpp"

class SpiderServer : public ISpiderServer {
private:
    std::unique_ptr<ISpiderNetworkManager> NetworkManager = std::unique_ptr<ISpiderNetworkManager>(new SpiderNetworkManager());
    std::unique_ptr<ISpiderEventManager> EventManager = std::unique_ptr<ISpiderEventManager>(new SpiderEventManager());
    std::unique_ptr<ISpiderBusinessManager> BusinessManager = std::unique_ptr<ISpiderBusinessManager>(new SpiderBusinessManager());

public:
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    void Run() override final {
        EventManager->Run();
        NetworkManager->Run();
    }
#pragma clang diagnostic pop
};

#endif //SPIDER_SERVER_SPIDERSERVER_HPP
