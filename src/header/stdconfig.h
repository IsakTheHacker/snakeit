#pragma once
#include <string>

namespace stdconf {
	//const wchar_t snakeBodyPart = L'ｏ';
	//const wchar_t snakeHead = L'Ｏ';
	//const wchar_t food = L'＊';
	//const wchar_t emptySpace = L'ｦ';

	const wchar_t snakeBodyPart = L'o';
	const wchar_t snakeHead = L'O';
	const wchar_t food = L'@';
	const wchar_t emptySpace = L' ';

	const int xOffset = 2;
	const int yOffset = 1;
	const unsigned int delay = 100000; 		//Something, not milliseconds at least
}
