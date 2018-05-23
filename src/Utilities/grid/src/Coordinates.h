#ifndef GRID_COORDINATES_H_
#define GRID_COORDINATES_H_

#include "common.h"

struct Coordinates {
	Coordinates() {};
	virtual ~Coordinates() {};
};

struct Coordinates2 : Coordinates {
	int x;
	int y;

	Coordinates2() : x(0), y(0) {};
	Coordinates2(int x, int y) : x(x), y(y) {};
	~Coordinates2() {};
};

struct Coordinates3 : Coordinates {
	int x;
	int y;
	int z;

	Coordinates3() : x(0), y(0), z(0) {};
	Coordinates3(int x, int y, int z) : x(x), y(y), z(z) {};
	~Coordinates3() {};
};

#endif // GRID_COORDINATES_H_