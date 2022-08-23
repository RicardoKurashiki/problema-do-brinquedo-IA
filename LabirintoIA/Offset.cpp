#include "Offset.h"

Offset::Offset() {
	x = y = 0;
}

Offset::Offset(int start_x, int start_y)
{
	x = start_x;
	y = start_y;
}

void Offset::move(char direction) 
{
	switch (direction)
	{
	case 'N':
		--x;
		path_x.push(x);
		path_y.push(y);
		break;
	case 'S':
		++x;
		path_x.push(x);
		path_y.push(y);
		break;
	case 'W':
		--y;
		path_x.push(x);
		path_y.push(y);
		break;
	case 'E':
		++y;
		path_x.push(x);
		path_y.push(y);
		break;
	default:
		break;
	}		
}

void Offset::undo() 
{
	x = path_x.top();
	y = path_y.top();
	path_x.pop();
	path_y.pop();
}