#ifndef OFFSET_H
#define OFFSET_H

#include <stack>

class Offset {
	int v, h;
	std::stack<char> path_v, path_h;

public:
	Offset();
	Offset(int start_v, int start_h);
	int getV() { return v; }
	int getH() { return h; }
	void move(char direction);
	void undo();
};

#endif
#pragma once