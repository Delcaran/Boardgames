#ifndef SQUAREGRID_SQUAREGRID_H_
#define SQUAREGRID_SQUAREGRID_H_

#include <grid.h>

#ifdef SquareGrid_EXPORTS
#define SQUAREGRID_DLL_API __declspec(dllexport) 
#else
#define SQUAREGRID_DLL_API __declspec(dllimport) 
#endif

namespace SquareGridLib {
  class SQUAREGRID_DLL_API SquareGrid {
  public:
    SquareGrid();
    virtual ~SquareGrid();
    virtual void getCell() = 0;
  };
}

#endif // SQUAREGRID_SQUAREGRID_H_