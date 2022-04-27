#include "chapter6/inheritance/friend.h"
#include "chapter6/inheritance/staticmember.h"
#include "chapter6/inheritance/basicmember.h"
#include <iostream>

void basicMemberFunction()
{
    chapter6::inheritance::basicmember p1;
    p1.m_PVal = 1;

    chapter6::inheritance::basicmember p2;
    p2 = p1; // 복사 대입 연산자

    chapter6::inheritance::basicmember p3;
    p3 = 1; // 일반 대입 연산자

    chapter6::inheritance::basicmemberChild c1;
    c1.m_PVal=1;
    c1.m_CVal=2;

    chapter6::inheritance::basicmemberChild c2;
    c2 = c1; // 복사 대입..??

    chapter6::inheritance::basicmemberChild c3;
    c3 = 1;  // Why compile error..??
}

int main()
{
    CTestString ts = "abc";
    ts = ts + "def";
    std::cout << ts.c_str() << "\n";

    CTestString ts2 = "ABC";
    ts2 = "DEF" + ts2; // 연산자 앞에 붙은 인자는 암시적 변환이 절대 이루어지지 않는다.. 전위 연산자가 필요하다..
    std::cout << ts2.c_str() << "\n";

    std::cout << "=====================================================";

    CParent::s_Value = 1;
    CChild::s_Value = 2; // 이와 같이 상속된 정적 맴버 사용가능

    CParent::s2_Value = 1;
    CChild::s2_Value = 2;
    CChild::CParent::s2_Value = 3;
    // 두개가 존재한다고 생각

    std::cout << "=====================================================";

    basicMemberFunction();
}
