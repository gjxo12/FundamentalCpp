#include "chapter6/dynamiccast/dynamiccast2.h"

using chapter6::dynamiccast2::CParentA;
using chapter6::dynamiccast2::CParentB;
using chapter6::dynamiccast2::CChild;

int test_dynamic()
{
    {
        CChild c;
        CParentA* pA = dynamic_cast<CParentA*>(&c);
        CParentB* pB = dynamic_cast<CParentB*>(&c);
        // CChild* 에서 CParent로 간다. 합리적인가??
    }
    {
        CParentA a;
        CChild* pC1 = dynamic_cast<CChild*>(&a);

        CParentB b;
        CChild* pC2 = dynamic_cast<CChild*>(&b); // NULL
        // 위 상황과 반대이다. 가능한가??
    }
    {
        CChild c;
        CParentA* pA = &c; // 여기서 pA의 실제 타입은..? CParent*인가 CChild* 인가?

        CChild* pC = dynamic_cast<CChild*>(pA);
        CParentB* pB = dynamic_cast<CParentB*>(pA);
    }

    // dynamic cast는 런타임 타입 변환을 하는것으로 무조건 실행되어야 함
    // 실행시점에 변환 성공과 실패 여부가 결ㅈ정됨
    // 실패할 경우 포인터 타입일 때는 NULL, 참조 타입일 경우 bad_cast 예외 처리
}