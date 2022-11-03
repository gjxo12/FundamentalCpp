#include "chapter8/vconsdes/vconsdes.h"

using chapter8::vconsdes::CParent;
using chapter8::vconsdes::CChild;

void test()
{
    CParent* pParent = new CParent;
    delete pParent;

    CParent p;
    // 두개의 CParent 객체의 생성: 하나는 힙에 다른 하나는 스택으로 갈것임
    // 이 두개 모두 소멸자는 호출한다. 힙에서는 destructor -> ~CParent이고 스택은 ~CParent가 바로 호출됨
    // delete -> 파괴자 -> 소멸자 순서
    // 컴파일러는 모든 클래스에 대해 파괴자를 맴버 함수로서 암시적으로 가짐 -> 소멸자를 호출하게한다

}

int main()
{
    return 0;
}