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
		body.push_back(Bodypart(0, 0 + i, stdconf::snakeBodyPart));
	}
	body.push_back(Bodypart(0, 0 + bodyLength, stdconf::snakeHead));
	
	this->direction = direction;
}

void Snake::draw() {
	cchar_t cchar;
	for (Bodypart part : body) {
		cchar = wchar2cchar(part.c);
		mvwadd_wch(stdscr, part.y, part.x, &cchar);
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
	add_wch(&cchar);
	body[body.size()-1] = Bodypart(body[body.size()-1].y, body[body.size()-1].x, stdconf::snakeBodyPart);
	
	switch(direction) {
	case Direction::RIGHT:
		body.push_back(Bodypart(body[body.size()-1].y, body[body.size()-1].x + 1, stdconf::snakeHead));
	break;
	case Direction::LEFT:
		body.push_back(Bodypart(body[body.size()-1].y, body[body.size()-1].x - 1, stdconf::snakeHead));
	break;
	case Direction::DOWN :
		body.push_back(Bodypart(body[body.size()-1].y + 1, body[body.size()-1].x, stdconf::snakeHead));
	break;
	case Direction::UP:
		body.push_back(Bodypart(body[body.size()-1].y - 1, body[body.size()-1].x, stdconf::snakeHead));
	break;
	}

	//Draw new head
	move(body[body.size()-1].y, body[body.size()-1].x); 		//Move to new head
	cchar = wchar2cchar(stdconf::snakeHead);
	add_wch(&cchar);
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
	addch(' '); 												//Add empty ch to remove last character
	body.pop_front();

	//Replace head with body part
	move(body[body.size()-1].y, body[body.size()-1].x); 		//Move to old head
	cchar = wchar2cchar(stdconf::snakeBodyPart);
	add_wch(&cchar);
	body[body.size()-1] = Bodypart(body[body.size()-1].y, body[body.size()-1].x, stdconf::snakeBodyPart);
	
	switch(direction) {
	case Direction::RIGHT:
		body.push_back(Bodypart(body[body.size()-1].y, body[body.size()-1].x + 1, stdconf::snakeHead));
	break;
	case Direction::LEFT:
		body.push_back(Bodypart(body[body.size()-1].y, body[body.size()-1].x - 1, stdconf::snakeHead));
	break;
	case Direction::DOWN :
		body.push_back(Bodypart(body[body.size()-1].y + 1, body[body.size()-1].x, stdconf::snakeHead));
	break;
	case Direction::UP:
		body.push_back(Bodypart(body[body.size()-1].y - 1, body[body.size()-1].x, stdconf::snakeHead));
	break;
	}

	//Draw new head
	move(body[body.size()-1].y, body[body.size()-1].x); 		//Move to new head
	cchar = wchar2cchar(stdconf::snakeHead);
	add_wch(&cchar);

	move(cy, cx);
	refresh();
}
