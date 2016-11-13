//
// Created by hippolyteb on 11/12/16.
//

#ifndef SPIDER_SERVER_AESCRYPTOGHRAPHICAGENT_HPP
#define SPIDER_SERVER_AESCRYPTOGHRAPHICAGENT_HPP

#include "../Interfaces/ISpiderCryptographicAgent.hpp"

class AESCryptographicAgent : public ISpiderCryptographicAgent {
private:

public:
    AESCryptographicAgent() {

    }

public:
    std::string EncryptPayload(std::string &playtextPayload) override final {

    }

    std::string DecryptPayload(std::string &encryptedPayload) override final {

    }

    virtual std::string GetEncryptionKeyForClient(const std::string &clientId) override {
        return "test";
    }

private:
};

#endif //SPIDER_SERVER_AESCRYPTOGHRAPHICAGENT_HPP
