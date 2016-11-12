//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_WINDOWSCONTEXTAGENT_HPP
#define SPIDER_CLIENT_WINDOWSCONTEXTAGENT_HPP

#include <Psapi.h>
#include <functional>
#include "ProcessInformation.hpp"
#include "IWindowsContextAgent.hpp"

std::function<void(ProcessInformation)> onContextChanged;


class WindowsContextAgent : public IWindowsContextAgent {
private:
	void displayContext(ProcessInformation info) {
		std::cout << "Process Name : " << info.ProcessName << std::endl;
		std::cout << "Window Title : " << info.WindowTitle << std::endl;
	}

public:
	WindowsContextAgent() {
		onContextChanged = std::bind(&WindowsContextAgent::displayContext, this, std::placeholders::_1);
	}

	~WindowsContextAgent() {
		UnhookWinEvent(hEvent);
	}
	void Run() {
		hEvent = SetWinEventHook(EVENT_SYSTEM_FOREGROUND, EVENT_SYSTEM_FOREGROUND, NULL, WinEventProcCallback, 0, 0, WINEVENT_OUTOFCONTEXT | WINEVENT_SKIPOWNPROCESS);
	}


	void SetOnContextChanged(std::function<void(ProcessInformation)> func) {
		onContextChanged = func;
	}

	static VOID CALLBACK WinEventProcCallback(HWINEVENTHOOK hWinEventHook, DWORD dwEvent, HWND hwnd, LONG idObject, LONG idChild, DWORD dwEventThread, DWORD dwmsEventTime)
	{
		ProcessInformation info;
		DWORD processId;

		char tmp[0xFF] = { 0 };
		GetWindowThreadProcessId(hwnd, &processId);
		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);
		GetModuleBaseName(hProcess, NULL, tmp, 0xFF);
		info.ProcessName = std::string(tmp);
		GetWindowText(hwnd, tmp, 0xFF);
		info.WindowTitle = std::string(tmp);
		onContextChanged(info);
	}

private:
	HWINEVENTHOOK hEvent;
};

#endif //SPIDER_CLIENT_WINDOWSCONTEXTAGENT_HPP