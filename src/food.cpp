#include "food.h"

Food::Food(const int& row, const int& col, const wchar_t& character) {
	y = row;
	x = col;
	c = character;
}

FoodMgr::FoodMgr(int amountFoodAtSameTime, int minheight, int minwidth, int maxheight, int maxwidth)
	: amount{amountFoodAtSameTime}, minheight{minheight}, minwidth{minwidth}, maxheight{maxheight}, maxwidth{maxwidth} {
	
}

void FoodMgr::generate(const Snake& snake) {
	while ((int)foodVec.size() < amount) {
		//Create array with favorable coordinates
		std::vector<int> favorableYPositions;
		std::vector<int> favorableXPositions;
		for (int i = minheight; i < maxheight; i++) {
			favorableYPositions.push_back(i);
		}
		for (int i = minwidth; i < maxwidth; i += 2) {
			favorableXPositions.push_back(i);
		}

		//Remove unfavorable coordinates aka positions currently taken up by the snake
		for (Bodypart bodyPart : snake.body) {
			favorableYPositions.erase(std::remove(favorableYPositions.begin(), favorableYPositions.end(), bodyPart.y), favorableYPositions.end());
			favorableXPositions.erase(std::remove(favorableXPositions.begin(), favorableXPositions.end(), bodyPart.x), favorableXPositions.end());
		}

		int randy = randIntRange(0, favorableYPositions.size() - 1);
		int randx = randIntRange(0, favorableXPositions.size() - 1);
		foodVec.push_back(Food(favorableYPositions[randy], favorableXPositions[randx], stdconf::food));
	}
	draw();
}

void FoodMgr::draw() {
	cchar_t cchar;
	for (Food food : foodVec) {
		cchar = wchar2cchar(food.c);
		SAFE_ATTRON(COLOR_PAIR(FOOD_PAIR));
		mvwadd_wch(stdscr, food.y, food.x, &cchar);
		SAFE_ATTROFF(COLOR_PAIR(COFF_PAIR));
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
