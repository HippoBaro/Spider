#ifndef SPIDER_SERVER_ISPIDEREVENTLISTENER_HPP
#define SPIDER_SERVER_ISPIDEREVENTLISTENER_HPP

#include <string>
#include <functional>

template<class TPayload>
class ISpiderEventListener {
public:
	virtual void Register(std::string payloadType, std::function<void(std::string clientId, TPayload &)> onMessage) = 0;
	virtual void RegisterNoUnpack(std::string payloadType, std::function<void(std::string clientId, TPayload &)> onMessage) = 0;
};

#endif //SPIDER_SERVER_ISPIDEREVENTLISTENER_HPP