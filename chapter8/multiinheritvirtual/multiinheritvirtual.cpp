#include "chapter8/multiinheritvirtual/multiinheritvirtual.h"
#include <iostream>

using chapter8::multiinheritvirtual::CChild;
using chapter8::multiinheritvirtual::CParent;
using chapter8::multiinheritvirtual::CParent1;
using chapter8::multiinheritvirtual::CParent2;
using chapter8::multiinheritvirtual::CParent3;
using chapter8::multiinheritvirtual::CParent4;
using chapter8::multiinheritvirtual::CChild2;

int main()
{
    CChild c;
    CChild *pChild = &c;
    CParent *pParent = pChild;
    // 이 두개의 포인터 변수의 메모리가 다를텐데..
    // 왜 다른지 꼭 이해해야한다
    std::cout << pChild << "  " << pParent << "\n";


    CChild2 c2;
    CChild2* pC = &c2;
    CParent1* p1 = pC;
    CParent2* p2 = pC;
    CParent3* p3 = pC;
    CParent4* p4 = pC;

    std::cout << pC << "  " << p1 << "  " << p2 << "  " << p3 << "  " << p4 << "\n";
    // 결과 생각해보기..
    // 메모리 구조가 상식을 깸.. 확실한건 vfptr이 가장 위.. 어떤 vfptr일까?
    // CChild2의 vfptr은 몇개일까? 가지고 있을까?
    // GCC도 똑같을까..? -> 중요한것은 main vfptr은 무조건 처음에 나타난다는것!!
    return 0;
}