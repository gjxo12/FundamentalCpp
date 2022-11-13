#ifndef __VCONSDES__
#define __VCONSDES__

#include <iostream>

namespace chapter8
{
    namespace vconsdes
    {
        // 소멸자: 파괴자
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

        // 생성자
        //  vfptr은 선처리 영역의 부모 클래스 생성자 호출 하고 생성된다..
        //  그런데.. 그러면 부모 클래스도 선처리 하고 vfptr이 생기면..
        //  얘는 부모 클래스의 주소를 가리키지 않나..? 어떻게 자식을 가리킬까???
        //  자식 클래스의 선처리 영역: 부모 클래스 생성자 호출 -> (vfptr이 설정, 초기화) -> 맴버 클래스의 생성자
        class ConsParent
        {
        public:
            ConsParent() { VFunc(); }
            ~ConsParent()
            {
                VFunc();
            }
            virtual void VFunc()
            {
                std::cout << "ConsParent::VFucn... \n";
            }
        };
        class ConsChild : public ConsParent
        {
        public:
            ConsChild() {}
            ~ConsChild() {}
            virtual void VFunc()
            {
                std::cout << "ConsChild::VFunc....\n";
            }
        };
        // 처음에 ConsCparent의 VTable 설정 -> ConsChild의 VTable이 다시 설정
        // ConsChild의 생성자 본체가 실행될때 VTable이 어떤 주소를 가리키는지 생각해보자
        // ConsParent의 생성자 본체가 시작될때, ConsChild의 본체나 생성자는 시작됐는가?

        // 소멸자는 어떻게 되는지 생각해보자.
        // 1. 멸자 블록 시작: ConsChild의 vfptr 설정 및 처리 -> ConsChild 후처리 영역 시작
        // 2. ConsParent의 소멸자 호출...
        // 3. 후처리.. 
        // 소멸자도 생성자와 마찬가지로 가상함수는 마치 비가상 맴버함수처럼 호출됨
    }
    /**
     * 정리.. 생성자나 소멸자에서 호출하는 가상 함수는 비가상 맴버함수처럼 호출된다!!
     * 
     */

}

#endif