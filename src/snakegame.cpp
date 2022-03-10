#include "snakegame.h"

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
