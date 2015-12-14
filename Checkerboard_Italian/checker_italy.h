/**
Chessboard with black lower right corner
*/

#ifndef ITALIANCHECKERBOARD_CHECKERITALY_H_
#define ITALIANCHECKERBOARD_CHECKERITALY_H_

#include <grid.h>
#include <square_grid.h>
#include <chessboard.h>
#include <checkerboard.h>

#ifdef ItalianCheckerboard_EXPORTS
#define ITALIAN_CHECKERBOARD_DLL_API __declspec(dllexport) 
#else
#define ITALIAN_CHECKERBOARD_DLL_API __declspec(dllimport) 
#endif

namespace SquareGridLib {
  class ItalianCheckerboard : SquareGridLib::Chessboard {
  public:
    ItalianCheckerboard();
    ~ItalianCheckerboard();
  };
}

#endif // ITALIANCHECKERBOARD_CHECKERITALY_H_