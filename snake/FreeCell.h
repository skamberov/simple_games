#ifndef FREECELL_H
#define FREECELL_H
#include"Cell.h"

class FreeCell:public Cell {
public:
	FreeCell(int _x, int _y);
	bool can_pass_through();
};

#endif