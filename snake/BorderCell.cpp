#include"BorderCell.h"

BorderCell::BorderCell(int _x, int _y) :Cell(_x, _y) {
	assert(_x == 0 || _x == MAX_HEIGHT - 1 || _y == 0 || _y == MAX_WIDTH - 1);
	type = '#';
}

bool BorderCell::can_pass_through() {
	return false;
}