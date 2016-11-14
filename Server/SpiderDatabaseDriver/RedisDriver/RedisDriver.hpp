//
// Created by hippolyteb on 11/13/16.
//

#ifndef SPIDER_SERVER_REDISDRIVER_HPP
#define SPIDER_SERVER_REDISDRIVER_HPP

#include <redox.hpp>
#include "../../Interfaces/Database/ISpiderKeyValueDatabaseDriver.hpp"

enum KeyType {
    List,
    Sets
};

std::unique_ptr<redox::Redox> RedisClient;

template <KeyType type>
class RedisDriver : public ISpiderKeyValueDatabaseDriver {
public:

    RedisDriver() {
        Connect("127.0.0.1", 6379, "", "");
    }

    virtual void Connect(const std::string &endpoint, const uint16_t &port, const std::string &user,
                         const std::string &password) override {
        if (RedisClient == nullptr) {
            RedisClient = std::unique_ptr<redox::Redox>(new redox::Redox());

            if (!RedisClient->connect(endpoint, (int)port))
                throw std::runtime_error("Impossible de se connecter à la base de donnée.");
        }
    }

    virtual std::vector<std::string> GetSecondaryKeyElements(const std::string &key, const int64_t &start, const int64_t &len) override {
        std::vector<std::string> ret;

        std::stringstream ss;
        std::vector<std::string> tokens;
        ss << "LRANGE " << key << " " << start << " " << len;

        return RedisClient->commandSync<std::vector<std::string>>(RedisClient->strToVec(ss.str())).reply();
    }

    virtual void PushElement(const std::string &key, const std::string &element) override {
        if (type == List) {
            std::stringstream ss;
            std::vector<std::string> tokens;
            ss << "LPUSH " << key << " " << element << " ";

            RedisClient->commandSync<redisReply*>(RedisClient->strToVec(ss.str())).reply();
        }
        else if (type == Sets) {

            std::stringstream ss;
            std::vector<std::string> tokens;
            ss << "LREM " << key << " " << 0 << " " << element;

            RedisClient->commandSync<redisReply*>(RedisClient->strToVec(ss.str())).reply();
            ss.str("");

            ss << "LPUSH " << key << " " << element << " ";

            RedisClient->commandSync<redisReply*>(RedisClient->strToVec(ss.str())).reply();
        }
    }

    virtual void Close() override {
        RedisClient->disconnect();
    }
};

#endif //SPIDER_SERVER_REDISDRIVER_HPP
