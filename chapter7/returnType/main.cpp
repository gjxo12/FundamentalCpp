#include "chapter7/returnType/returnType.h"

// 반환 타입으로 기본 타입을 사용할 경우,
// 반환값은 eax(rax)와 edx(rdx) 레지스터에 대입된다!

typedef int TARR[1];

TARR *FuncArr() // 함수는 배열을 반환할 수 없다.. TARR* 타입이 필요하다..
{
    int arg[1] = {0};
    return (TARR *)arg;
}

int &rFunc()
{
    int ret = 1;
    return ret;
}

int main()
{
    chapter7::returnType::CTest Func();
    chapter7::returnType::CTest2 Func2();

    // call by reference
    int r = rFunc(); // 혹시 int& r 이라면..? 반환 결과가 스택에 있다.. 이 경우 참조 타입 변수로 받아선 위험함!

    return 0;
}
