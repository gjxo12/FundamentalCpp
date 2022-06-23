#include "chapter6/dynamiccast/dynamiccast.h"

using chapter6::dynamiccast::CChildA;
using chapter6::dynamiccast::CChildB;
using chapter6::dynamiccast::CParent;


int main()
{
    CChildA ca;
    int VA = chapter6::dynamiccast::GetValue(&ca); // 자동으로 부모 클래스의 포인터 타입으로 변환됨

    CChildB cb;
    int VB = chapter6::dynamiccast::GetValue(&cb);

    CParent p;
    p.m_Type = 'A';
    int VP = chapter6::dynamiccast::GetValue(&p);
    // 여기를 보면, CParent객체에 대해서.. GetValue를 들어가면..
    // CChildA, CChildB 로 강제 자식으로 타입이 변환될텐데... Undefined Behavior
    // 그래서 CChildA CChildB 에 대해서만 타입 변환을 허용해 준다면..?
    // dynamic_cast 사용
}