//
// Created by hippolyteb on 11/13/16.
//

#ifndef SPIDER_SERVER_REDISDRIVER_HPP
#define SPIDER_SERVER_REDISDRIVER_HPP

#include <xredis/xRedisClient.h>
#include "../../Interfaces/Database/ISpiderDatabaseDriver.hpp"

class RedisDriver : public ISpiderDatabaseDriver {
private:
    std::unique_ptr<xRedisClient> _client = nullptr;
    std::unique_ptr<RedisDBIdx> _db = nullptr;
public:

    virtual void Connect(const std::string &endpoint, const uint16_t &port, const std::string &user,
                         const std::string &password) override {
        _client = std::unique_ptr<xRedisClient>(new xRedisClient());
        _client->Init(1);

        RedisNode RedisList1[1] = {
                {0, endpoint.c_str(), port, password.c_str(), 2, 5, 0},
        };

        if (!_client->ConnectRedisCache(RedisList1, 1, 0))
            throw std::runtime_error("Impossible de se connecter à la base de donnée.");

        _db = std::unique_ptr<RedisDBIdx>(new RedisDBIdx(_client.get()));
    }

    virtual std::vector<std::string> GetSecondaryKeyElements(const std::string &key, const int64_t &start, const int64_t &len) override {
        ArrayReply reply;
        if (!_client->lrange(*_db, key, start, len, reply))
            throw std::runtime_error(_db->GetErrInfo());
        std::vector<std::string> ret;
        for(auto const& value: reply)
            ret.push_back(value.str);
        return ret;
    }

    virtual void PushElement(const std::string &key, const std::string &element) override {
        int64_t count = 0;
        if(!_client->lpushx(*_db, key, element, count))
            throw std::runtime_error(_db->GetErrInfo());
    }

    virtual void Close() override {
        _client->quit();
    }
};

#endif //SPIDER_SERVER_REDISDRIVER_HPP
