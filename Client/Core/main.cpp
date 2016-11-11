#include "SpiderDeamon.hpp"

int main(int ac, char **av)
{
	SpiderDeamon deamon;

	deamon.Run();

	std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::hours(std::numeric_limits<int>::max()));
	return 0;
}
