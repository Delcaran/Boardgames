/**
10x10 checkerboard with black-white pattern and white lower right corner
*/

#ifndef INTERNATIONALCHECKERBOARD_CHECKERNTERNATIONAL_H_
#define INTERNATIONALCHECKERBOARD_CHECKERNTERNATIONAL_H_

#include <grid.h>
#include <square_grid.h>
#include <checkerboard.h>

#ifdef InternationalCheckerboard_EXPORTS
#define INTERNATIONAL_CHECKERBOARD_DLL_API __declspec(dllexport) 
#else
#define INTERNATIONAL_CHECKERBOARD_DLL_API __declspec(dllimport) 
#endif

namespace SquareGridLib {
	class INTERNATIONAL_CHECKERBOARD_DLL_API InternationalCheckerboard 
		: public SquareGridLib::Checkerboard 
	{
	public:
		InternationalCheckerboard();
		~InternationalCheckerboard();
	};
}

#endif // INTERNATIONALCHECKERBOARD_CHECKERNTERNATIONAL_H_