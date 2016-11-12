//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_IWINDOWSCONTEXTAGENT_HPP
#define SPIDER_CLIENT_IWINDOWSCONTEXTAGENT_HPP


class IWindowsContextAgent {
public:
	virtual void Run() = 0;
	virtual void OnContextChanged(std::string &processName, std::string &windowTitle) = 0;

};

#endif //SPIDER_CLIENT_IWINDOWSCONTEXTAGENT_HPP