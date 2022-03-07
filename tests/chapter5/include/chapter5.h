#ifndef __CHAPTER5__H
#define __CHAPTER5__H

#if _WIN32 || _WIN64
  #if _WIN64
    #define ENV64
  #else
    #define ENV32
  #endif
#endif

#include<time.h>
#include<iostream>

namespace chapter5{
    int Func(int arg[]);
    int Func2(int (&arg)[4]);
    int CustomRand(int count);
}
#endif