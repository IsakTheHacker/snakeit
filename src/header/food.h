#pragma once

#include <vector>
#include <algorithm>
#include "deps.h"

#include "stdconfig.h"
#include "handyFunctions.h"
#include "snake.h"

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
	int paddingTop, paddingLeft, paddingBottom, paddingRight;
	std::vector<Food> foodVec;
	FoodMgr(int amountFoodAtSameTime, int paddingTop, int paddingLeft, int paddingBottom, int paddingRight);
	void generate(const Snake& snake);
	bool checkIfEaten(int y, int x);
	void draw();
};
