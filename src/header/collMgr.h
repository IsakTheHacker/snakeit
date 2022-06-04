#pragma once
#include "stdconfig.h"

class CollMgr {
public:
	CollMgr(int yMin, int xMin, int yMax, int xMax);
	void changeBorderDim(int yMin, int xMin, int yMax, int xMax);
	bool checkForCollision(int y, int x);
private:
	int yMin, xMin, yMax, xMax;
};
