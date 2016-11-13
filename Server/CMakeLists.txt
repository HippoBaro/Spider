cmake_minimum_required(VERSION 3.3)
project(Spider_Server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB proto_SRC "./ProtoEnvelopes/Proto/*.pb.cc")

set(SOURCE_FILES
        main.cpp

        Interfaces/ISpiderServer.hpp
        Interfaces/ISpiderNetworkManager.hpp
        Interfaces/ISpiderBusinessManager.hpp
        Interfaces/ISpiderServer.hpp
        Interfaces/ISpiderBusinessModule.hpp
        Interfaces/ISpiderEventListener.hpp
        Interfaces/ISpiderEventEmitter.hpp
        Interfaces/ISpiderEventManager.hpp
        Interfaces/External/ISpiderSocket.hpp
        Interfaces/External/ISpiderSocketPoller.hpp

        Includes/ZeroMQ/zmq.hpp
        Includes/ZeroMQ/zmq_addon.hpp

        SpiderServer.hpp
        SpiderNetworkManager/SpiderNetworkManager.hpp
        BusinessManager/SpiderBusinessManager.hpp

        SpiderEventManager/SpiderEventManager.hpp
        SpiderEventManager/SpiderEventEmitter.hpp
        SpiderEventManager/SpiderEventListener.hpp

        SpiderSocket/ZeroMQ/ZeroMQSocket.hpp
        SpiderSocket/ZeroMQ/ZeroMQSocketPoller.hpp

        BusinessModules/OutputSTDOUTModule.hpp

        ${proto_SRC} Serialization/SpiderDeserializer.hpp Serialization/SpiderSerializer.hpp Interfaces/ISpiderCryptographicAgent.hpp Enums/Cryptography.hpp SpiderNetworkManager/RSACryptographicAgent.hpp SpiderNetworkManager/AESCryptographicAgent.hpp SpiderSocket/ZeroMQ/ZeroMQSecureSocket.hpp Enums/SecureSocketType.hpp)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/ProtoEnvelopes)

add_executable(Spider_Server ${SOURCE_FILES})
target_link_libraries(Spider_Server pthread zmq protobuf)