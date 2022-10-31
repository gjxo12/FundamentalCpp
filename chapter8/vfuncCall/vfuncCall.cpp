#include "chapter8/vfuncCall/vfuncCall.h"

using chapter8::vfuncCall::CParent;
using chapter8::vfuncCall::CChild;
using chapter8::vfuncCall::A;
using chapter8::vfuncCall::B;

int main()
{
    CChild c;

    CParent p1 =c;
    p1.VFunc();

    CParent& p2 = c;
    p2.VFunc();
    
    /**
     * // 왜 결과가 다른가???
     * 참조 타입의 경우 인터페이스는 CParent이지만, 실제 타입은 CChild이다.
     * p1은 실제타입도 CPaent이다.. 일반 객체 타입!!
     * p1은 스택에 새로 생성된 순수한 CPaent 객체일 뿐 -> 암시적 복사 생성자에 의해 객체 c의 일부 메모리 영역만 복사된것..
     * 근데.. 명시적 복사 생성자 없고 암시적 복사 생성자 인데.. 
     * c++은 기본 타입의 메모리 복사에 vfptr은 제외한다! 이는 vfptr이 복사될수 없다
     * 간혹, memcpy로 클래스 객체에서 부모 객체로 사용하는데.. vfptr이 복사되니 주의! 
     * 
     * 
     * 결론은 가상함수는 직접이나 간접이나 호출 가능: 방식은 가상함수 호출방식이다
     * 
     */

    B b;
    A* pA = &b;

    pA->Func(); 
    // 비가상 함수인 Func, 이 안에는 VFunc이 있는데 B::VFunc 부름 왜? -> 실제객체와 인터페이스 객체를 확인해보자 
    // 그리고 A::의 VFunc 부름

    pA->VFunc();
    pA->A::VFunc();
    //위 두개는 알거라 생각한다.
    

}