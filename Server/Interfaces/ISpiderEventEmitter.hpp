//
// Created by hippolyteb on 11/7/16.
//

#ifndef SPIDER_SERVER_ISPIDEREVENTEMITTER_HPP
#define SPIDER_SERVER_ISPIDEREVENTEMITTER_HPP

class ISpiderEventEmitter {
public:
    virtual void Emit(std::string id, std::string message) = 0;
};

#endif //SPIDER_SERVER_ISPIDEREVENTEMITTER_HPP
