//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_IWINDOWSMOUSELISTENER_HPP
#define SPIDER_CLIENT_IWINDOWSMOUSELISTENER_HPP

class IWindowsMouseListener {
public:
	virtual void Run() = 0;
	virtual void OnMouseEvent(int button, long x, long y) = 0;
};

#endif //SPIDER_CLIENT_IWINDOWSMOUSELISTENER_HPP