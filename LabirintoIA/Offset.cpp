#include "Offset.h"

Offset::Offset() {
	v = h = 0;
}

Offset::Offset(int start_v, int start_h)
{
	v = start_v;
	h = start_h;
}

void Offset::move(char direction) 
{
	switch (direction)
	{
	case 'N':
		--v;
		path_v.push(v);
		path_h.push(h);
		break;
	case 'S':
		++v;
		path_v.push(v);
		path_h.push(h);
		break;
	case 'W':
		--h;
		path_v.push(v);
		path_h.push(h);
		break;
	case 'E':
		++h;
		path_v.push(v);
		path_h.push(h);
		break;
	default:
		break;
	}		
}

void Offset::undo() 
{
	v = path_v.top();
	h = path_h.top();
	path_v.pop();
	path_h.pop();
}