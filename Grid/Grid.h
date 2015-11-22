#ifdef GRID_DLL_EXPORTS
#define GRID_DLL_API __declspec(dllexport) 
#else
#define GRID_DLL_API __declspec(dllimport) 
#endif

#include "Coordinates.h"

namespace GridLib {
  class Grid {
  public:
    Grid();
    virtual ~Grid();
    virtual void getCell() = 0;
  };
}
