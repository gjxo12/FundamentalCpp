/*
 * 값에 의한 호출은 오버헤드가 크다.. 값이 바뀌지 않도록 하기위해
 * 함수호출 후에 인자의 값이 유지되야 한다면.. 참조에 의한 호출이 필요
 */
#include <iostream>
namespace chapter7
{
    namespace callref
    {
        class Carg
        {
        public:
            Carg() { std::cout << "Carg Constructor....\n"; }
            Carg(const Carg &arg) { std::cout << "Carg Copy Constructor...\n"; }
            // 이 때 생성자는 몇번 호출될까..?
            int m_E;
            int m_V;
        };

        void Func(Carg &arg)
        {
            std::cout << "arg value...: " << arg.m_V << "\n";
            arg.m_V = 1;
        }

        int test_ref()
        {
            Carg a;
            a.m_V = 0;
            Func(a);
            // 클래스 객체가 객체 복사로 전달될때, 복사 생성자가 호출!!
            return 0;
        }

        /*
         * 호출스택이 어떻게 되는지 알면 좋음
         * 참조는 클래스 객체의 주소를 스택에 추가함:
         */

        //복사 손실
        class CParent{
            public:
            virtual void VFunc(){
                std::cout << "CParent::VFunc\n";
                std::cout << "m_Parent: " <<m_Parent << "\n";
            }
            int m_Parent;
        };
        class CChild : public CParent
        {
            public:
            virtual void VFunc()
            {
                std::cout << "CChild::VFunc" << "\n";
                std::cout << "m_Parent: " << m_Parent << "\n";
                std::cout << "m_Chiiild: " << m_Child << "\n";
            }
            int m_Child;
        };
        void vFunc(CParent arg) {arg.VFunc();}
        


    } // namespace callref

} // namespace chapter7