/**
12x12 checkerboard with black-white pattern and white lower right corner
*/

#ifndef CANADIANCHECKERBOARD_CHECKERCANADA_H_
#define CANADIANCHECKERBOARD_CHECKERCANADA_H_

#include <grid.h>
#include <square_grid.h>
#include <checkerboard.h>

#ifdef CanadianCheckerboard_EXPORTS
#define CANADIAN_CHECKERBOARD_DLL_API __declspec(dllexport) 
#else
#define CANADIAN_CHECKERBOARD_DLL_API __declspec(dllimport) 
#endif

namespace SquareGridLib {
	class CANADIAN_CHECKERBOARD_DLL_API CanadianCheckerboard 
		: public SquareGridLib::Checkerboard
	{
	public:
		CanadianCheckerboard();
		~CanadianCheckerboard();
	};
}

#endif // CANADIANCHECKERBOARD_CHECKERCANADA_H_