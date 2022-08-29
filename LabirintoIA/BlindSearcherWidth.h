#pragma once

#include "Searcher.h"
#include "vector"

class BlindSearcherWidth : public Searcher
{
public:
	BlindSearcherWidth();
	void receiveContext(Context recContext);
	Coordinate makeMovement();
	void handle();
private:
	void removeLastMovement(Context& context, char move);
	std::vector<Context> lastContexts;
	char lastMov;
};

