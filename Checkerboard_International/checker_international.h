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

namespace InternationalCheckerboardLib {
  class INTERNATIONAL_CHECKERBOARD_DLL_API InternationalCheckerboard {
  public:
    InternationalCheckerboard();
    ~InternationalCheckerboard();
    void getCell();
  };
}

#endif // INTERNATIONALCHECKERBOARD_CHECKERNTERNATIONAL_H_