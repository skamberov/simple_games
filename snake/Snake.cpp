#include"Snake.h"

void Snake::copy(const Snake& other) {
	snake = nullptr;
	capacity = other.capacity;
	size = other.size;
	dir = other.dir;
	for (int i = 0; i < capacity; i++) {
		snake[i] = nullptr;
	}
	*snake = new SnakeHead(MAX_HEIGHT / 2, MAX_WIDTH / 2);
	**snake = **other.snake;
	for (int i = 1; i < size; i++) {
		snake[i] = new SnakeTail(MAX_HEIGHT / 2, MAX_WIDTH / 2);
		*snake[i] = *other.snake[i];
	}
}

void Snake::del() {
	for (int i = 0; i < size; i++) {
		delete snake[i];
	}
	delete snake;
}

void Snake::resize() {
	capacity *= 2;
	SnakeCell** new_snake = new SnakeCell*[capacity];
	for (int i = 0; i < capacity; i++) {
		new_snake[i] = nullptr;
	}
	*new_snake = new SnakeHead(MAX_HEIGHT / 2, MAX_WIDTH / 2);
	**new_snake = **snake;
	for (int i = 1; i < size; i++) {
		new_snake[i] = new SnakeTail(MAX_HEIGHT / 2, MAX_WIDTH / 2);
		*new_snake[i] = *snake[i];
	}
	del();
	snake = new_snake;
}

Snake::Snake(): capacity(5), size(1), snake(nullptr), dir(STOP) {
	snake = new SnakeCell*[5];
	for (int i = 0; i < capacity; i++) {
		snake[i] = nullptr;
	}
	*snake = new SnakeHead(MAX_HEIGHT / 2, MAX_WIDTH / 2);
}

Snake::~Snake() {
	del();
}

Snake::Snake(const Snake& other) {
	copy(other);
}

Snake& Snake::operator=(const Snake& other) {
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}

int Snake::get_size()const {
	return size;
}

SnakeCell* Snake::head()const {
	return *snake;
}

SnakeCell* Snake::get_cell(int i)const {
	assert(i >= 0 && i < size);
	return snake[i];
}

SnakeCell* Snake::tail_end()const {
	return snake[size - 1];
}

void Snake::enlarge() {
	if (size == capacity) {
		resize();
	}
	size++;
	snake[size - 1] = new SnakeTail(MAX_HEIGHT / 2, MAX_WIDTH / 2);
	*snake[size - 1] = *snake[size - 2];
	for (int i = size - 2; i >= 2; i--) {
		*snake[i] = *snake[i - 1];
	}
	int x = head()->get_X();
	int y = head()->get_Y();
	delete snake[1];
	snake[1] = new SnakeTail(x, y);
	delete *snake;
	switch (dir) {
	case UP: *snake = new SnakeHead(x - 1, y);
		break;
	case LEFT: *snake = new SnakeHead(x, y - 1);
		break;
	case DOWN: *snake = new SnakeHead(x + 1, y);
		break;
	case RIGHT: *snake = new SnakeHead(x, y + 1);
		break;
	default:break;
	}
}

Direction Snake::get_dir()const {
	return dir;
}

bool Snake::can_change_dir(char s)const {
	switch (s) {
	case 'w':return dir != DOWN && dir != STOP;
	case 'a':return dir != RIGHT && dir != STOP;
	case 's':return dir != UP && dir != STOP;
	case 'd':return dir != LEFT && dir != STOP;
	case ' ':return true;
	default:return false;
	}
}

void Snake::change_dir(char s, Direction old_dir) {
	bool moving = false;
	if (dir != STOP) {
		moving = true;
	}
	switch(s) {
	case 'w':dir = UP;
		break;
	case 'a':dir = LEFT;
		break;
	case 's':dir = DOWN;
		break;
	case 'd':dir = RIGHT;
		break;
	case ' ':
		if (moving) {
			dir = STOP;
		}
		else {
			dir = old_dir;
		}
		break;
	default:break;
	}
}

void Snake::move_left() {
	for (int i = size - 1; i >= 1; i--) {
		*snake[i] = *snake[i - 1];
	}
	int x = head()->get_X();
	int y = head()->get_Y();
	delete *snake;
	*snake = new SnakeHead(x, y - 1);
}

void Snake::move_right() {
	for (int i = size - 1; i >= 1; i--) {
		*snake[i] = *snake[i - 1];
	}
	int x = head()->get_X();
	int y = head()->get_Y();
	delete *snake;
	*snake = new SnakeHead(x, y + 1);
}

void Snake::move_up() {
	for (int i = size - 1; i >= 1; i--) {
		*snake[i] = *snake[i - 1];
	}
	int x = head()->get_X();
	int y = head()->get_Y();
	delete *snake;
	*snake = new SnakeHead(x - 1, y);
}

void Snake::move_down() {
	for (int i = size - 1; i >= 1; i--) {
		*snake[i] = *snake[i - 1];
	}
	int x = head()->get_X();
	int y = head()->get_Y();
	delete *snake;
	*snake = new SnakeHead(x + 1, y);
}