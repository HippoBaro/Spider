cmake_minimum_required(VERSION 3.2)
project(.)

include_directories(
        /usr/local/lib
        include/tclap
        protobufMessages
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        userInput.cpp
        zmq.hpp
        Command.hpp
        protobufMessages/CmdPacket.pb.cc
        )

add_executable(CLI ${SOURCE_FILES})
target_link_libraries(CLI pthread zmq readline protobuf)
