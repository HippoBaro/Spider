//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_WINDOWSCONTEXTAGENT_HPP
#define SPIDER_CLIENT_WINDOWSCONTEXTAGENT_HPP

#include <Psapi.h>
#include <functional>
#include "IWindowsContextAgent.hpp"
#include "SpiderSerializer.hpp"
#include "SpiderContextChangedEvent.pb.h"

IWindowsContextAgent *windowsContextAgent;

class WindowsContextAgent : public IWindowsContextAgent {

public:
	WindowsContextAgent() {
		windowsContextAgent = this; //This is mendatory for the hook to be able to communicate with our appContext.
	}

	~WindowsContextAgent() {
		UnhookWinEvent(hEvent);
	}

	void Run() override final {
		hEvent = SetWinEventHook(EVENT_SYSTEM_FOREGROUND, EVENT_SYSTEM_FOREGROUND, nullptr, WinEventProcCallback, 0, 0, WINEVENT_OUTOFCONTEXT | WINEVENT_SKIPOWNPROCESS);
	}

	void OnContextChanged(std::string &processName, std::string &windowTitle) override final {
		SpiderContextChangedEvent event;
		event.set_processname(processName);
		event.set_windowtitle(windowTitle);
		SpiderEnveloppe enveloppe = SpiderSerializer::CreateFromPayload("OnWindowsContextChanged", event);
		_eventEmitter->Emit("OnWindowsContextChanged", enveloppe);
	}

	static VOID CALLBACK WinEventProcCallback(HWINEVENTHOOK hWinEventHook, DWORD dwEvent, HWND hwnd, LONG idObject, LONG idChild, DWORD dwEventThread, DWORD dwmsEventTime)
	{
		DWORD processId;

		char tmp[0xFF] = { 0 };
		GetWindowThreadProcessId(hwnd, &processId);
		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);
		GetModuleBaseName(hProcess, nullptr, tmp, 0xFF);
		std::string processName = std::string(tmp);
		GetWindowText(hwnd, tmp, 0xFF);
		std::string windowTitle = std::string(tmp);
		windowsContextAgent->OnContextChanged(processName, windowTitle);
	}

private:
	HWINEVENTHOOK hEvent;
	std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(std::make_unique<SpiderEventEmitter>());
};

#endif //SPIDER_CLIENT_WINDOWSCONTEXTAGENT_HPP