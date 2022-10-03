/*
* 클래스 맴버로서 속성과 함께 일반 함수의 특징을 가진다.
* 맴버 함수는 다른 전역 함수와 마찬가지로 코드 영역에 있다.
* 이들은 지정된 범위 안에서만 호출될수 있다.

thiscall: 맴버 함수의 필수 인자인 this를 넘기는 규칙이 포함된 함수 호출 규약
비정적 맴버 함수에 대해서는 보통 thsicall, x64는 다 통합됨
보통 ecx, rcx 레지스터를 이용해 this를 넘시는것이 일반적
맴버 함수 호출시에는 객체의 주소를 전달해야한다.
*/

#include "chapter7/memberfunc/memberfunc.h"

using chapter7::memberfunc::CChild;
using chapter7::memberfunc::ChildConst;
using chapter7::memberfunc::Cparent;
using chapter7::memberfunc::CTest;
using chapter7::memberfunc::NeedConst;

int main()
{
    CTest *pT = nullptr; // this는 NULL
    pT->Func1();
    // pT->Func2(); // runtime error.. m_Value 접근..
    pT->vFunc();
    // vFunc가 가상함수로 인해 vfptr 가상 함수 테ㅔ이블을 가리티는 포인터를 맴버로 가지게됨
    // 호출할때 무조건 vfptr을 참조하므로 this가 잘못될 경우..? 예외..
    // 가상 함수는 vfptr을 참조함으로 비정적 맴버 함수만 가능: static과 양립할수 없다...

    CChild c;
    c.Func1(1);
    // c.Func1(); why this code is commpile error??

    c.Func(1);            // 이것은 CChild이 Func()이다. 가까운 범위 내에서 함수를 찾는다
    c.Cparent::Func(1.0); // 이렇게. 부모::함수이름 으로 사용할수 있다!!!

    const CTest ct;
    ct.Func(); // const 맴버 함수는 모든 객체에 대해 호출 가능

    CTest t;
    t.Func(); // 비 const 맴버 함수는 비 const 객체만 호출 가능

    // const ChildConst c;
    // const NeedConst* pP = &c;
    // pP->VFunc();
    // compile error.. 런타임시점에 결정되는 가상함수는 가상함수 장에서..

    t.constFunc();
    ct.constFunc();
    // 어떤것을 호출할지 쉽게 알수있음.

    // STL 만들어보기
    std::map<CTest, CTest *> test_map;
    CTest ttt;
    test_map[ttt] = &t;

    /**
     * const: 클래스 객체는 절대로 맴버가 변경되어선 안된다..
     * 그래서 const 맴버 함수만 호출 가능
     * const 맴버 함수를 정의할 경우에는 코드 변경 가능성 있는 코드는 단연 컴파일 에러
     * const 키워드가 가상함수에서 꽤 필요: 가상함수 장에서..
     * STL 호환 클래스에서 const 맴버 함수가 필요할수 있다...
     */
}
