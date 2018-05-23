#ifndef GRID_CELL_H_
#define GRID_CELL_H_

#include "common.h"
#include "Coordinates.h"

class GRID_DLL_API Cell {
public:
	Cell() {};
	virtual ~Cell() {};
	virtual Coordinates coordinates() = 0;
};

class GRID_DLL_API SquareCell : Cell {
	Coordinates2 coordinates_;
public:
	SquareCell(int x, int y) : coordinates_(x, y) {};
	Coordinates coordinates() { return coordinates_; };
};

#endif // GRID_COORDINATES_H_
