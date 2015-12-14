#include "square_grid.h"

namespace SquareGridLib {
	SquareGrid::SquareGrid() 
		: size_x_(1), size_y_(1) 
	{ 
		initGrid(); 
	};

    SquareGrid::SquareGrid(unsigned int x, unsigned int y, const bool north_south = false, const bool east_west = false)
		: size_x_(x), size_y_(y), linked_north_south_(north_south), linked_east_west_(east_west) 
	{ 
		initGrid(); 
	};

	SquareGrid::~SquareGrid() {}

	void SquareGrid::initGrid() 
	{
		for(unsigned int x = 0; x < size_x_; ++x) {
			std::vector<SquareCell> new_column;
			for(unsigned int y = 0; y < size_y_; ++y) {
				SquareCell new_cell(x, y);
				new_column.push_back(new_cell);
			}
			square_grid_.push_back(new_column);
		}
	}

	// TODO: define CellOutOfBoundsException
	SquareCell* SquareGrid::getCell(const Coordinates2 coordinates) const 
	{
		SquareCell* cell = 0;
		int x = coordinates.x;
		if(linked_north_south_) {
			x %= size_x_;
			if(x > 0) {
				x -= 1;
			}
		} else {
			if(x < 0 || x >= static_cast<int>(size_x_)) {
				// throw exception
				return cell;
			}
		}

		int y = coordinates.y;
		if(linked_east_west_) {
			y %= size_y_;
			if(y > 0) {
				y -= 1;
			}
		} else {
			if(y < 0 || y >= static_cast<int>(size_y_)) {
				// throw exception
				return cell;
			}
		}

		return cell;
	}
}
