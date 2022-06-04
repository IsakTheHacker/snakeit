#include "collMgr.h"

CollMgr::CollMgr(int yMin, int xMin, int yMax, int xMax)
	: yMin{yMin}, xMin{xMin}, yMax{yMax}, xMax{xMax} {
	
}

void CollMgr::changeBorderDim(int yMin, int xMin, int yMax, int xMax) {
	this->yMin = yMin;
	this->xMin = xMin;
	this->yMax = yMax;
	this->xMax = xMax;
}

bool CollMgr::checkForCollision(int y, int x) {
	if ((y == yMin-stdconf::yOffset || y == yMax) || (x == xMin-stdconf::xOffset || x == xMax)) {
		return true;
	} else {
		return false;
	}
}
