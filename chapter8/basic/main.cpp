#include <iostream>

class CParent
{
public:
    void Func()
    {
        std::cout << "CParent - Func\n";
    }
    virtual void VFunc() { std::cout << "CParent - VFunc\n"; }
    //보통 부모에 virtualdmf 하면 자식 클래스의 재정의도 항상 virtual
    int m_Parent;
};

class CChild : public CParent
{
public:
    void Func() { std::cout << "CChild - Func\n"; }
    virtual void VFunc() { std::cout << "CChild - VFunc\n"; }
    int m_Child;
};

int main()
{
    CParent* pParent = new CChild;
    // 개념이 햇갈릴수 있으니 잘 이해: CChild 객체를 생성해서 CParent* 타입으로 변환
    // 보통 실제 타입 객체가 생성되고 실제 객체를 다루기 위한 인터페이스 타입으로 변환해서 사용

    pParent->Func();
    pParent->VFunc();
    // 결과를 통해서 알수 있다..
    // 비가상 맴버함수는 인터페이스 타입 클래스인 Cparent에 정의된 Func 호출
    // 가상 맴버함수의 경우 실제 타입 클래스인 CCHild의 VFunc이 호출

    delete pParent;

}