#ifndef GRID_H
#define GRID_H
#include"BorderCell.h"
#include"FreeCell.h"
#include"Snake.h"
#include"Food.h"

class Grid {
private:
	Cell* grid[MAX_HEIGHT][MAX_WIDTH];
	Food* food;
	void copy(const Grid& other);
	void clear();
public:
	Snake snake;
	Grid();
	~Grid();
	Grid(const Grid& other);
	Grid& operator=(const Grid& other);

	Food* get_food()const;
	Cell* snake_tail_end()const;

	Cell* next();
	void set_food();
	void set_grid();
	void print_grid();
};

#endif
