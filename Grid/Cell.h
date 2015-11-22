#pragma once

#include "Coordinates.h"

class Cell {
public:
	Cell();
	virtual ~Cell();
	virtual Coordinates getCoordinates() = 0;
};

class SquareCell : Cell {
	Coordinates2 coordinates_;
public:
	SquareCell(int x, int y) : coordinates_(x, y) {};
};
