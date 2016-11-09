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

class OutputSTDOUTModule : public ISpiderBusinessModule {
    std::unique_ptr<ISpiderEventListener> _eventListener = std::unique_ptr<ISpiderEventListener>(new SpiderEventListener());

private:
    static void Output(std::string id, std::string payload){
        std::cout << "Message from ID : " << id << " Payload is : " << payload << std::endl;
    }

public:
    OutputSTDOUTModule() {
        _eventListener->Start("OutputSTDIN", Output);
    }
};

#endif //SPIDER_SERVER_OUTPUTSTDINMODULE_HPP
