#ifndef OFFSET_H
#define OFFSET_H

#include <stack>

class Offset {
	int x, y;
	std::stack<char> path_x, path_y;

public:
	Offset();
	Offset(int start_x, int start_y);
	int getX() { return x; }
	int getY() { return y; }
	void move(char direction);
	void undo();
};

#endif
#pragma once