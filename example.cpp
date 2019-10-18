#include "clogger.hpp"

#include <iostream>
#include <fstream>
#include <chrono>

auto& debug = clog::logger["debug"];

int main()
{
	debug << "hello";

	std::ofstream ofs("txt.txt");
	debug(ofs);

	debug << "hello";

	auto now = std::chrono::system_clock::now();
	auto sec = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
	std::cout << sec << std::endl;
}
