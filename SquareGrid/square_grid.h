/**
A grid of squared cells. It may be a rectangular grid.

0    1    2   . . . x
-------------------------
0 | 0,0  1,0  2,0 . . . x,0
1 | 0,1  1,1  2,1 . . . x,1
2 | 0,2  1,2  2,2 . . . x,2
. |
. |
y | 0,y  1,y  2,y . . . x,y

*/

#ifndef SQUAREGRID_SQUAREGRID_H_
#define SQUAREGRID_SQUAREGRID_H_

#include <vector>

#include <Cell.h>
#include <Coordinates.h>
#include <grid.h>

#ifdef SquareGrid_EXPORTS
#define SQUAREGRID_DLL_API __declspec(dllexport) 
#else
#define SQUAREGRID_DLL_API __declspec(dllimport) 
#endif

namespace SquareGridLib {
	enum SQUAREGRID_DLL_API Direction {
		kNorth,
		kEast,
		kSouth,
		kWest,
		kNorthEast,
		kSouthEast,
		kSouthWest,
		kNorthWest,
		kDirectionMax
	};

	class SQUAREGRID_DLL_API SquareGrid {
		unsigned int size_x_;
		unsigned int size_y_;
		bool linked_north_south_;
		bool linked_east_west_;
		std::vector<std::vector<SquareCell>> square_grid_;

		SquareCell* GetCellDirection(const Coordinates2 starting_coord, const Direction dir, const unsigned int count);
		void InitGrid();
		void RebaseCoordinates(int &x, int &y);

	public:
		SquareGrid();
		SquareGrid(const unsigned int x, const unsigned int y, const bool north_south, const bool east_west);
		virtual ~SquareGrid();
		SquareCell* GetCell(const Coordinates2 coordinates);
		SquareCell* GetCellNorth(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kNorth, count); };
		SquareCell* GetCellEast(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kEast, count); };
		SquareCell* GetCellSouth(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kSouth, count); };
		SquareCell* GetCellWest(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kWest, count); };
		SquareCell* GetCellNorthEast(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kNorthEast, count); };
		SquareCell* GetCellSouthEast(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kSouthEast, count); };
		SquareCell* GetCellSouthWest(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kSouthWest, count); };
		SquareCell* GetCellNorthWest(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kNorthWest, count); };
	};
}

#endif // SQUAREGRID_SQUAREGRID_H_