#pragma once

#include <deque>
#include <string>

#include <ncurses.h>
#include <unistd.h>

#include "stdconfig.h"
#include "snake.h"
#include "food.h"
#include "collMgr.h"
#include "globals.h"

class SnakeGame {
private:
	Snake ekans;
	FoodMgr* foodMgr;
	CollMgr* collMgr;

	int winHeightLastFrame;
	int winWidthLastFrame;

	void initWindow();
	void deinitWindow();
	void drawStatusbar();
	bool hasDimensionsChanged();
	void receiveDirections(const int& c);
	void render();

public:
	SnakeGame();
	~SnakeGame();

	int play();
};
