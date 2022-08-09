/*
 * 클래스의 경우에도 기본 타입과 마찬가지로 객체를 인자로 넘긴다.
 * 클래스 객체가 복사되어 인자로 넘긴다. -> 객체의 상태가 변경되지 않는다.
 */
#include <iostream>
namespace chapter7
{
    namespace callvalue
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

        void Func(Carg arg)
        {
            std::cout << "arg value...: " << arg.m_V << "\n";
            arg.m_V = 1;
        }

        int test_value()
        {
            Carg a;
            a.m_V = 0;
            Func(a);
            // 클래스 객체가 객체 복사로 전달될때, 복사 생성자가 호출!!
            return 0;
        }

        /*
         * 호출스택이 어떻게 되는지 알면 좋음
         */
    }
}