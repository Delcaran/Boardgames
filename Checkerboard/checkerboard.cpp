#include "checkerboard.h"

namespace SquareGridLib {
  Checkerboard::Checkerboard() 
	  : SquareGrid(8, 8, false, false)
  {};

  Checkerboard::Checkerboard(const unsigned int size_x, const unsigned int size_y)
	  : SquareGrid(size_x, size_y, false, false)
  {};

  Checkerboard::~Checkerboard() {}
}
