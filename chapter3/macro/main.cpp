#include "../include/macro_A.h"
#include "../include/macro_B.h"
#include <stdio.h>
// 헤더파일에 조건부 컴파일
// macro_B.h의 define은 Main.cpp에서만 정의된다. -> 중복정의 방지

char* GetPlatform()
{
#ifdef _WIN32
  #ifdef _WIN64
    #ifdef _M_X64
        return "64BIT x64 Window!";
    #elif defined(_M_IA64)
        return "64bit IA64 Windows..!";
    #endif
  #elif defined(_M_IX86)
        return "32bit x86 windows..!";
  #endif
#else
    return "not windows system...";
#endif
}

int main()
{
    char* a = GetPlatform();
    printf("%s\n",a);
    return 0;
}