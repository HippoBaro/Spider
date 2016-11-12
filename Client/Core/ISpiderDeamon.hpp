//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_ISPIDERDEAMON_HPP
#define SPIDER_CLIENT_ISPIDERDEAMON_HPP
#include "zmq.hpp"

#include <memory>

class ISpiderDeamon {
public:
	static zmq::context_t *Context;
	virtual void Run() = 0;
};

zmq::context_t *ISpiderDeamon::Context = new zmq::context_t();

#endif //SPIDER_CLIENT_ISPIDERDEAMON_HPP