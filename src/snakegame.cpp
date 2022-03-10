#include "snakegame.h"

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

//Constructors and destructors
SnakeGame::SnakeGame() {
	ekans = Snake(7, Direction::RIGHT);
	initWindow();
}
SnakeGame::~SnakeGame() {
	nodelay(stdscr, false);
	endwin();
}

int SnakeGame::play() {
	int c;
	while (true) {

		//Recieve input
		c = getch();
		switch(c) {
		case KEY_LEFT:
			if (ekans.direction != Direction::RIGHT)
				ekans.direction = Direction::LEFT;
		break;
		case KEY_RIGHT:
			if (ekans.direction != Direction::LEFT)
				ekans.direction = Direction::RIGHT;
		break;
		case KEY_UP:
			if (ekans.direction != Direction::DOWN)
				ekans.direction = Direction::UP;
		break;
		case KEY_DOWN:
			if (ekans.direction != Direction::UP)
				ekans.direction = Direction::DOWN;
		break;
		case KEY_BACKSPACE:
			//Quit
		break;
		}

		//Do processing
		ekans.step();

		//Render output
		ekans.draw();
		
		usleep(stdconf::delay);
	}
}

//Helper functions
void SnakeGame::initWindow() {
	initscr(); 					//Initialize the screen
	nodelay(stdscr, true);
	keypad(stdscr, true); // initialise the keyboard: we can use arrows for directions
	noecho(); // user input is not displayed on the screen
	curs_set(0); // cursor symbol is not not displayed on the screen (Linux)
	getmaxyx(stdscr, maxheight, maxwidth); // define dimensions of game window
}

void SnakeGame::render() {
	ekans.draw();
}

const char* char2cstr(const char& c) {
	std::string str = {c};
	return str.c_str();

	//return std::string{c}.c_str();
	/*
		The above code also works but has
	   	a weird syntax LOL

		----------------------------------------------------

	   	History so that I never make the same mistake again:
	   	Before this function existed I used:

	   	(const char*)&c

	   	to convert from char to c str which doesn't work
	   	(probably because we don't have a null termination character)

	   	What happened was that it spit out random characters from memory
	   	we didn't own resulting in VERY strange behaviour:

		                      U@
                      U@
                 U@   U@
             U@  U@   U@       UUUUU@
             U@  U@   U@       U@  U@
             U@  U@   U@       U@  U@        UUUUUU@
             U@                                                oooooooO@
             U@       U@                     U@   U@
             U@                    U@        U@
             U@                              U@
             UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU@

		(Terminal output)

		The only thing supposed to be here is the snake: "oooooooO"
		The @s and Us should not be here xD
		   
		So there you have it! This took me several hours to figure out so
		I hope someone who finds this code in the future can benefit from this ;)
	*/
}