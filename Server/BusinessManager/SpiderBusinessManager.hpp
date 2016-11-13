//
// Created by hippolyteb on 11/7/16.
//

#ifndef SPIDER_SERVER_BUSINESSMANAGER_HPP
#define SPIDER_SERVER_BUSINESSMANAGER_HPP

#include <vector>
#include "../Interfaces/ISpiderBusinessManager.hpp"
#include "../Interfaces/ISpiderBusinessModule.hpp"
#include "../BusinessModules/OutputSTDOUTModule.hpp"
#include "../BusinessModules/AuthenticationModule.hpp"

class SpiderBusinessManager : public ISpiderBusinessManager {
public:
    virtual void ReadConfiguration() override {
        _modules.push_back(std::unique_ptr<ISpiderBusinessModule>(new OutputSTDOUTModule()));
        _modules.push_back(std::unique_ptr<ISpiderBusinessModule>(new AuthenticationModule()));
    }

    SpiderBusinessManager() {
        ReadConfiguration();
    }

private:
    std::vector<std::unique_ptr<ISpiderBusinessModule>> _modules;
};

#endif //SPIDER_SERVER_BUSINESSMANAGER_HPP
