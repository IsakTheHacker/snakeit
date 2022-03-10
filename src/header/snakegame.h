#pragma once

#include <deque>
#include <string>

#include <ncurses.h>
#include <unistd.h>

#include "stdconfig.h"
#include "snake.h"

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
