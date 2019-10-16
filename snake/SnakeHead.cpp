#include"SnakeHead.h"

SnakeHead::SnakeHead(int _x, int _y) :SnakeCell(_x, _y) {
	assert(_x >= 0 && _x <= MAX_HEIGHT - 1);
	assert(_y >= 0 && _y <= MAX_WIDTH - 1);
	type = 'O';
}

bool SnakeHead::can_pass_through() {
	return false;
}