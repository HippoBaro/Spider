//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_SPIDERNETWORKMANAGER_HPP
#define SPIDER_CLIENT_SPIDERNETWORKMANAGER_HPP

#include "ISpiderNetworkManager.hpp"
#include <ostream>
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <thread>
#include "zmq.hpp"
#include "ISpiderDeamon.hpp"
#include "ISpiderSocket.hpp"
#include "ISpiderSocketPoller.hpp"
#include "ZeroMQSocketPoller.hpp"
#include "ISpiderEventEmitter.hpp"
#include "SpiderEventEmitter.hpp"
#include "ISpiderEventListener.hpp"
#include "SpiderEventListener.hpp"
#include "SpiderSerializer.hpp"

class SpiderNetworkManager : public ISpiderNetworkManager {
private:
	std::unique_ptr<std::thread> _networkMenagerThread;
	std::unique_ptr<std::thread> _networkMenagerCommanderThread;

	std::shared_ptr<ISpiderSocket> _socket;
	std::shared_ptr<zmq::socket_t> _commanderSocket;

	std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(new SpiderEventEmitter());
	std::unique_ptr<ISpiderEventListener<SpiderEnveloppe>> _eventListener = std::unique_ptr<ISpiderEventListener<SpiderEnveloppe>>(new SpiderEventListener<SpiderEnveloppe>());

	std::map<std::string, std::unique_ptr<ISpiderSocket>> _socketPool;

private:
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

	void RunReceive() {
		std::unique_ptr<ISpiderSocketPoller> poller = std::unique_ptr<ISpiderSocketPoller>(new ZeroMQSocketPoller());
		while (true) {
			std::vector<ISpiderSocket *> sockets;
			for (std::map<std::string, std::unique_ptr<ISpiderSocket>>::iterator it = _socketPool.begin(); it != _socketPool.end(); ++it) {
				sockets.push_back(it->second.get());
			}
			auto msg = poller->ReceivePoller(_socket.get(), sockets);

			SpiderEnveloppe envelope;
			try {
				// Code that could throw an exception
				envelope = SpiderDeserializer::GetEnvelopeFromMessage(std::get<1>(msg));
			}
			catch (const std::runtime_error& e) {
				std::cout << "Error : " << e.what() << std::endl;
				continue;
			}
			_eventEmitter->RouteToModules(envelope); //Dispatch message to inner communication service.
		}
	}
#pragma clang diagnostic pop

public:
	SpiderNetworkManager() {
		_socket = std::shared_ptr<ISpiderSocket>(new ZeroMQSocket());
		_commanderSocket = std::shared_ptr<zmq::socket_t>(new zmq::socket_t(*ISpiderDeamon::Context, ZMQ_REP));
	}

	virtual ~SpiderNetworkManager() {
		_socket->Disconnect();
		_commanderSocket->close();
	}

	void Run() override final {
		_socket->Bind("tcp://*:5432");
		_commanderSocket->bind("tcp://*:9876");

		_networkMenagerThread = std::unique_ptr<std::thread>(new std::thread(std::bind(&SpiderNetworkManager::RunReceive, this)));
		_eventListener->RegisterNoUnpack("SpiderNetworkManager", [&](std::string clientId, SpiderEnveloppe &enveloppe) {
			std::string enveloppe_data;
			enveloppe.SerializeToString(&enveloppe_data);
			_socket->Send(enveloppe.clientid(), enveloppe_data);
		});
	}
};

#endif //SPIDER_CLIENT_SPIDERNETWORKMANAGER_HPP