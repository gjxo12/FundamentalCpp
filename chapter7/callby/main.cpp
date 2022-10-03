#include "chapter7/callby/callref.h"
#include "chapter7/callby/callvalue.h"

int Increase(const int &arg) { return arg + 1; }

int main()
{
    chapter7::callvalue::test_value();
    chapter7::callref::test_ref();

    std::cout << "copy loss..........................................\n";
    // copy loss....
    chapter7::callref::CChild c;
    c.m_Parent = 1;
    c.m_Child = 2;
    chapter7::callref::vFunc(c);
    // 여기서 함수 인자타입이 CChild가 아닌 CParent이다....
    // 가상함수인데.. 가상 함수 테이블을 통해 객체가 생성될때 이미 정해진다..
    // CChild::VFunc가 아닌 CParent인가...
    // 객체 복사이고 매개변수 arg는 CParent / 인자인 c는 Child
    // 여기서 복사 손실: m_Child는 복사불가 / 가상 함수 테이블 포인터인 vfptr 복사가 안됨..

    /*
     * 정리: 클래스 객체를 함수의 인자로 넘길 때는 가능하면 참조에 의한 호출을 사용
     * 클래스 객체는 가능한 참조에 의한 호출로 인자를 넘기는 것이 성능이나 효율적인 면에서 유리..
     */

    Increase(0);
    // 원래 참조 타입 인자는 객체의 주소를 넘기는것이라 상수를 인자로 넘길수 없다.
    // 참조 타입에 const를 추가함으로써 컴파일러는 상수를 위한 메모리 영역을 만들도록 함(쓰기 금지!)
    // 클래스도 마찬가지..
    chapter7::callref::FuncTest(0);
    // 컴파일러는 상수에 대해 비 const 참조 타입에 대해 허용하지 않는다!!
}