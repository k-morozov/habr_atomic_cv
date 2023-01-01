//
// Created by focus on 01.01.23.
//

#include <memory>

#include <game_time/game_time.h>
#include <game_cv/game_cv.h>
#include <game_atomic/game_atomic.h>


int main() {
	game_time{std::make_unique<game_cv>()}.run();
	game_time{std::make_unique<game_atomic>()}.run();
}