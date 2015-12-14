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

namespace ChessboardLib {
  class CHESSBOARD_DLL_API Chessboard {
  public:
    Chessboard();
    ~Chessboard();
    void getCell();
  };
}

#endif // CHESSBOARD_CHESSBOARD_H_