//
// Created by focus on 01.01.23.
//

#pragma once

#include <game.h>

struct game_base : game {
public:
	void run() final;
protected:
	static constexpr int MaxCountTimes = 1'000'000;

	virtual void start_game() = 0;
	virtual void ping() = 0;
	virtual void pong() = 0;
};