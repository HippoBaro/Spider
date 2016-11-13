//
// Created by hippolyteb on 11/8/16.
//

#ifndef SPIDER_SERVER_ZEROMQSECURESOCKET_HPP
#define SPIDER_SERVER_ZEROMQSECURESOCKET_HPP

#include "ZeroMQSocket.hpp"
#include "../../Enums/SecureSocketType.hpp"

template <SecureSocketType type>
class ZeroMQSecureSocket : public ZeroMQSocket { };

template <>
class ZeroMQSecureSocket<Server> : public ZeroMQSocket {
public:
    ZeroMQSecureSocket(const std::string &serverSecretKey) : ZeroMQSocket() {
        _socket->setsockopt(ZMQ_CURVE_SERVER, 1);
        _socket->setsockopt(ZMQ_CURVE_SECRETKEY, strdup(serverSecretKey.c_str()), serverSecretKey.size());
    }
};

template <>
class ZeroMQSecureSocket<Client> : public ZeroMQSocket {
public:
    ZeroMQSecureSocket(const std::string &serverKey, const std::string &publicKey, const std::string &clientSecretKey) : ZeroMQSocket() {
        _socket->setsockopt(ZMQ_CURVE_SERVERKEY, strdup(serverKey.c_str()), serverKey.size());
        _socket->setsockopt(ZMQ_CURVE_PUBLICKEY, strdup(publicKey.c_str()), publicKey.size());
        _socket->setsockopt(ZMQ_CURVE_SECRETKEY, strdup(clientSecretKey.c_str()), clientSecretKey.size());
    }
};
#endif //SPIDER_SERVER_ZEROMQSOCKET_HPP
