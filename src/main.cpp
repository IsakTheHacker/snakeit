#include "snakegame.h"
#include <iostream>

#define YES true
bool askToPlayAgain();

int main(int argc, char* argv[]) {
	int exitStatus;
	do {
		SnakeGame game;
		exitStatus = game.play();
		if (exitStatus == 2) {
			//Exit the game
			break;
		}
	} while (askToPlayAgain() == YES);
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
