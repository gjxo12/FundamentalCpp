#ifndef __THIS__
#define __THIS__

namespace chapter8
{
    namespace This
    {
        class CParent1
        {
        public:
            virtual void VFunc1() {}
        };
        class CParent2
        {
        public:
            virtual void VFunc2() {}
        };
        class CChild : public CParent1, public CParent2
        {
            public:
            void FuncC(){
                void *p = this;
            }
            // 비가상 함수와 차이을 꼭 비교해보자..
            virtual void VFunc2()
            {
                void *p = this; // ecx -4
                // 가상함수일때, 해당 가상함수가 선언된 클래스의 주소가 넘어온다!!!
                // main 함수에서 어떤 객체로 되어있는지 봐라!!
                // 왜 -4로 대입되는지..
            }
        };
    }
}

#endif