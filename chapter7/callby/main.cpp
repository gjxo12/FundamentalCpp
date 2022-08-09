#include "chapter7/callby/callref.h"
#include "chapter7/callby/callvalue.h"

int main()
{
    chapter7::callvalue::test_value();
    chapter7::callref::test_ref();


    std::cout << "copy loss..........................................\n";
    //copy loss....
    chapter7::callref::CChild c;
    c.m_Parent = 1;
    c.m_Child = 2;
    chapter7::callref::vFunc(c);
    // 여기서 함수 인자타입이 CChild가 아닌 CParent이다....
    // 가상함수인데.. 가상 함수 테이블을 통해 객체가 생성될때 이미 정해진다..
    // CChild::VFunc가 아닌 CParent인가...
    // 객체 복사이고 매개변수 arg는 CParent / 인자인 c는 Child 
    // 여기서 복사 손실: m_Child는 복사불가 / 가상 함수 테이블 포인터인 vfptr 복사가 안됨..
}