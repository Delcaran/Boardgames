#ifndef CHECKERBOARD_CHECKERBOARD_H_
#define CHECKERBOARD_CHECKERBOARD_H_

/**
Just a squared-cell pattern with alternate colors
*/

#include <grid.h>
#include <square_grid.h>

#ifdef Checkerboard_EXPORTS
#define CHECKERBOARD_DLL_API __declspec(dllexport) 
#else
#define CHECKERBOARD_DLL_API __declspec(dllimport) 
#endif

namespace CheckerboardLib {
  class CHECKERBOARD_DLL_API Checkerboard {
  public:
    Checkerboard();
    virtual ~Checkerboard();
    virtual void getCell() = 0;
  };
}

#endif // CHECKERBOARD_CHECKERBOARD_H_