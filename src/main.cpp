#include "snakegame.h"
#include <iostream>

bool askToPlayAgain();

int main(int argc, char* argv[]) {
	int exitStatus;
	do {
		SnakeGame game;
		exitStatus = game.play();
	} while (askToPlayAgain() && exitStatus != 0);
	return 0;
}

bool askToPlayAgain() {
	std::cout << "GAME OVER! Do you want to play again? [y/n] ";
	std::string input;
	std::cin >> input;
	if (input == "Y" || input == "y") {
		return true;
	} else {
		return false;
	}
}
