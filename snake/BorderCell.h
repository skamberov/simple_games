#ifndef BORDERCELL_H
#define BORDERCELL_H
#include"Cell.h"

class BorderCell :public Cell {
public:
	BorderCell(int _x, int _y);
	bool can_pass_through();
};

#endif
