#include "chapter7/externC/externC.h"


//void Func(int arg);
extern "C" void Func(int arg) {}

extern "C"
{
    void FuncA() {}
    void FuncB() {}
    void FuncC() {}
}
// 이렇게 괄호로 묵어서 사용하는데..
// 보통 헤더파일로 사용한다.