//
// Created by focus on 01.01.23.
//

#include "game_time.h"

#include <iostream>
#include <chrono>

void game_time::run() {
	auto start = std::chrono::system_clock::now();

	game_->run();

	std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
	std::cout << "Duration: " << dur.count() << " seconds" << std::endl;
}