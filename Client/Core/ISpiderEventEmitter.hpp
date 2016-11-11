#ifndef SPIDER_SERVER_ISPIDEREVENTEMITTER_HPP
#define SPIDER_SERVER_ISPIDEREVENTEMITTER_HPP

#include <string>
#include "SpiderEnveloppe.pb.h"

class ISpiderEventEmitter {
public:
	virtual void RouteToModules(SpiderEnveloppe &payload) = 0;
	virtual void Emit(std::string destinator, SpiderEnveloppe &payload) = 0;
};

#endif //SPIDER_SERVER_ISPIDEREVENTEMITTER_HPP