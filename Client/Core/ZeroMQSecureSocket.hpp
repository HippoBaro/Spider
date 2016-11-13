//
// Created by hippolyteb on 11/8/16.
//

#ifndef SPIDER_SERVER_ZEROMQSECURESOCKET_HPP
#define SPIDER_SERVER_ZEROMQSECURESOCKET_HPP

#include "ZeroMQSocket.hpp"

enum SecureSocketType {
	Client = 0,
	Server = 1
};


template <SecureSocketType type>
class ZeroMQSecureSocket : public ZeroMQSocket { };

template <>
class ZeroMQSecureSocket<Server> : public ZeroMQSocket {
public:
	ZeroMQSecureSocket(const std::string &serverSecretKey) : ZeroMQSocket() {
		_socket->setsockopt(ZMQ_CURVE_SERVER, 1);
		_socket->setsockopt(ZMQ_CURVE_SECRETKEY, _strdup(serverSecretKey.c_str()), serverSecretKey.size());
	}
};

template <>
class ZeroMQSecureSocket<Client> : public ZeroMQSocket {
public:
	ZeroMQSecureSocket(const std::string &serverKey, const std::string &publicKey, const std::string &clientSecretKey) : ZeroMQSocket() {
		_socket->setsockopt(ZMQ_CURVE_SERVERKEY, _strdup(serverKey.c_str()), serverKey.size());
		_socket->setsockopt(ZMQ_CURVE_PUBLICKEY, _strdup(publicKey.c_str()), publicKey.size());
		_socket->setsockopt(ZMQ_CURVE_SECRETKEY, _strdup(clientSecretKey.c_str()), clientSecretKey.size());
	}
};

#endif //SPIDER_SERVER_ZEROMQSOCKET_HPP