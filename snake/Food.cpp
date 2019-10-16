#include"Food.h"

Food::Food(int _x, int _y) :Cell(_x, _y) {
	assert(_x > 0 && _x < MAX_HEIGHT - 1);
	assert(_y > 0 && _y < MAX_WIDTH - 1);
	type = '*';
}

bool Food::can_pass_through() {
	return true;
}