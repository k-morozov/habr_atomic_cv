//
// Created by focus on 01.01.23.
//

#pragma once

#include <memory>

#include <game.h>

class game_time : public game {
public:
	explicit game_time(std::unique_ptr<game> p) : game_(std::move(p)) {}
	void run() override;
private:
	std::unique_ptr<game> game_;
};