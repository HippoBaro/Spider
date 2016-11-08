cmake_minimum_required(VERSION 3.3)
project(Spider_Server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp

        Interfaces/ISpiderServer.hpp
        Interfaces/ISpiderNetworkManager.hpp

        Includes/ZeroMQ/zmq.hpp
        Includes/ZeroMQ/zmq_addon.hpp Interfaces/ISpiderServer.hpp SpiderServer.hpp SpiderNetworkManager/SpiderNetworkManager.hpp Interfaces/ISpiderBusinessManager.hpp BusinessManager/SpiderBusinessManager.hpp Interfaces/ISpiderBusinessModule.hpp Interfaces/ISpiderEventListener.hpp Interfaces/ISpiderEventEmitter.hpp Interfaces/ISpiderEventManager.hpp SpiderEventManager/SpiderEventManager.hpp SpiderEventManager/SpiderEventEmitter.hpp SpiderEventManager/SpiderEventListener.hpp)

add_executable(Spider_Server ${SOURCE_FILES})
target_link_libraries(Spider_Server pthread zmq)