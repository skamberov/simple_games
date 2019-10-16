#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H
#include"SnakeCell.h"

class SnakeHead :public SnakeCell {
public:
	SnakeHead(int _x, int _y);
	bool can_pass_through();
};

#endif
