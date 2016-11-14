//
// Created by aguado_e on 08/11/16.
//

#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include <string>

class InputCenter {
public:
  InputCenter();

  void readUserInput();

private:


  void _sendCommand(std::string) const;
  void _waitResponse() const;

};


#endif //USERINPUT_HPP
