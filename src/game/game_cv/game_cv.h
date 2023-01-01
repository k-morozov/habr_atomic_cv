//
// Created by focus on 01.01.23.
//

#pragma once

#include <mutex>
#include <condition_variable>

#include <game_base/game_base.h>

class game_cv final : public game_base {
	void ping() override;

	void pong() override;

	void start_game() override;

private:
	std::condition_variable cv_;
	std::mutex m_;
	bool ping_done_{false};
	bool pong_done_{false};
};
