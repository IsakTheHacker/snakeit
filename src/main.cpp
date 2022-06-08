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
	std::cout << "GAME OVER! Do you want to play again? [Y/n] ";
	std::string input;
	getline(std::cin, input);
	if (input == "Y" || input == "y" || input == "") {
		return true;
	} else {
		return false;
	}
}
