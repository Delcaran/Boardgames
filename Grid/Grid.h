#ifndef GRID_GRID_H_
#define GRID_GRID_H_

#include "Coordinates.h"

#ifdef Grid_EXPORTS // Grid_EXPORTS is added by cmake with add_library(Grid SHARED x.cpp y.cpp ...)
#define GRID_DLL_API __declspec(dllexport) 
#else
#define GRID_DLL_API __declspec(dllimport) 
#endif

namespace GridLib {
  class GRID_DLL_API Grid {
  public:
    Grid();
    virtual ~Grid();
    virtual void getCell() = 0;
  };
}

#endif // GRID_GRID_H_