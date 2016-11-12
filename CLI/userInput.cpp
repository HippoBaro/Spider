//
// Created by aguado_e on 08/11/16.
//

#include <readline/history.h>
#include <readline/readline.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "userInput.hpp"
#include "protobufMessages/CmdPacket.pb.h"

InputCenter::InputCenter()
{
}

void InputCenter::readUserInput()
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
    // TODO: wait for response here
  }
}

bool InputCenter::isCommandValid(std::vector<std::string> command) const
{
  for (auto it = _commands.begin(); it != _commands.end(); ++it)
  {
    // Does the command exist ?
    if (std::get<COMMAND>(*it) == command[0])
    {
      // Does it require an argument ?
      if (std::get<ARG>(*it) != "")
        return (command.size() == 3);
      else
        return true;
    }
  }
  return false;
}

// TODO: abstract commands in another Class for a clearer code
void InputCenter::_sendCommand(std::string command) const
{
  std::vector<std::string> splittedCommands;
  std::stringstream ss(command);
  std::string temp;
  while (ss >> temp)
    splittedCommands.push_back(temp);

  // Error handling
  if (splittedCommands.size() < 2)
    help();
  else if (!isCommandValid(splittedCommands))
    help();

  // Send command
  else
  {
    spider::CmdPacket package;
    package.set_targetuuid(splittedCommands[0]);
    package.set_name(splittedCommands[1]);
    if (splittedCommands.size() == 3)
      package.set_argument(splittedCommands[2]);
  }
}

void InputCenter::help() const
{
  std::cout << "USAGE:\n\n\t<client UUID> <command> [arguments]\n" << std::endl;
  std::cout << "COMMANDS:\n" << std::endl;
  for (auto it = _commands.begin(); it != _commands.end(); ++it)
  {
    std::cout << '\t' << std::left << std::setw(10) << std::get<COMMAND>(*it);
    std::cout << '\t' << std::left << std::setw(15) << std::get<ARG>(*it);
    std::cout << std::get<DESC>(*it) << '\n' << std::endl;
  }
}
