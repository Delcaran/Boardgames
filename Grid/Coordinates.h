#pragma once
struct Coordinates {
	Coordinates();
	virtual ~Coordinates();
};

struct Coordinates2 : Coordinates {
	int x;
	int y;

	Coordinates2();
	Coordinates2(int x, int y);
	~Coordinates2();
};

struct Coordinates3 : Coordinates {
	int x;
	int y;
	int z;

	Coordinates3();
	Coordinates3(int x, int y, int z);
	~Coordinates3();
};