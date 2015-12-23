#ifndef DIE_DICE_H_
#define DIE_DICE_H_

#ifdef Die_EXPORTS
#define DIE_DLL_API __declspec(dllexport) 
#else
#define DIE_DLL_API __declspec(dllimport) 
#endif

namespace Utilities {
	DIE_DLL_API bool init();
	DIE_DLL_API unsigned int roll(const unsigned int f);
	DIE_DLL_API unsigned int roll(const unsigned int n, const unsigned int f);
	DIE_DLL_API int roll(const unsigned int n, const unsigned int f, const int m);
}

#endif // DIE_DICE_H_
