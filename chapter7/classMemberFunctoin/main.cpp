/*
* 클래스 맴버로서 속성과 함께 일반 함수의 특징을 가진다.
* 맴버 함수는 다른 전역 함수와 마찬가지로 코드 영역에 있다.
* 이들은 지정된 범위 안에서만 호출될수 있다.

thiscall: 맴버 함수의 필수 인자인 this를 넘기는 규칙이 포함된 함수 호출 규약
비정적 맴버 함수에 대해서는 보통 thsicall, x64는 다 통합됨
보통 ecx, rcx 레지스터를 이용해 this를 넘시는것이 일반적
맴버 함수 호출시에는 객체의 주소를 전달해야한다.
*/

#include<iostream>

class CTest
{
public:
    void Func0() {}
    void Func1() {
        Func0();
        std::cout << this << "\n";
    } 
    void Func2() {
        Func0();
        std::cout << this << m_Value << "\n";
    }
    virtual void vFunc() {}
    static void sFunc() { 
        //std::cout << this << "\n"; compile error..
    }
    int m_Value;
};

int main()
{
    CTest* pT = nullptr; // this는 NULL
    pT->Func1();
    //pT->Func2(); // runtime error.. m_Value 접근..
    pT->vFunc(); 
    // vFunc가 가상함수로 인해 vfptr 가상 함수 테ㅔ이블을 가리티는 포인터를 맴버로 가지게됨
    // 호출할때 무조건 vfptr을 참조하므로 this가 잘못될 경우..? 예외..
    // 가상 함수는 vfptr을 참조함으로 비정적 맴버 함수만 가능: static과 양립할수 없다...
}

