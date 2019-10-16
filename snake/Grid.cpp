#include"Grid.h"

void Grid::copy(const Grid& other) {
	food = nullptr;
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			grid[i][j] = nullptr;
		}
	}
	int foodX = other.food->get_X();
	int foodY = other.food->get_Y();
	food = new Food(foodX, foodY);
	
	for (int i = 0; i < MAX_HEIGHT; i++) {
		grid[i][0] = new BorderCell(i, 0);
		grid[i][MAX_WIDTH - 1] = new BorderCell(i, MAX_WIDTH - 1);
	}
	for (int j = 1; j < MAX_WIDTH - 1; j++) {
		grid[0][j] = new BorderCell(0, j);
		grid[MAX_HEIGHT - 1][j] = new BorderCell(MAX_HEIGHT - 1, j);
	}
	int headX = other.snake.head()->get_X();
	int headY = other.snake.head()->get_Y();
	grid[headX][headY] = new SnakeHead(headX, headY);
	for (int i = 1; i < snake.get_size(); i++) {
		int x = other.snake.get_cell(i)->get_X();
		int y = other.snake.get_cell(i)->get_Y();
		grid[x][y] = new SnakeTail(x, y);
	}
	for (int i = 1; i < MAX_HEIGHT - 1; i++) {
		for (int j = 1; j < MAX_WIDTH - 1; j++) {
			if (grid[i][j] == nullptr) {
				grid[i][j] = new FreeCell(i, j);
			}
		}
	}
	delete grid[foodX][foodY];
	grid[foodX][foodY] = new Food(foodX, foodY);
}

void Grid::clear() {
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			if (grid[i][j] != nullptr) {
				delete grid[i][j];
				grid[i][j] = nullptr;
			}
		}
	}
}

Grid::Grid():food(nullptr) {
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			grid[i][j] = nullptr;
		}
	}
	set_grid();
}

Grid::~Grid() {
	clear();
	if (food != nullptr) {
		delete food;
		food = nullptr;
	}
}

Grid::Grid(const Grid& other):snake(other.snake) {
	copy(other);
}

Grid& Grid::operator=(const Grid& other) {
	if (this != &other) {
		snake = other.snake;
		clear();
		copy(other);
	}
	return *this;
}

Food* Grid::get_food()const {
	return food;
}

Cell* Grid::snake_tail_end()const {
	int tailX = snake.tail_end()->get_X();
	int tailY = snake.tail_end()->get_Y();
	return grid[tailX][tailY];
}

Cell* Grid::next() {
	int headX = snake.head()->get_X();
	int headY = snake.head()->get_Y();
	switch (snake.get_dir()) {
	case UP:return grid[headX - 1][headY];
	case LEFT:return grid[headX][headY - 1];
	case DOWN:return grid[headX + 1][headY];
	case RIGHT:return grid[headX][headY + 1];
	case STOP:return food;
	default:return grid[0][0];
	}
}

void Grid::set_food() {
	int x, y;
	do {
		x = rand() % MAX_HEIGHT;
		y = rand() % MAX_WIDTH;
	} while (!grid[x][y]->can_pass_through());
	if (food != nullptr) {
		delete food;
	}
	food = new Food(x, y);
	delete grid[x][y];
	grid[x][y] = new Food(x, y);
}

void Grid::set_grid() {
	bool eaten = false;
	int foodX, foodY;
	if (food != nullptr) {
		if (food->get_X() == snake.head()->get_X() &&
			food->get_Y() == snake.head()->get_Y()) {
			eaten = true;
		}
	}

	clear();

	int headX = snake.head()->get_X();
	int headY = snake.head()->get_Y();
	grid[headX][headY] = new SnakeHead(headX, headY);

	for (int i = 0; i < MAX_HEIGHT; i++) {
		if (i != headX || 0 != headY) {
			grid[i][0] = new BorderCell(i, 0);
		}
		if (i != headX || MAX_WIDTH - 1 != headY) {
			grid[i][MAX_WIDTH - 1] = new BorderCell(i, MAX_WIDTH - 1);
		}
	}

	for (int j = 1; j < MAX_WIDTH - 1; j++) {
		if (0 != headX || j != headY) {
			grid[0][j] = new BorderCell(0, j);
		}
		if (MAX_HEIGHT - 1 != headX || j != headY) {
			grid[MAX_HEIGHT - 1][j] = new BorderCell(MAX_HEIGHT - 1, j);
		}
	}

	for (int i = 1; i < snake.get_size(); i++) {
		int x = snake.get_cell(i)->get_X();
		int y = snake.get_cell(i)->get_Y();
		if (x != headX || y != headY) {
			grid[x][y] = new SnakeTail(x, y);
		}
	}

	for (int i = 1; i < MAX_HEIGHT - 1; i++) {
		for (int j = 1; j < MAX_WIDTH - 1; j++) {
			if (grid[i][j] == nullptr) {
				grid[i][j] = new FreeCell(i, j);
			}
		}
	}

	if (food == nullptr || eaten) {
		set_food();
	}
	else {
		foodX = food->get_X();
		foodY = food->get_Y();
		delete grid[foodX][foodY];
		grid[foodX][foodY] = new Food(foodX, foodY);
	}
}

void Grid::print_grid() {
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			grid[i][j]->print();
		}
		cout << endl;
	}
}