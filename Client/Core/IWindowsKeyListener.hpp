//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_IWINDOWSKEYLISTENER_HPP
#define SPIDER_CLIENT_IWINDOWSKEYLISTENER_HPP

class IWindowsKeyListener {
public:
	virtual void Run() = 0;
	virtual std::string Flush() = 0;
};

#endif //SPIDER_CLIENT_IWINDOWSKEYLISTENER_HPP