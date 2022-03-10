#include "snake.h"

//Constructors and destructors
Bodypart::Bodypart(const int& row, const int& col, const char& character) {
	y = row;
	x = col;
	c = character;
}

//Constructors and destructors
Snake::Snake(int bodyLength, Direction direction) {
	for (size_t i = 0; i < bodyLength; i++) {
		body.push_back(Bodypart(0, 0 + i, stdconf::snakeBodyPart));
	}
	body.push_back(Bodypart(0, 0 + bodyLength, stdconf::snakeHead));
	
	this->direction = direction;
}

void Snake::draw() {
	for (Bodypart part : body) {
		mvwprintw(stdscr, part.y, part.x, char2cstr(part.c));
	}
}

void Snake::step() {

	int cy, cx;
	getyx(stdscr, cy, cx);

	//Remove last bit of tail
	move(body[0].y, body[0].x); 								//Move to the end of the tail
	printw(" "); 												//Add empty ch to remove last character
	body.pop_front();

	//Replace head with body part
	move(body[body.size()-1].y, body[body.size()-1].x); 		//Move to old head
	printw(char2cstr(stdconf::snakeBodyPart));
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
	printw(char2cstr(stdconf::snakeHead));

	move(cy, cx);
	refresh();
}