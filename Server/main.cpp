#include <iostream>
#include "SpiderServer.hpp"
#include "SpiderDatabaseDriver/RedisDriver/RedisDriver.hpp"

using namespace std;

int main() {
    SpiderServer server;
    server.Run();

    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::hours(std::numeric_limits<int>::max()));
    return 0;
}