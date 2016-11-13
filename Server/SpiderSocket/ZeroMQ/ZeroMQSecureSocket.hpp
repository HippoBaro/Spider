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
    ZeroMQSecureSocket(std::string serverSecretKey) : ZeroMQSocket() {
        _socket->setsockopt(ZMQ_CURVE_SERVER, 1);
        _socket->setsockopt(ZMQ_CURVE_SECRETKEY, serverSecretKey);
    }
};

template <>
class ZeroMQSecureSocket<Client> : public ZeroMQSocket {
public:
    ZeroMQSecureSocket(std::string serverKey, std::string publicKey, std::string clientSecretKey) : ZeroMQSocket() {
        _socket->setsockopt(ZMQ_CURVE_SERVERKEY, serverKey);
        _socket->setsockopt(ZMQ_CURVE_PUBLICKEY, publicKey);
        _socket->setsockopt(ZMQ_CURVE_SECRETKEY, clientSecretKey);
    }
};

#endif //SPIDER_SERVER_ZEROMQSOCKET_HPP
