#ifndef SPIDER_SERVER_SPIDEREVENTMANAGER_HPP
#define SPIDER_SERVER_SPIDEREVENTMANAGER_HPP

#include <thread>
#include "ISpiderEventManager.hpp"
#include <memory>
#include "ZeroMQSocket.hpp"


class SpiderEventManager : public ISpiderEventManager {
private:
	std::unique_ptr<std::thread> _eventManagerThread;

	std::shared_ptr<zmq::socket_t> _socketPUB;
	std::shared_ptr<zmq::socket_t> _socketSUB;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
	static void RunReceive(zmq::socket_t *socketSub, zmq::socket_t *socketPub) {
		while (true) {
			zmq::multipart_t rep;
			zmq::message_t msg;
			socketSub->recv(&msg);
			std::string ret = std::string(static_cast<char*>(msg.data()), msg.size());
			rep.addstr(ret);
			zmq::message_t msg2;
			socketSub->recv(&msg2);
			ret = std::string(static_cast<char*>(msg2.data()), msg2.size());
			rep.addstr(ret);
			rep.send(*socketPub, 0);
		}
	}
#pragma clang diagnostic pop

public:
	SpiderEventManager() {
		_socketPUB = std::make_shared<zmq::socket_t>(*ISpiderDeamon::Context, ZMQ_PUB);
		_socketSUB = std::make_shared<zmq::socket_t>(*ISpiderDeamon::Context, ZMQ_SUB);
	}

public:
	void Run() override final {
		_socketPUB->bind("inproc://EventEmitter");
		_socketSUB->bind("inproc://EventListener");
		_socketSUB->setsockopt(ZMQ_SUBSCRIBE, "", 0);

		_eventManagerThread = std::make_unique<std::thread>(RunReceive, _socketSUB.get(), _socketPUB.get());
	}
};

#endif //SPIDER_SERVER_SPIDEREVENTMANAGER_HPP