//
// Created by hippolyteb on 11/14/16.
//

#ifndef SPIDER_SERVER_ZEROMQEVENTMONITOR_HPP
#define SPIDER_SERVER_ZEROMQEVENTMONITOR_HPP

#include <iostream>
#include "../../Includes/ZeroMQ/zmq.hpp"

class ZeroMQEventMonitor : public zmq::monitor_t {
public:
    ZeroMQEventMonitor(zmq::socket_t *socket, const std::string &socketId) : zmq::monitor_t() {
        monitor(*socket, "inproc://" + socketId, ZMQ_EVENT_ALL);
    }

    virtual void on_event_connected(const zmq_event_t &event_, const char *addr_) override {

    }

    virtual void on_event_connect_delayed(const zmq_event_t &event_, const char *addr_) override {

    }

    virtual void on_event_connect_retried(const zmq_event_t &event_, const char *addr_) override {

    }

    virtual void on_event_listening(const zmq_event_t &event_, const char *addr_) override {
    }

    virtual void on_event_bind_failed(const zmq_event_t &event_, const char *addr_) override {
    }

    virtual void on_event_accepted(const zmq_event_t &event_, const char *addr_) override {
        std::cout << "New client connected with addrr : " << addr_ << std::endl;
    }

    virtual void on_event_accept_failed(const zmq_event_t &event_, const char *addr_) override {
    }

    virtual void on_event_closed(const zmq_event_t &event_, const char *addr_) override {
        std::cout << "Client closed with addrr : " << addr_ << std::endl;
    }

    virtual void on_event_close_failed(const zmq_event_t &event_, const char *addr_) override {
    }

    virtual void on_event_disconnected(const zmq_event_t &event_, const char *addr_) override {
        std::cout << "Client disconnected with addrr : " << addr_ << std::endl;
    }

    virtual void on_event_unknown(const zmq_event_t &event_, const char *addr_) override {
    }
};

#endif //SPIDER_SERVER_ZEROMQEVENTMONITOR_HPP
