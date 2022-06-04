#include "food.h"

Food::Food(const int& row, const int& col, const wchar_t& character) {
	y = row;
	x = col;
	c = character;
}

FoodMgr::FoodMgr(int amountFoodAtSameTime, int minheight, int minwidth, int maxheight, int maxwidth)
	: amount{amountFoodAtSameTime}, minheight{minheight}, minwidth{minwidth}, maxheight{maxheight}, maxwidth{maxwidth} {
	
}

void FoodMgr::generate() {
	while ((int)foodVec.size() < amount) {
		int randy = randIntRange(minheight, maxheight);
		int randx = randIntRange(minwidth, maxwidth);
		foodVec.push_back(Food(randy, randx, stdconf::food));
	}
	draw();
}

void FoodMgr::draw() {
	cchar_t cchar;
	for (Food food : foodVec) {
		cchar = wchar2cchar(food.c);
		mvwadd_wch(stdscr, food.y, food.x, &cchar);
	}
}

bool FoodMgr::checkIfEaten(int y, int x) {
	for (int i = 0; i < (int)foodVec.size(); i++) {
		if (foodVec[i].y == y && foodVec[i].x == x) {
			foodVec.erase(foodVec.begin() + i);
			return true;
		}
	}
	return false;
}
