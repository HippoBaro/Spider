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

  SpiderEnveloppe readUserInput(const std::string &endpoint)
  {
    char *input = readline(std::string(endpoint + "> ").c_str());
    if (!input)
      return SpiderEnveloppe();
    else if (*input)
      add_history(input);
    auto ret = getEnveloppeFromInput(std::string(input));
    free(input);
    return ret;
  }

private:

  SpiderEnveloppe getEnveloppeFromInput(std::string command)
  {
    Spider::Command finalCommand(command);
    if (finalCommand.isValid())
      return finalCommand.getPacket();
    return SpiderEnveloppe();
  }
};


#endif //USERINPUT_HPP
