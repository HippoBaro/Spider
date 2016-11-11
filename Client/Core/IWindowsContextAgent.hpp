//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_IWINDOWSCONTEXTAGENT_HPP
#define SPIDER_CLIENT_IWINDOWSCONTEXTAGENT_HPP

#include "ProcessInformation.hpp"

class IWindowsContextAgent {
public:
	virtual void Run() = 0;
	virtual void SetOnContextChanged(std::function<void(ProcessInformation)>) = 0;

};

#endif //SPIDER_CLIENT_IWINDOWSCONTEXTAGENT_HPP