//
// Created by hippolyteb on 11/12/16.
//

#ifndef SPIDER_SERVER_ISPIDERCRYPTOGRAPHICAGENT_HPP
#define SPIDER_SERVER_ISPIDERCRYPTOGRAPHICAGENT_HPP

#include <string>
#include "../Enums/Cryptography.hpp"

class ISpiderCryptographicAgent {
public:
    virtual std::string EncryptPayload(std::string &playtextPayload) = 0;
    virtual std::string DecryptPayload(std::string &encryptedPayload) = 0;
    virtual std::string GetEncryptionKeyForClient(const std::string &clientId) = 0;
};

#endif //SPIDER_SERVER_ISPIDERCRYPTOGRAPHICAGENT_HPP
