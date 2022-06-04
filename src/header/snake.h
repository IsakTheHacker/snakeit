#pragma once

#include <deque>

#include <ncurses.h>

#include "stdconfig.h"
#include "handyFunctions.h"

struct Bodypart {
public:
	int y, x;
	wchar_t c;
	Bodypart(const int& row, const int& col, const wchar_t& character);
};

enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct Snake {
public:
	std::deque<Bodypart> body;
	Direction direction;
	Snake(int bodyLength = 3, Direction direction = Direction::RIGHT);
	void draw();
	void progress();
	Bodypart getHead();
	void lengthen(int bodypartAmount);
	bool checkSelfCollision();
};
