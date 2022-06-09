#pragma once
#include <string>

namespace stdconf {
	const wchar_t snakeHeadRight = L'▶';
	const wchar_t snakeHeadLeft = L'◀';
	const wchar_t snakeHeadDown = L'▼';
	const wchar_t snakeHeadUp = L'▲';

	const wchar_t snakeBodyPart = L'●';
	const wchar_t food = L'◆';
	const wchar_t emptySpace = L' ';

	//const wchar_t snakeBodyPart = L'o';
	//const wchar_t snakeHead = L'O';
	//const wchar_t food = L'@';
	//const wchar_t emptySpace = L' ';

	const int foodSpawnframePaddingRight = 2;
	const int foodSpawnframePaddingLeft = 2;
	const int foodSpawnframePaddingBottom = 1;
	const int foodSpawnframePaddingTop = 1;
	const int amountFoodAtSameTime = 1;

	const bool checkForSnakeSelfCollision = false;
	const bool checkForSnakeWallCollision = false;

	const int xOffset = 2;
	const int yOffset = 1;
	const unsigned int delay = 100000; 		//Something, not milliseconds at least
}
