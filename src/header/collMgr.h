#pragma once
#include "stdconfig.h"
#include "globals.h"

class CollMgr {
public:
	CollMgr(int paddingTop, int paddingLeft, int paddingBottom, int paddingRight);
	bool checkForCollision(int y, int x);
private:
	int paddingTop, paddingLeft, paddingBottom, paddingRight;
};
