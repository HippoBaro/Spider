#include <iostream>
#include "SpiderServer.hpp"

using namespace std;

int main() {
    SpiderServer server;

    server.Run();

    cout << "Hello, World!" << endl;
    return 0;
}