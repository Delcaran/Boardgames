#ifndef GRID_COMMON_H_
#define GRID_COMMON_H_

#ifdef Grid_EXPORTS // Grid_EXPORTS is added by cmake with add_library(Grid SHARED x.cpp y.cpp ...)
#define GRID_DLL_API __declspec(dllexport) 
#else
#define GRID_DLL_API __declspec(dllimport) 
#endif

#endif // GRID_COMMON_H_