#ifdef Grid_EXPORTS // Grid_EXPORTS is added by cmake with add_library(Grid SHARED x.cpp y.cpp ...)
#define GRID_DLL_API __declspec(dllexport) 
#else
#define GRID_DLL_API __declspec(dllimport) 
#endif

#include "Coordinates.h"

namespace GridLib {
  class GRID_DLL_API Grid {
  public:
    Grid();
    virtual ~Grid();
    virtual void getCell() = 0;
  };
}
