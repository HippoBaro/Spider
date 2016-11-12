#include <iostream>
#include "userInput.hpp"
#include "zmq.hpp"
#include <signal.h>
#include <CmdLine.h>
#include "protobufMessages/CmdPacket.pb.h"

void ctrlCSignal(int s){
  std::cout << "\"quit\" to exit the program\n$> " << std::endl;
  google::protobuf::ShutdownProtobufLibrary();
}

void handleSignal()
{
  struct sigaction sigIntHandler;
  sigIntHandler.sa_handler = ctrlCSignal;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  sigaction(SIGINT, &sigIntHandler, NULL);
}

int main(const int argc, const char **argv)
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  // Make sure that an IP is provided
  TCLAP::CmdLine cmd("Spider CLI", ' ', "v0.1");
  TCLAP::UnlabeledValueArg<std::string> clientIp("server", "Server IP you want to connect to.", true, "", "server");
  cmd.add(clientIp);
  cmd.parse(argc, argv);

  InputCenter input;
  input.readUserInput();

  google::protobuf::ShutdownProtobufLibrary();
  return EXIT_SUCCESS;
}
