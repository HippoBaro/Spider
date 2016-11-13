//
// Created by hippolyteb on 11/13/16.
//

#ifndef SPIDER_SERVER_AUTHENTICATIONMODULE_HPP
#define SPIDER_SERVER_AUTHENTICATIONMODULE_HPP

#include "../SpiderEventManager/SpiderEventListener.hpp"
#include "../SpiderEventManager/SpiderEventEmitter.hpp"
#include "../Interfaces/ISpiderBusinessModule.hpp"
#include "../ProtoEnvelopes/Proto/SpiderAuthenticationPayload.pb.h"
#include "../Interfaces/ISpiderCryptographicAgent.hpp"
#include "../SpiderNetworkManager/AESCryptographicAgent.hpp"
#include "../ProtoEnvelopes/Proto/SpiderAuthorizedPayload.pb.h"
#include "../Serialization/SpiderSerializer.hpp"
#include "../SpiderNetworkManager/RSACryptographicAgent.hpp"

static const char b64_table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static const char reverse_table[128] = {
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 62, 64, 64, 64, 63,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 64, 64, 64, 64, 64, 64,
        64,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 64, 64, 64, 64, 64,
        64, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 64, 64, 64, 64, 64
};

::std::string base64_encode(const ::std::string &bindata)
{
    using ::std::string;
    using ::std::numeric_limits;

    if (bindata.size() > (numeric_limits<string::size_type>::max() / 4u) * 3u) {
        throw ::std::length_error("Converting too large a string to base64.");
    }

    const ::std::size_t binlen = bindata.size();
    // Use = signs so the end is properly padded.
    string retval((((binlen + 2) / 3) * 4), '=');
    ::std::size_t outpos = 0;
    int bits_collected = 0;
    unsigned int accumulator = 0;
    const string::const_iterator binend = bindata.end();

    for (string::const_iterator i = bindata.begin(); i != binend; ++i) {
        accumulator = (accumulator << 8) | (*i & 0xffu);
        bits_collected += 8;
        while (bits_collected >= 6) {
            bits_collected -= 6;
            retval[outpos++] = b64_table[(accumulator >> bits_collected) & 0x3fu];
        }
    }
    if (bits_collected > 0) { // Any trailing bits that are missing.
        assert(bits_collected < 6);
        accumulator <<= 6 - bits_collected;
        retval[outpos++] = b64_table[accumulator & 0x3fu];
    }
    assert(outpos >= (retval.size() - 2));
    assert(outpos <= retval.size());
    return retval;
}

class AuthenticationModule : public ISpiderBusinessModule {
private:
    std::unique_ptr<ISpiderEventListener<SpiderAuthenticationPayload>> _eventListener = std::unique_ptr<ISpiderEventListener<SpiderAuthenticationPayload>>(new SpiderEventListener<SpiderAuthenticationPayload>());
    std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(new SpiderEventEmitter());
    std::unique_ptr<ISpiderCryptographicAgent> _cryptoAESAgent = std::unique_ptr<ISpiderCryptographicAgent>(new AESCryptographicAgent());
    std::unique_ptr<ISpiderCryptographicAgent> _cryptoRSAAgent;

public:
    AuthenticationModule() {
        std::string publicKey = "-----BEGIN PUBLIC KEY-----\n"\
"MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAy8Dbv8prpJ/0kKhlGeJY\n"\
"ozo2t60EG8L0561g13R29LvMR5hyvGZlGJpmn65+A4xHXInJYiPuKzrKUnApeLZ+\n"\
"vw1HocOAZtWK0z3r26uA8kQYOKX9Qt/DbCdvsF9wF8gRK0ptx9M6R13NvBxvVQAp\n"\
"fc9jB9nTzphOgM4JiEYvlV8FLhg9yZovMYd6Wwf3aoXK891VQxTr/kQYoq1Yp+68\n"\
"i6T4nNq7NWC+UNVjQHxNQMQMzU6lWCX8zyg3yH88OAQkUXIXKfQ+NkvYQ1cxaMoV\n"\
"PpY72+eVthKzpMeyHkBn7ciumk5qgLTEJAfWZpe4f4eFZj/Rc8Y8Jj2IS5kVPjUy\n"\
"wQIDAQAB\n"\
"-----END PUBLIC KEY-----\n";

        _cryptoRSAAgent = std::unique_ptr<ISpiderCryptographicAgent>(new RSACryptographicAgent<Public>(publicKey));


        _eventListener->Register("SpiderAuthenticationPayload", [&](std::string clientId, SpiderAuthenticationPayload &payload){
            SpiderAuthorizedPayload response;
            auto key = _cryptoAESAgent->GetEncryptionKeyForClient(clientId);
            auto keyrsa = _cryptoRSAAgent->EncryptPayload(key);
            //keyrsa = base64_encode(keyrsa);
            std::cout << "KEYENC : " << keyrsa << std::endl;
            response.set_key(keyrsa.c_str(), 256);
            auto pay = SpiderSerializer::CreateResponseFromPayload(clientId, response);
            _eventEmitter->Emit("NoEncryption:SpiderNetworkManager", pay);
        });
    }

private:
};

#endif //SPIDER_SERVER_AUTHENTICATIONMODULE_HPP
