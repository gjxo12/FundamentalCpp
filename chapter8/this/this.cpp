#include "chapter8/this/this.h"
#include<iostream>

using chapter8::This::CChild;
using chapter8::This::CParent1;
using chapter8::This::CParent2;

int main()
{
    CChild* pC = new CChild;
    CParent2* pP2 = pC;

    pP2->VFunc2();
    // 어셈블리를 봐야하는데... 왜 CParent2의 주소가 대입될까?
    // 가상 함수 VFunc2 처음 선언된 CParnet2이기 때문
    // 처음으로 선언되었다는것은 실제 호출된 함수인 VFunc2가 속한 테이블을 가리키는 놈
    std::cout << pP2 << "\n";
    delete pC;
    // ===================================================================================

    CChild* pC2 = new CChild;
    pC2->VFunc2();
    // 위와 같다? 
    // 중요한것은 호출되는 험수가 처음 선언된 클래스 객체의 주소라는 사실
    // 바로 CChild!!
    std::cout << pC2 << "\n";
    delete pC2;
    return 0;
}