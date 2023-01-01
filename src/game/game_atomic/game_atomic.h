//
// Created by focus on 01.01.23.
//

#pragma once

#include <atomic>

#include <game_base/game_base.h>


class game_atomic final : public game_base {
	void ping() override;

	void pong() override;

	void start_game() override;

private:
	std::atomic_flag pass_;
	std::atomic_int current_counter_;
};