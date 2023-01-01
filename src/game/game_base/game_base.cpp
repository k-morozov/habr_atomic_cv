//
// Created by focus on 01.01.23.
//
#include "game_base.h"

#include <thread>

void game_base::run() {
	start_game();

	std::thread ping = std::thread(&game_base::ping, this);
	std::thread pong = std::thread(&game_base::pong, this);

	if (ping.joinable()) {
		ping.join();
	}
	if (pong.joinable()) {
		pong.join();
	}
}