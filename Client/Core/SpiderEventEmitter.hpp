#ifndef SPIDER_SERVER_SPIDEREVENTEMITTER_HPP
#define SPIDER_SERVER_SPIDEREVENTEMITTER_HPP

#include <thread>
#include "zmq_addon.hpp"
#include "ISpiderEventEmitter.hpp"
#include <memory>
#include "ISpiderDeamon.hpp"

class SpiderEventEmitter : public ISpiderEventEmitter {
	std::shared_ptr<zmq::socket_t> _socketPUB = std::make_shared<zmq::socket_t>(*ISpiderDeamon::Context, ZMQ_PUB);

public:
	SpiderEventEmitter() {
		_socketPUB->connect("inproc://EventListener");
	}

	void Emit(std::string destinator, SpiderEnveloppe &payload) override final {
		zmq::multipart_t msg;
		msg.addstr(destinator);
		std::string temp = payload.SerializeAsString();
		msg.addstr(temp);
		msg.send(*_socketPUB);
	}

	void RouteToModules(SpiderEnveloppe &payload) override final {
		Emit(payload.payloadtype(), payload);
	}
};

#endif //SPIDER_SERVER_SPIDEREVENTEMITTER_HPP
