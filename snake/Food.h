#ifndef FOOD_H
#define FOOD_H
#include"Cell.h"

class Food :public Cell {
public:
	Food(int _x, int _y);
	bool can_pass_through();
};

#endif
