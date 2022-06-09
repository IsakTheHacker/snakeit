#include "snakegame.h"

//Constructors and destructors
SnakeGame::SnakeGame() {
	initWindow();
	ekans = Snake(7, Direction::RIGHT);
	foodMgr = new FoodMgr(
		stdconf::amountFoodAtSameTime,
		stdconf::foodSpawnframePaddingTop,
		stdconf::foodSpawnframePaddingLeft,
		maxheight - stdconf::foodSpawnframePaddingBottom - 1,
		maxwidth - stdconf::foodSpawnframePaddingRight);
	collMgr = new CollMgr(0, 0, maxheight - 1, maxwidth);
}
SnakeGame::~SnakeGame() {
	deinitWindow();
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
			return 2;
		break;
		case ' ':
			//Pause
			Globals::isPaused = true;
			drawStatusbar(ekans);
			while (getch() != ' ');
			Globals::isPaused = false;
		break;
		}

		//Do processing
		foodMgr->generate(ekans);
		ekans.progress();
		if (foodMgr->checkIfEaten(ekans.getHead().y, ekans.getHead().x)) {
			ekans.lengthen(1);
		}
		if (stdconf::checkForSnakeSelfCollision && ekans.checkSelfCollision()) {
			//Collision happened, GAME OVER
			return 1;
		}
		if (stdconf::checkForSnakeWallCollision && collMgr->checkForCollision(ekans.getHead().y, ekans.getHead().x)) {
			//Collision happened, GAME OVER
			return 1;
		}

		//Render output
		drawStatusbar(ekans);
		ekans.draw();
		
		usleep(stdconf::delay);
	}
	return 0;
}

//Helper functions
void SnakeGame::initWindow() {
	setlocale(LC_ALL, "");
	initscr(); 					//Initialize the screen
	nodelay(stdscr, true);
	keypad(stdscr, true); // initialise the keyboard: we can use arrows for directions
	noecho(); // user input is not displayed on the screen
	curs_set(0); // cursor symbol is not not displayed on the screen (Linux)
	getmaxyx(stdscr, maxheight, maxwidth); // define dimensions of game window

	if (has_colors()) {
		start_color();
		init_pair(HEAD_PAIR, COLOR_BLUE, COLOR_BLACK);			//Head color pair
		init_pair(BODYPART_PAIR, COLOR_CYAN, COLOR_BLACK);		//Bodypart color pair
		init_pair(FOOD_PAIR, COLOR_RED, COLOR_BLACK);			//Food color pair
		init_pair(COFF_PAIR, COLOR_WHITE, COLOR_BLACK);			//Color OFF pair or Background color pair
		init_pair(STATUSBAR_PAIR, COLOR_BLACK, COLOR_WHITE);	//Statusbar pair
		Globals::supportsColor = true;
	}
}

void SnakeGame::deinitWindow() {
	setlocale(LC_ALL, "");
	nodelay(stdscr, false);
	clear();
	endwin();
}

void SnakeGame::drawStatusbar(const Snake& snake) {
	std::string lStr;
	if (Globals::isPaused)
		lStr += "Paused ";

	std::string rStr;
	rStr += "Snake length: ";
	rStr += std::to_string(snake.body.size());

	std::string filloutStr(maxwidth - lStr.size() - rStr.size(), ' ');
	SAFE_ATTRON(COLOR_PAIR(STATUSBAR_PAIR));
	mvprintw(maxheight-1, 0, (lStr + filloutStr + rStr).c_str());
	SAFE_ATTROFF(COLOR_PAIR(COFF_PAIR));
}
