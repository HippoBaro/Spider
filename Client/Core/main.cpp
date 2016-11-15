#include "SpiderDeamon.hpp"

int WINAPI WinMain(HINSTANCE thisinstance, HINSTANCE previnstance,
	LPSTR cmdline, int ncmdshow)
{
	SpiderDeamon deamon;

	deamon.Run();

	//Let's wait indefinitely
	std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::hours(std::numeric_limits<int>::max()));
	return 0;
}