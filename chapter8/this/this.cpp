#include "chapter8/this/this.h"
#include "chapter8/this/thunk.h"
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


    // 얘가 실제 객체임을 잘 알기
    // Cthunk는 인터페이스 타입으로 변환하여 사용가능
    chapter8::Thunk::CChild* Cthunk = new chapter8::Thunk::CChild;
    
    // 인터페이스 타입처럼 사용하는 일반적인 가상 함수 사용 방식
    chapter8::Thunk::CParent1* P1thunk = Cthunk;
    P1thunk->VFunc();
    P1thunk->VFunc1();

    
    chapter8::Thunk::CParent2* P2thunk = Cthunk;
    P2thunk->VFunc();   // 여기서 문제인데 땜빵코드가 필요하다.. 적당히 가감해서 P1thunk로 만들어버림: 어셈블리 확인
    P2thunk->VFunc2();
    
    // 메모리 구조가 어떻게 되어 가리키는지 잘 생각해보기
    // vfptr은 몇개인가? 2개
    // VTable1 과 VTable2 가 가리키는 함수는 각각 어떤 함수인가? 1은 VFunc과 VFunc1 2는 VFUNC과 VFunc2
    // P1thunk는 어떤 함수만 가리킬수 있는가? P2thunk는??? 
    // 기존에 계속 보던 메모리 그림에서는 CChild::VFunc() 이 호출될때 this 포인터가 문제이다.. 
    // 그래서 Thunk 코드가 필요하다. 떔빵코드

    delete Cthunk;

    return 0;
}