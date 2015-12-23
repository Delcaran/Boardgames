#ifndef CHESSBOARD_PIECES_H_
#define CHESSBOARD_PIECES_H_

#include <chessboard.h>

#include <string>

#ifdef Chessboard_EXPORTS
#define CHESSBOARD_DLL_API __declspec(dllexport) 
#else
#define CHESSBOARD_DLL_API __declspec(dllimport) 
#endif

namespace SquareGridLib {
	namespace ChessLib {
		class CHESSBOARD_DLL_API Piece
		{
		protected:
			SquareCell* position; // pointer to the SquareCell inside SquareGrid::square_grid_ vector
			std::string name;

		public:
			Piece();
			~Piece();
		};
	}
}

#endif // CHESSBOARD_PIECES_H_