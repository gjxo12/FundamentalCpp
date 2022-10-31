#ifndef __INHERITANCEVIRTUAL__
#define __INHERITANCEVIRTUAL__

#include <iostream>

namespace chapter8
{
    namespace inheritanceVitrual
    {
        class CParent // 클래스 정의의 시작
        {
        public:
            CParent() {} // 여기서 VTable을 가리킴
            virtual void VFunc()
            {
                std::cout << "CParent - VFunc"
                          << "\n";
            }
            int m_Parent;
        };

        class CChild : public CParent // 클래스 정의의 시작
        {
        public:
            CChild() {}          // 그다음 여기서 VTable을 가리킴 : 생성자 호출 원리를 기억할것..
            virtual void VFunc() // 가상함수 상속받으니 재정의한 CChild::VFunc() 주소가 들어감, 안하면 vfptr에 CCparent::VFunc 들어감
            {
                std::cout << "CChild - VFunc"
                          << "\n";
            }
            int m_Child;
        };

        class A
        {
        public:
            virtual void vfunc1() {}
            virtual void vfunc2() {}
            virtual void vfunc3() {}
            virtual void vfunc4() {}
        };
        class B : public A
        {
            virtual void vfunc2() {}
            virtual void vfunc4() {}
            virtual void vfunc5() {}
            virtual void vfunc6() {}
        };
        class C : public B
        {
            virtual void vfunc3() {}
            virtual void vfunc4() {}
            virtual void vfunc6() {}
            virtual void vfunc7() {}
        };
        /**
         *         간단하게 생각할 수 있다..
         *  A              B                C       
         * vfunc1    ---> A::vfunc1  ---> A::vfunc1
         * vfunc2    ---> B::vfunc2  ---> B::vfunc2
         * vfunc3    ---> A::vfunc3  ---> C::vfunc3
         * vfunc4    ---> B::vfunc4  ---> C::vfunc4
         *                B::vfunc5  ---> B::vfunc5
         *                B::vfunc6  ---> C::vfunc6
         *                                C::vfunc7
         * 
         * 
         * 
         * 
         *
         */

    }
}

#endif