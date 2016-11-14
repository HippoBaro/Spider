//
// Created by hippolyteb on 11/13/16.
//

#ifndef SPIDER_SERVER_ISPIDERDATABASEDRIVER_HPP
#define SPIDER_SERVER_ISPIDERDATABASEDRIVER_HPP

class ISpiderKeyValueDatabaseDriver {
public:
    virtual void Connect(const std::string &endpoint, const uint16_t &port, const std::string &user, const std::string &password) = 0;
    virtual std::vector<std::string> GetSecondaryKeyElements(const std::string &key, const int64_t &start, const int64_t &len) = 0;
    virtual void PushElement(const std::string &key, const std::string &element) = 0;
    virtual void Close() = 0;
};

#endif //SPIDER_SERVER_ISPIDERDATABASEDRIVER_HPP
