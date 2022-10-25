#include <iostream>
#include "chapter8/animal.h"
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

using chapter8::animal::CAnimal;
using chapter8::animal::CCat;
using chapter8::animal::CDog;
using chapter8::animal::CPig;

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

    CAnimal* pAnimal = NULL;
    
    pAnimal = new CPig;
    chapter8::animal::PlayAnimalSound(pAnimal);
    // 이런식으로 어떤 다른 동물이 추가되더라도 이 함수는 수정할 필요가 없다.
    // 미래에 추가될 어떤 클래스 타입에 대해 기존 ㅋ코드로 대응
    // 인터페이스(부모 클래스)로 사용하고 실제타입으로 다시 변환할 필요가 없다..

}