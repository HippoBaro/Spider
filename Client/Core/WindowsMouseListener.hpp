//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_WINDOWSMOUSELISTENER_HPP
#define SPIDER_CLIENT_WINDOWSMOUSELISTENER_HPP

#include <future>
#include "IWindowsMouseListener.hpp"
#include "SpiderMouseEvent.pb.h"

HHOOK hhkLowLevelMouse;
IWindowsMouseListener *windowsMouseListener;

class WindowsMouseListener : public IWindowsMouseListener {
public:
	WindowsMouseListener() {
		// Set global variable mendatory for hook to access appContext.
		windowsMouseListener = this;
	}

	void Run() override final {
		hhkLowLevelMouse = SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseProc, GetModuleHandle(nullptr), 0);
	}

	bool busy = false;
	void OnMouseEvent(int button, long x, long y) {
		if (busy)
			return;

		busy = true;
		SpiderMouseEvent event;
		SpiderMouseEvent::MouseEventType type;

		switch (button)
		{
		case WM_LBUTTONDOWN:
			type = SpiderMouseEvent_MouseEventType_LBUTTON_CLICK;
			break;
		case WM_RBUTTONDOWN:
			type = SpiderMouseEvent_MouseEventType_RBUTTON_CLICK;
			break;
		case WM_MBUTTONDOWN:
			type = SpiderMouseEvent_MouseEventType_MBUTTON_DOWN;
			break;
		case WM_MBUTTONUP:
			type = SpiderMouseEvent_MouseEventType_MBUTTON_UP;
			break;
		case WM_MBUTTONDBLCLK:
			type = SpiderMouseEvent_MouseEventType_MBUTTON_CLICK;
			break;
		default:
			return; //Unknown event, ignoring.
		}

		event.set_type(type);
		event.set_x(x);
		event.set_y(y);
		SpiderEnveloppe enveloppe = SpiderSerializer::CreateResponseFromPayload("SpiderNetworkManager", event);
		_eventEmitter->Emit("SpiderNetworkManager", enveloppe);
		busy = false;
	}

private:
	static LRESULT CALLBACK LowLevelMouseProc(int code, WPARAM wp, LPARAM lp)
	{
		if (code == HC_ACTION)
		{
			auto s_mouse = reinterpret_cast<MSLLHOOKSTRUCT*>(lp);
			switch (wp)
			{
			case WM_LBUTTONDOWN:
				std::cout << "MOUSEEVENT" << std::endl;
				std::async([&]() {windowsMouseListener->OnMouseEvent(wp, s_mouse->pt.x, s_mouse->pt.y); });
				break;
			case WM_RBUTTONDOWN:
				std::async([&]() {windowsMouseListener->OnMouseEvent(wp, s_mouse->pt.x, s_mouse->pt.y); });
				break;
			case WM_MBUTTONDBLCLK:
				std::async([&]() {windowsMouseListener->OnMouseEvent(wp, s_mouse->pt.x, s_mouse->pt.y); });
				break;
			case WM_MBUTTONUP:
				std::async([&]() {windowsMouseListener->OnMouseEvent(wp, s_mouse->pt.x, s_mouse->pt.y); });
				break;
			case WM_MBUTTONDOWN:
				std::async([&]() {windowsMouseListener->OnMouseEvent(wp, s_mouse->pt.x, s_mouse->pt.y); });
				break;
			default:
				break;
			}
		}
		return CallNextHookEx(hhkLowLevelMouse, code, wp, lp);
	}

private:
	std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(std::make_unique<SpiderEventEmitter>());
};

#endif //SPIDER_CLIENT_WINDOWSMOUSELISTENER_HPP