/**
8x8 checkerboard with black-white pattern and white lower right corner

Despite its name, it's also used for checkers games.
*/

#ifndef CHESSBOARD_CHESSBOARD_H_
#define CHESSBOARD_CHESSBOARD_H_

#include <grid.h>
#include <square_grid.h>
#include <checkerboard.h>

#ifdef Chessboard_EXPORTS
#define CHESSBOARD_DLL_API __declspec(dllexport) 
#else
#define CHESSBOARD_DLL_API __declspec(dllimport) 
#endif

namespace SquareGridLib {
  class CHESSBOARD_DLL_API Chessboard : SquareGridLib::Checkerboard {
  public:
    Chessboard();
    ~Chessboard();
  };
}

#endif // CHESSBOARD_CHESSBOARD_H_