#ifndef __VCONSDES__
#define __VCONSDES__

#include <iostream>

namespace chapter8
{
    namespace vconsdes
    {
        //소멸자: 파괴자
        class CParent
        {
        public:
            virtual void Destructor() { delete this; }
            ~CParent() {}
        };
        class CChild : public CParent
        {
        public:
            virtual void Destructor() { delete this; }
            ~CChild() {}
        };
        // 파괴자의 개념을 보여주기 위해 임의로 작성
        // 소멸자를 가상함수로 지정할때 이렇게 파괴자를 가상 함수로 지정한다.
        // 그래서 VTable 항목에는 이 파괴자의 주소를 넣는다

        //생성자
        // vfptr은 선처리 영역의 부모 클래스 생성자 호출 하고 생성된다..
        // 그런데.. 그러면 부모 클래스도 선처리 하고 vfptr이 생기면..
        // 얘는 부모 클래스의 주소를 가리키지 않나..? 어떻게 자식을 가리킬까???

    }
}

#endif