#pragma once

#include <stack>

class Coordinate
{
public:
	Coordinate();
	Coordinate(int startLine, int starColumn);
	int getLine() { return m_line; }
	int getColumn() { return m_column; }
	void move(char direction);
private:
	int m_line;
	int m_column;
};

