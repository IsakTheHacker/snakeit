#pragma once

#include <deque>
#include <string>

#include <ncurses.h>
#include <unistd.h>

#include "stdconfig.h"

struct Bodypart {
public:
	int y, x;
	char c;
	Bodypart(const int& row, const int& col, const char& character);
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
	void step();
};

class SnakeGame {
private:
	int maxheight, maxwidth;
	Snake ekans;

	void initWindow();

public:
	SnakeGame();
	~SnakeGame();

	int play();
	void render();
};

const char* char2cstr(const char& c);
