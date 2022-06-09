#include "collMgr.h"

CollMgr::CollMgr(int paddingTop, int paddingLeft, int paddingBottom, int paddingRight)
	: paddingTop{paddingTop}, paddingLeft{paddingLeft}, paddingBottom{paddingBottom}, paddingRight{paddingRight}
{
}

bool CollMgr::checkForCollision(int y, int x) {
	if ((y == paddingTop-stdconf::yOffset || y == Globals::winHeight - paddingBottom) || (x == paddingLeft-stdconf::xOffset || x == Globals::winWidth - paddingRight)) {
		return true;
	} else {
		return false;
	}
}
