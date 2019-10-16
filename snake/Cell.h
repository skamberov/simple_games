#ifndef CELL_H
#define CELL_H

#include<iostream>
#include<cassert>
#include<conio.h>
#include <stdio.h>
#include<time.h>
#include<Windows.h>
#define MAX_WIDTH 54
#define MAX_HEIGHT 18

using namespace std;

class Cell {
private:
	int x, y;
protected:
	char type;
public:
	Cell(int _x, int _y);
	virtual bool can_pass_through() = 0;
	int get_X()const;
	int get_Y()const;
	void print()const;
};

#endif
