#include "chapter8/multiinheritvirtual/multiinheritvirtual.h"
#include <iostream>

using chapter8::multiinheritvirtual::CChild;
using chapter8::multiinheritvirtual::CParent;

int main()
{
    CChild c;
    CChild *pChild = &c;
    CParent *pParent = pChild;
    // 이 두개의 포인터 변수의 메모리가 다를텐데..
    // 왜 다른지 꼭 이해해야한다
    std::cout << pChild << "  " << pParent << "\n";

    return 0;
}