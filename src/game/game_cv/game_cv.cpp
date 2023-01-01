//
// Created by focus on 01.01.23.
//

#include "game_cv.h"

void game_cv::ping() {
	int counter = 0;

	while (counter <= MaxCountTimes) {
		{
			std::unique_lock lck(m_);
			cv_.wait(lck, [this]() {
				return ping_done_;
			});
			ping_done_ = false;
			pong_done_ = true;
			counter++;
		}
		cv_.notify_one();
	}
}

void game_cv::pong() {
	int counter = 0;

	while (counter<MaxCountTimes) {
		{
			std::unique_lock lck(m_);
			cv_.wait(lck, [this](){
				return pong_done_;
			});
			ping_done_ = true;
			pong_done_ = false;
			counter++;
		}
		cv_.notify_one();
	}
}

void game_cv::start_game() {
	{
		std::unique_lock lck(m_);
		ping_done_ = true;
	}
	cv_.notify_one();
}