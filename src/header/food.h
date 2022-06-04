#pragma once

#include <vector>
#include <ncurses.h>

#include "stdconfig.h"
#include "handyFunctions.h"

class Food {
public:
	int y, x;
	wchar_t c;
	Food(const int& row, const int& col, const wchar_t& character);
	Food(const int& row, const int& col, const wchar_t* character);
};

class FoodMgr {
public:
	int amount;
	int minheight, minwidth, maxheight, maxwidth;
	std::vector<Food> foodVec;
	FoodMgr(int amountFoodAtSameTime, int minheight, int minwidth, int maxheight, int maxwidth);
	void generate();
	bool checkIfEaten(int y, int x);
	void draw();
};
