#ifndef SNAKETAIL_H
#define SNAKETAIL_H
#include"SnakeCell.h"

class SnakeTail :public SnakeCell {
public:
	SnakeTail(int _x, int _y);
	bool can_pass_through();
};

#endif