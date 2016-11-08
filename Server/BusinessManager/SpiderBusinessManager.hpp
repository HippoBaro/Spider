//
// Created by hippolyteb on 11/7/16.
//

#ifndef SPIDER_SERVER_BUSINESSMANAGER_HPP
#define SPIDER_SERVER_BUSINESSMANAGER_HPP

#include <vector>
#include "../Interfaces/ISpiderBusinessManager.hpp"
#include "../Interfaces/ISpiderBusinessModule.hpp"

class SpiderBusinessManager : public ISpiderBusinessManager {
public:
    virtual void ReadConfiguration() override {

    }

private:
    std::vector<ISpiderBusinessModule> _modules;
};

#endif //SPIDER_SERVER_BUSINESSMANAGER_HPP
