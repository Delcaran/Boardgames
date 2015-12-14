#ifndef ITALIANCHECKERBOARD_CHECKERITALY_H_
#define ITALIANCHECKERBOARD_CHECKERITALY_H_

#include <grid.h>
#include <square_grid.h>
#include <checkerboard.h>

#ifdef ItalianCheckerboard_EXPORTS
#define ITALIAN_CHECKERBOARD_DLL_API __declspec(dllexport) 
#else
#define ITALIAN_CHECKERBOARD_DLL_API __declspec(dllimport) 
#endif

namespace ItalianCheckerboardLib {
  class ItalianCheckerboard {
  public:
    ItalianCheckerboard();
    ~ItalianCheckerboard();
    void getCell();
  };
}

#endif // ITALIANCHECKERBOARD_CHECKERITALY_H_