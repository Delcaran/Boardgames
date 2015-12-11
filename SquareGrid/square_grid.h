#include <grid.h>

namespace SquareGridLib {
  class SquareGrid {
  public:
    SquareGrid();
    virtual ~SquareGrid();
    virtual void getCell() = 0;
  };
}
