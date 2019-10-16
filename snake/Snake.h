#ifndef SNAKE_H
#define SNAKE_H
#include"SnakeHead.h"
#include"SnakeTail.h"

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Snake {
private:
	SnakeCell** snake;
	int size, capacity;
	Direction dir;
	void copy(const Snake& other);
	void del();
	void resize();
public:
	Snake();
	~Snake();
	Snake(const Snake& other);
	Snake& operator=(const Snake& other);

	int get_size()const;
	SnakeCell* head()const;
	SnakeCell* get_cell(int i)const;
	SnakeCell* tail_end()const;
	void enlarge();

	Direction get_dir()const;
	bool can_change_dir(char s)const;
	void change_dir(char s, Direction old_dir);

	void move_left();
	void move_right();
	void move_up();
	void move_down();

};

#endif
