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
  class SQUAREGRID_DLL_API SquareGrid {
	  unsigned int size_x_;
	  unsigned int size_y_;
	  bool linked_north_south_;
	  bool linked_east_west_;
	  std::vector<std::vector<SquareCell>> square_grid_;

	  void initGrid();
  public:
	  SquareGrid();
    SquareGrid(const unsigned int x, const unsigned int y, const bool north_south, const bool east_west);
    virtual ~SquareGrid();
	SquareCell* getCell(const Coordinates2 coordinates) const;
  };
}

#endif // SQUAREGRID_SQUAREGRID_H_