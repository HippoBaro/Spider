#include "SpiderDeamon.hpp"

int main(void)
{
	SpiderDeamon client;

	while (true) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return (0);
}