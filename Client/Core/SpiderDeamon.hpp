//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_SPIDERDEAMON_HPP
#define SPIDER_CLIENT_SPIDERDEAMON_HPP

#include "ISpiderDeamon.hpp"
#include <memory>
#include <thread>
#include "SpiderEventManager.hpp"
#include "SpiderNetworkManager.hpp"

class SpiderDeamon : public ISpiderDeamon {
private:
	std::unique_ptr<ISpiderNetworkManager> NetworkManager = std::unique_ptr<ISpiderNetworkManager>(new SpiderNetworkManager());
	std::unique_ptr<ISpiderEventManager> EventManager = std::unique_ptr<ISpiderEventManager>(new SpiderEventManager());

public:
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
	void Run() override final {
		EventManager->Run();
		NetworkManager->Run();

		while (true) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
		};
	}
#pragma clang diagnostic pop
};

#endif //SPIDER_CLIENT_SPIDERDEAMON_HPP