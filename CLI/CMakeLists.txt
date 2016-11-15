cmake_minimum_required(VERSION 3.2)
project(.)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(GLOB proto_SRC "./protobufMessages/*.pb.cc")

set(SOURCE_FILES
        main.cpp
        zmq.hpp
        userInput.hpp
        Command.hpp
        ${proto_SRC} ConnectionManager.hpp MessageDeserializer.hpp)

add_executable(CLI ${SOURCE_FILES})
target_link_libraries(CLI pthread zmq readline protobuf)
