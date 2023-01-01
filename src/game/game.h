//
// Created by focus on 01.01.23.
//

#pragma once

struct game {
	virtual ~game() = default;
	virtual void run() = 0;
};