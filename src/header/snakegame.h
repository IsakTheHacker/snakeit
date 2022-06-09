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

	void initWindow();
	void deinitWindow();
	void drawStatusbar(const Snake& snake);
	void redrawWindowIfDimsChanged();
	void render();

public:
	SnakeGame();
	~SnakeGame();

	int play();
};
