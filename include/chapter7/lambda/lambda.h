#ifndef __LAMBDA__
#define __LAMBDA__

#include <iostream>
#include <functional>

namespace chapter7
{
    namespace lambda
    {
        int foo();
        int bar();
        class CTest
        {
        public:
            int m_Value;
            int Func()
            {
                return [=](int arg) -> int
                {
                    return m_Value + arg;
                }(1);
                // 여기서 m_Value는..? 람다 본체에서는 전역, 지역(여기서는 this!), 외부 변수뿐...
                // 여기서 [=] -> [this] 이다! [&] [&this] 를 허용하지 않는다
            }
        };

        class CLambda
        {
        public:
            CLambda(int &vx, int &rx) : _vx(vx), _rx(rx) {}
            int operator()(int arg) // test와 같은 기능을 하는 Functor, operator를 재정의해서 람다와 같은 로직을 하도록 함
            {
                _rx = 10;
                return _vx + _rx + arg;
            }
            const int _vx;
            int &_rx;
        };
        void test();

        // 함수 저장
        void Func();
        // functional 헤더 사용
        void Functional();

    } // namespace lambda

} // namespace chapter7

#endif