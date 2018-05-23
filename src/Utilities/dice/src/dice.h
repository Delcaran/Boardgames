#ifndef DIE_DICE_H_
#define DIE_DICE_H_

#ifdef Die_EXPORTS
#define DIE_DLL_API __declspec(dllexport) 
#else
#define DIE_DLL_API __declspec(dllimport) 
#endif

namespace Utilities {
  DIE_DLL_API int rollDice(const unsigned int n = 1, const unsigned int f = 6, const int m = 0);
}

#endif // DIE_DICE_H_
