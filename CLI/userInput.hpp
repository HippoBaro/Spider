//
// Created by aguado_e on 08/11/16.
//

#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include <string>
#include <readline/history.h>
#include <readline/readline.h>
#include "Command.hpp"
#include "zmq.hpp"

class InputCenter {
public:
  InputCenter() :
    _context(1),
    _socket(_context, ZMQ_REP)
  {
    _socket.bind("tcp://*:9876");
  }

  ~InputCenter()
  {

  }

  void readUserInput()
  {
    while (true)
    {
      char *input = readline("$> ");
      if (!input)
        break;
      else if (*input)
        add_history(input);
      this->_sendCommand(std::string(input));
      free(input);
      this->_waitResponse();
    }
  }

private:
  zmq::context_t _context;
  zmq::socket_t _socket;

  void _sendCommand(std::string command)
  {
    Spider::Command finalCommand(command);
    if (finalCommand.isValid())
    {


//      std::string content = finalCommand.getPacket().SerializeAsString();
//      zmq::message_t message(content.length());
//      memcpy(message.data(), content, content.length());
//      _socket.send(message);
    }
  }

  void _waitResponse()
  {
//    zmq::message_t request;
//    _socket.recv(&request);
//    std::cout << request << std::endl;
  }

};


#endif //USERINPUT_HPP
