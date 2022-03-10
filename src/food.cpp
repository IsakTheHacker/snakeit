#include "food.h"

Food::Food(const int& row, const int& col, const char& character) {
	y = row;
	x = col;
	c = character;
}

FoodMgr::FoodMgr(const int& amountFoodAtSameTime) {
	amount = amountFoodAtSameTime;
}

void FoodMgr::generate() {
	while (foodVec.size() < amount) {
		foodVec.push_back(Food(5, 5, stdconf::food));
	}
}

bool FoodMgr::checkIfEaten(int y, int x) {
	for (int i = 0; i < foodVec.size(); i++) {
		if (foodVec[i].y == y && foodVec[i].x == x) {
			return true;
		}
	}
	return false;
}
