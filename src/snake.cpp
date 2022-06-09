#include "snake.h"

//Constructors and destructors
Bodypart::Bodypart(const int& row, const int& col, const wchar_t& character) {
	y = row;
	x = col;
	c = character;
}

//Constructors and destructors
Snake::Snake(int bodyLength, Direction direction) {
	for (int i = 0; i < bodyLength; i++) {
		body.push_back(Bodypart(0, stdconf::xOffset * i, stdconf::snakeBodyPart));
	}
	body.push_back(Bodypart(0, stdconf::xOffset * bodyLength, stdconf::snakeHeadRight));
	
	this->direction = direction;
}

void Snake::draw() {
	cchar_t cchar;
	for (Bodypart part : body) {
		cchar = wchar2cchar(part.c);
		if (part.c == stdconf::snakeBodyPart) {
			SAFE_ATTRON(COLOR_PAIR(BODYPART_PAIR));
		} else {
			SAFE_ATTRON(COLOR_PAIR(HEAD_PAIR));
		}
		mvwadd_wch(stdscr, part.y, part.x, &cchar);
		SAFE_ATTROFF(COLOR_PAIR(COFF_PAIR));
	}
}

Bodypart Snake::getHead() {
	return body[body.size() - 1];
}

void Snake::lengthen(int bodypartAmount) {
	cchar_t cchar;

	//Replace head with body part
	move(body[body.size()-1].y, body[body.size()-1].x); 		//Move to old head
	cchar = wchar2cchar(stdconf::snakeBodyPart);
	SAFE_ATTRON(COLOR_PAIR(BODYPART_PAIR));
	add_wch(&cchar);
	SAFE_ATTROFF(COLOR_PAIR(COFF_PAIR));
	body[body.size()-1] = Bodypart(body[body.size()-1].y, body[body.size()-1].x, stdconf::snakeBodyPart);
	
	createNewHead();

	//Draw new head
	move(body[body.size()-1].y, body[body.size()-1].x); 		//Move to new head
	cchar = wchar2cchar(body[body.size()-1].c);
	SAFE_ATTRON(COLOR_PAIR(HEAD_PAIR));
	add_wch(&cchar);
	SAFE_ATTROFF(COLOR_PAIR(COFF_PAIR));
}

bool Snake::checkSelfCollision() {
	for (size_t i = 0; i < body.size()-1; i++)					//"body.size()-1" because we want to exclude the head
		if (getHead().y == body[i].y && getHead().x == body[i].x)
			return true;
	return false;
}

void Snake::progress() {
	cchar_t cchar;

	int cy, cx;
	getyx(stdscr, cy, cx);

	//Remove last bit of tail
	move(body[0].y, body[0].x); 								//Move to the end of the tail
	cchar = wchar2cchar(stdconf::emptySpace);
	add_wch(&cchar); 											//Add empty ch to remove last character
	body.pop_front();

	//Replace head with body part
	move(body[body.size()-1].y, body[body.size()-1].x); 		//Move to old head
	cchar = wchar2cchar(stdconf::snakeBodyPart);
	SAFE_ATTRON(COLOR_PAIR(BODYPART_PAIR));
	add_wch(&cchar);
	SAFE_ATTROFF(COLOR_PAIR(COFF_PAIR));
	body[body.size()-1] = Bodypart(body[body.size()-1].y, body[body.size()-1].x, stdconf::snakeBodyPart);
	
	createNewHead();

	//Draw new head
	move(body[body.size()-1].y, body[body.size()-1].x); 		//Move to new head
	cchar = wchar2cchar(body[body.size()-1].c);
	SAFE_ATTRON(COLOR_PAIR(HEAD_PAIR));
	add_wch(&cchar);
	SAFE_ATTROFF(COLOR_PAIR(COFF_PAIR));

	move(cy, cx);
	refresh();
}

void Snake::createNewHead() {
	int newX, newY;
	int maxheight, maxwidth;
	getmaxyx(stdscr, maxheight, maxwidth);	// define dimensions of game window
	switch (direction) {
	case Direction::RIGHT:
		newX = body[body.size()-1].x + stdconf::xOffset;
		if (newX > maxwidth - 1)
			newX = 0;
		body.push_back(Bodypart(body[body.size()-1].y, newX, stdconf::snakeHeadRight));
	break;
	case Direction::LEFT:
		newX = body[body.size()-1].x - stdconf::xOffset;
		if (newX < 0)
			newX = maxwidth - 2;
		body.push_back(Bodypart(body[body.size()-1].y, newX, stdconf::snakeHeadLeft));
	break;
	case Direction::DOWN:
		newY = body[body.size()-1].y + stdconf::yOffset;
		if (newY > maxheight - 2)
			newY = 0;
		body.push_back(Bodypart(newY, body[body.size()-1].x, stdconf::snakeHeadDown));
	break;
	case Direction::UP:
		newY = body[body.size()-1].y - stdconf::yOffset;
		if (newY < 0)
			newY = maxheight - 2;
		body.push_back(Bodypart(newY, body[body.size()-1].x, stdconf::snakeHeadUp));
	break;
	}
}
