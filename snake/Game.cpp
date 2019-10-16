#include"Game.h"

void Game::instructions() {
	cout << "Controls:" << endl;
	cout << "w - Start moving up" << "		";
	cout << "a - Start moving left" << endl;
	cout << "s - Start moving down" << "		";
	cout << "d - Start moving right" << endl;
	cout << "Space - Start/Stop moving" << endl;
}

Game::Game() :score(0) {}

void Game::start() {
	bool gameover = false;
	Direction old_dir = RIGHT;
	bool eaten = false;

	while (!gameover) {
		grid.set_grid();
		system("cls");
		instructions();
		grid.print_grid();
		cout << "Score: " << score << endl;

		if (_kbhit()) {
			char c = _getch();
			if (grid.snake.can_change_dir(c)) {
				grid.snake.change_dir(c, old_dir);
			}
		}

		if (grid.snake.get_dir() != STOP) {
			old_dir = grid.snake.get_dir();
		}

		if (!grid.next()->can_pass_through() &&
			grid.next() != grid.snake_tail_end()) {
			gameover = true;
		}

		if (eaten) {
			if (grid.snake.get_dir() != STOP) {
				grid.snake.enlarge();
				eaten = false;
				score += 100;
			}
		}
		else {
			switch (grid.snake.get_dir()) {
			case UP:grid.snake.move_up();
				break;
			case LEFT:grid.snake.move_left();
				break;
			case DOWN:grid.snake.move_down();
				break;
			case RIGHT:grid.snake.move_right();
				break;
			default:break;
			}
		}
		if (grid.get_food()->get_X() == grid.snake.head()->get_X() &&
			grid.get_food()->get_Y() == grid.snake.head()->get_Y()) {
			eaten = true;
		}
		Sleep(100);
	}

	grid.set_grid();
	system("cls");
	instructions();
	grid.print_grid();
	cout << "GAME OVER" << endl;
	cout << "Your score: " << score << endl;
}