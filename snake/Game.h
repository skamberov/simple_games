#ifndef GAME_H
#define GAME_H
#include"Grid.h"

class Game {
private:
	Grid grid;
	int score;
	void instructions();
public:
	Game();

	void start();
};

#endif
