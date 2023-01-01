//
// Created by focus on 01.01.23.
//

#include "game_atomic.h"

void game_atomic::ping() {
	int counter = 0;

	while (counter <= MaxCountTimes) {
		pass_.wait(false);
		pass_.clear();
		counter++;
		current_counter_++;
		pass_.notify_one();
	}
}

void game_atomic::pong() {
	int counter = 0;

	while (counter < MaxCountTimes) {
		pass_.wait(true);

		pass_.test_and_set();
		counter++;
		pass_.notify_one();
	}
}

void game_atomic::start_game() {
	pass_.test_and_set();
	pass_.notify_one();
}