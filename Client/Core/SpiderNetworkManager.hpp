//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_SPIDERNETWORKMANAGER_HPP
#define SPIDER_CLIENT_SPIDERNETWORKMANAGER_HPP

#include "ISpiderNetworkManager.hpp"
#include <ostream>
#include <iostream>
#include <memory>
#include <thread>
#include "ISpiderSocket.hpp"
#include "ISpiderSocketPoller.hpp"
#include "ZeroMQSocketPoller.hpp"
#include "ISpiderEventEmitter.hpp"
#include "SpiderEventEmitter.hpp"
#include "ISpiderEventListener.hpp"
#include "SpiderEventListener.hpp"
#include "SpiderDeserialization.hpp"

class SpiderNetworkManager : public ISpiderNetworkManager {
private:
	std::unique_ptr<std::thread> _networkMenagerThread;

	std::shared_ptr<ISpiderSocket> _socket;

	std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(std::make_unique<SpiderEventEmitter>());
	std::unique_ptr<ISpiderEventListener<SpiderEnveloppe>> _eventListener = std::unique_ptr<ISpiderEventListener<SpiderEnveloppe>>(std::make_unique<SpiderEventListener<SpiderEnveloppe>>());

private:
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

	void RunReceive() {
		std::unique_ptr<ISpiderSocketPoller> poller = std::unique_ptr<ISpiderSocketPoller>(std::make_unique<ZeroMQSocketPoller>());
		while (true) {
			auto msg = _socket->Receive();

			SpiderEnveloppe envelope;
			try {
				// Code that could throw an exception
				envelope = SpiderDeserializer::GetEnvelopeFromMessage(msg);
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
		_socket = std::static_pointer_cast<ISpiderSocket>(std::make_shared<ZeroMQSocket>());
	}
	virtual ~SpiderNetworkManager() {
		_socket->Disconnect();
	}

	void Run() override final {
		_socket->Connect("tcp://spider.northeurope.cloudapp.azure.com:5432");

		_networkMenagerThread = std::make_unique<std::thread>(std::bind(&SpiderNetworkManager::RunReceive, this));
		_eventListener->RegisterNoUnpack("SpiderNetworkManager", [&](std::string clientId, SpiderEnveloppe &enveloppe) {
			std::string enveloppe_data;
			enveloppe.set_clientid("Wph2eyRK6ftjkNUP");
			enveloppe.SerializeToString(&enveloppe_data);
			try {
				// Code that could throw an exception
				_socket->Send(enveloppe.clientid(), enveloppe_data);
			}
			catch (const std::exception &e) {
				std::cout << "Error : " << e.what() << std::endl;
			}
			
		});
	}
};

#endif //SPIDER_CLIENT_SPIDERNETWORKMANAGER_HPP