//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_WINDOWSCONTEXTAGENT_HPP
#define SPIDER_CLIENT_WINDOWSCONTEXTAGENT_HPP

#include <functional>
#include "ProcessInformation.hpp"
#include "IWindowsContextAgent.hpp"

class WindowsContextAgent : public IWindowsContextAgent {
public:
	void Run() {

	}

	void SetOnContextChanged(std::function<void(ProcessInformation)>) {

	}
private:
	std::function<void(ProcessInformation)> _onContextChanged;
};

#endif //SPIDER_CLIENT_WINDOWSCONTEXTAGENT_HPP