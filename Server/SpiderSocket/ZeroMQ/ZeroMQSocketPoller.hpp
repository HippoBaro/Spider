//
// Created by hippolyteb on 11/8/16.
//

#ifndef SPIDER_SERVER_ZEROMQSOCKETPOLLER_HPP
#define SPIDER_SERVER_ZEROMQSOCKETPOLLER_HPP

#include "../../Interfaces/External/ISpiderSocketPoller.hpp"
#include "../../Includes/ZeroMQ/zmq_addon.hpp"

class ZeroMQSocketPoller : public ISpiderSocketPoller {
    virtual std::tuple<std::string, std::string> ReceivePoller(ISpiderSocket *master, std::vector<ISpiderSocket *> vector) override final {
        zmq::socket_t *sock = ((zmq::socket_t *)master->GetNativeSocket());
        zmq::multipart_t msg(*sock);
        auto id = msg.popstr();
        auto payload = msg.popstr();
        return std::tuple<std::string, std::string>(id, payload);
    }
};

#endif //SPIDER_SERVER_ZEROMQSOCKETPOLLER_HPP
