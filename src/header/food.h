#pragma once

#include <vector>

#include "stdconfig.h"

class Food {
public:
	int y, x;
	char c;
	Food(const int& row, const int& col, const char& character);
};

class FoodMgr {
public:
	int amount;
	std::vector<Food> foodVec;
	FoodMgr(const int& amountFoodAtSameTime);
	void generate();
	bool checkIfEaten(int y, int x);
};