//
// Created by hippolyteb on 11/12/16.
//

#ifndef SPIDER_SERVER_RSACRYPTOGHRAPHICAGENT_HPP
#define SPIDER_SERVER_RSACRYPTOGHRAPHICAGENT_HPP

#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>
#include <openssl/evp.h>
#include <openssl/engine.h>
#include <stdexcept>
#include <bits/unique_ptr.h>
#include <openssl/err.h>
#include <bitset>
#include "../Interfaces/ISpiderCryptographicAgent.hpp"

template<PrimaryKeyType primaryKey>
class RSACryptographicAgent : public ISpiderCryptographicAgent {
private:
    const std::string _key;
    std::unique_ptr<RSA> _rsa = nullptr;

public:
    RSACryptographicAgent(const std::string &key) : _key(key) {
        if (primaryKey != Private && primaryKey != Public)
            throw std::runtime_error("Impossible de créer l'agent de cryptographie");
        _rsa = std::unique_ptr<RSA>(createRSA());
    }

public:
    std::string EncryptPayload(std::string &playtextPayload) override final {
        std::string out = encrypt((unsigned char *)playtextPayload.c_str());
        if (out == "")
        {
            char *err = (char *)malloc(1000);
            ERR_load_crypto_strings();
            ERR_error_string(ERR_get_error(), err);
            throw std::runtime_error("Impossible de chiffrer le payload : " + std::string(err));
        }
        return out;
    }

    std::string DecryptPayload(std::string &encryptedPayload) override final {
        std::string out = decrypt((unsigned char *)encryptedPayload.c_str());
        if (out == "")
        {
            char *err = (char *)malloc(1000);
            ERR_load_crypto_strings();
            ERR_error_string(ERR_get_error(), err);
            throw std::runtime_error("Impossible de déchiffrer le payload : " + std::string(err));
        }
        return out;
    }

    virtual std::string GetEncryptionKeyForClient(const std::string &clientId) override {
        return "";
    }

private:
    RSA *createRSA()
    {
        RSA *rsa = nullptr;
        BIO *keybio;
        keybio = BIO_new_mem_buf(_key.c_str(), -1);
        if (keybio == nullptr)
            throw std::runtime_error("Impossible de créer l'agent de cryptographie");
        if(primaryKey)
            rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa, nullptr, nullptr);
        else
            rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, nullptr, nullptr);
        return rsa;
    }

    std::string encrypt(unsigned char *data)
    {
        RSA *rsa = this->createRSA();
        int rsaLen = RSA_size(rsa) ;
        unsigned char* encrypted = (unsigned char*)malloc((size_t) rsaLen);
        int ret = 0;
        if (primaryKey == Public)
            ret = RSA_public_encrypt((int) strlen((char *)data), data, encrypted, rsa, RSA_PKCS1_OAEP_PADDING);
        else
            ret = RSA_private_encrypt((int) strlen((char *)data), data, encrypted, rsa, RSA_PKCS1_OAEP_PADDING);
        if (ret == -1)
            return "";
        std::cout << "RET = " << ret << std::endl;
        return std::string((char *)encrypted);
    }

    std::string decrypt(unsigned char *enc_data)
    {
        RSA *rsa = this->createRSA();
        int rsaLen = RSA_size(rsa); // That's how many bytes the decrypted data would be
        int resultLen;

        unsigned char *decryptedBin = (unsigned char*)malloc((size_t) rsaLen) ;
        if (primaryKey == Public)
            resultLen = RSA_public_decrypt(rsaLen, enc_data, decryptedBin, rsa, RSA_PKCS1_OAEP_PADDING);
        else
            resultLen = RSA_private_decrypt(rsaLen, enc_data, decryptedBin, rsa, RSA_PKCS1_OAEP_PADDING);
        if( resultLen == -1 )
            return "";

        return std::string((char *)decryptedBin);
    }


};

#endif //SPIDER_SERVER_RSACRYPTOGHRAPHICAGENT_HPP
