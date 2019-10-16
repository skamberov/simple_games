#include "Cell.h"

Cell::Cell(int _x, int _y) :x(_x), y(_y) {}

int Cell::get_X()const {
	return x;
}

int Cell::get_Y()const {
	return y;
}

void Cell::print()const {
	cout << type;
}