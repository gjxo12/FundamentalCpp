#include "chapter6\classtypeconversion\classconversion.h"

using chapter6::classconversion::CParent;
using chapter6::classconversion::CChild;

int classtypeconversion2()
{
    CChild c;
    c.m_Parent = 1;
    c.m_Child = 2;

    CParent p1 = c;
    CParent p2 = (CParent)c;
    CParent p3 = static_cast<CParent>(c);
    CParent p4 = reinterpret_cast<CParent>(c); // 얘는 값타입 변환을 허용하지 않음! 얘는 포인터!!

    CParent p;
    p.m_Parent = 1;

    CChild c1 = p;
    CChild c2 = (CChild)p;
    CChild c3 = static_cast<CChild>(p);
    CChild c4 = reinterpret_cast<CChild>(p);
    // 자식 클래스에서 부모 클래스로 타입 변환은 허용하지만
    // 부모 클래스에서 자식 클래스로의 변환은 허용하지 않는다..
    // 상식적으로 생각하면 쉬움.. 부모 클래스를 자식으로 변환할때.. 과연 
    // 자식의 맴버들에 대해 가지고 있는가..?

    CChild c;
    c.m_Parent = 1;
    c.m_Child = 2;

    CParent& rp1 = c;
    CParent& rp2 = (CParent)c;
    CParent& rp3 = static_cast<CParent>(c);
    CParent& rp4 = reinterpret_cast<CParent>(c); 

    CParent p;
    p.m_Parent = 1;

    CChild& rc1 = p;                        //error
    CChild& rc2 = (CChild&)p;                // 물론 아래 3개도 결과는 보증하지 않지만 컴파일은 OK
    CChild& rc3 = static_cast<CChild&>(p);
    CChild& rc4 = reinterpret_cast<CChild&>(p);
    // 이렇게 참조타입으로 하면 p가 차지하는 메모리 영역을 확장하여 CChild 객체로 만듬
    // 확장되면서 m_Child 영역이 불문명하다.
    // 즉, undeifned Behavior


    CChild c;
    c.m_Parent = 1;
    c.m_Child = 2;
    
    CParent& rp = c;
    CChild& rc = (CChild&) rp;
    // 클래스 간 타입 변환은 값 타입 변환과 참조 타입 변환
    // 값 타입 변환은 임시 객체가 생성, 참조는 기존 객체의 메모리 영역이 그대로 재활용
    // 부모 클래스 -> 자식으로ㅗ 타입 변환할때 참조 타입은 가능한데...
    // static cast는 상속관계에서! reinterpreter cast는 참조나 포인터 타입 변환만!! 

    return 0;
}
