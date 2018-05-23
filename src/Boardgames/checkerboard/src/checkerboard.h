/**
Just a squared-cell pattern with alternate colors
*/

#ifndef CHECKERBOARD_CHECKERBOARD_H_
#define CHECKERBOARD_CHECKERBOARD_H_

#include <grid.h>
#include <square_grid.h>

#ifdef Checkerboard_EXPORTS
#define CHECKERBOARD_DLL_API __declspec(dllexport) 
#else
#define CHECKERBOARD_DLL_API __declspec(dllimport) 
#endif

namespace SquareGridLib {
	class CHECKERBOARD_DLL_API Checkerboard 
		: public SquareGrid 
	{
	public:
		Checkerboard();
		Checkerboard(const unsigned int size_x, const unsigned int size_y);
		virtual ~Checkerboard();
	};
}

#endif // CHECKERBOARD_CHECKERBOARD_H_