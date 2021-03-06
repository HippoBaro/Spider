
#ifndef SPIDER_SERVER_ZEROMQSOCKET_HPP
#define SPIDER_SERVER_ZEROMQSOCKET_HPP

#include "ISpiderSocket.hpp"
#include "zmq.hpp"
#include "ISpiderDeamon.hpp"
#include "zmq_addon.hpp"

class ZeroMQSocket : public ISpiderSocket {
public:
	std::unique_ptr<zmq::socket_t> _socket;

	ZeroMQSocket() : ISpiderSocket() {
		_socket = std::unique_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderDeamon::Context, ZMQ_DEALER));
	}

	virtual std::string &GetSocketID() override {
		return ISpiderSocket::GetSocketID();
	}

	virtual void SetSocketID(const std::string &id) override {
		ISpiderSocket::SetSocketID(id);
	}

	const std::string &GetSocketImplementationIdentity() override {
		return "ZeroMQ";
	}

	virtual void Send(const std::string &clientId, const std::string &payload) override final {
		zmq::multipart_t rep;
		_socket->setsockopt(ZMQ_IDENTITY, clientId.c_str(), 16);
		rep.addstr(payload);
		rep.send(*_socket, 0);
	}

	virtual std::string &Receive() override final {
		zmq::message_t msg;
		_socket->recv(&msg);
		std::string ret = std::string(static_cast<char*>(msg.data()), msg.size());
		return ret;
	}

	virtual void Connect(const std::string &address) override final {
		_socket->connect(address);
	}

	virtual void Bind(const std::string &address) override final {
		_socket->bind(address);
	}

	virtual bool ShouldAccept() override final {
		return false;
	}

	virtual std::unique_ptr<ISpiderSocket> Accept() override final {
		return nullptr;
	}

	virtual void *GetNativeSocket() override final {
		return _socket.get();
	}

	virtual void Disconnect() override {
		_socket->close();
	}
};

#endif