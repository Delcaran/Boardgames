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

	class SQUAREGRID_DLL_API SquareGrid 
		: public GridLib::Grid
	{
		protected:
		unsigned int size_x_;
		unsigned int size_y_;
		bool linked_north_south_;
		bool linked_east_west_;
		std::vector<std::vector<SquareCell>> square_grid_;

		virtual SquareCell* GetCellDirection(const Coordinates2 starting_coord, const Direction dir, const unsigned int count);
		virtual void InitGrid();
		virtual void RebaseCoordinates(int &x, int &y);

	public:
		SquareGrid();
		SquareGrid(const unsigned int x, const unsigned int y, const bool north_south, const bool east_west);
		virtual ~SquareGrid();
		virtual SquareCell* GetCell(const Coordinates2 coordinates);
		virtual SquareCell* GetCellNorth(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kNorth, count); };
		virtual SquareCell* GetCellEast(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kEast, count); };
		virtual SquareCell* GetCellSouth(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kSouth, count); };
		virtual SquareCell* GetCellWest(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kWest, count); };
		virtual SquareCell* GetCellNorthEast(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kNorthEast, count); };
		virtual SquareCell* GetCellSouthEast(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kSouthEast, count); };
		virtual SquareCell* GetCellSouthWest(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kSouthWest, count); };
		virtual SquareCell* GetCellNorthWest(const Coordinates2 starting_coord, const unsigned int count) { return GetCellDirection(starting_coord, kNorthWest, count); };
	};
}

#endif // SQUAREGRID_SQUAREGRID_H_