//
// Created by hippolyteb on 11/7/16.
//

#ifndef SPIDER_SERVER_ISPIDEREVENTLISTENER_HPP
#define SPIDER_SERVER_ISPIDEREVENTLISTENER_HPP

#include <string>
#include <functional>

class ISpiderEventListener {
public:
    virtual void Start(const std::string typeName, std::function<void(std::string, std::string)> onMessage) = 0;
};

#endif //SPIDER_SERVER_ISPIDEREVENTLISTENER_HPP