#ifndef GRID_GRID_H_
#define GRID_GRID_H_

#include "common.h"
#include "Cell.h"
#include "Coordinates.h"

#include <exception>
#include <vector>
#include <string>

namespace GridLib {
	class GRID_DLL_API Grid {
	public:
		Grid() {};
		virtual ~Grid() {};
		virtual void getCell() = 0;
	};

	class GRID_DLL_API ExceptionCellOutOfBounds {};
}

#endif // GRID_GRID_H_