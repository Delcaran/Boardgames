#include "square_grid.h"

namespace SquareGridLib {
	SquareGrid::SquareGrid() 
		: size_x_(1), size_y_(1) 
	{ 
		InitGrid(); 
	};

	SquareGrid::SquareGrid(unsigned int x, unsigned int y, const bool north_south = false, const bool east_west = false)
		: size_x_(x), size_y_(y), linked_north_south_(north_south), linked_east_west_(east_west) 
	{ 
		InitGrid(); 
	};

	SquareGrid::~SquareGrid() {}

	void SquareGrid::InitGrid() 
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

	/**
	All coordinates MUST BE 0-based.
	Size of board in a direction is MAX INDEX + 1
	*/
	void SquareGrid::RebaseCoordinates(int &x, int &y)
	{
		if(linked_north_south_) {
			x %= size_x_;
			if(x < 0) {
				x = size_x_ - x;
			}
		} else {
			if(x < 0 || x >= static_cast<int>(size_x_)) {
				throw GridLib::ExceptionCellOutOfBounds();
			}
		}

		if(linked_east_west_) {
			y %= size_y_;
			if(y < 0) {
				y = size_y_ - y;
			}
		} else {
			if(y < 0 || y >= static_cast<int>(size_y_)) {
				throw GridLib::ExceptionCellOutOfBounds();
			}
		}
	}

	SquareCell* SquareGrid::GetCell(const Coordinates2 coordinates) 
	{
		SquareCell* cell = 0;
		int x = coordinates.x;
		int y = coordinates.y;

		RebaseCoordinates(x, y);

		cell = const_cast<SquareCell*>(&square_grid_.at(x).at(y));

		return cell;
	}

	SquareCell* SquareGrid::GetCellDirection(const Coordinates2 starting_coord, const Direction dir, const unsigned int count)
	{
		SquareCell* cell = 0;
		int x = starting_coord.x;
		int y = starting_coord.y;

		switch(dir) {
		case kNorth:
			y -= count;
			break;
		case kEast:
			x += count;
			break;
		case kSouth:
			y += count;
			break;
		case kWest:
			x -= count;
			break;
		case kNorthEast:
			x += count;
			y -= count;
			break;
		case kSouthEast:
			x += count;
			y += count;
			break;
		case kSouthWest:
			x -= count;
			y += count;
			break;
		case kNorthWest:
			x -= count;
			y -= count;
			break;
		}

		RebaseCoordinates(x, y);

		cell = const_cast<SquareCell*>(&square_grid_.at(x).at(y));

		return cell;
	}
}
