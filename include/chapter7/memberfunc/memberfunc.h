#ifndef __MEMBERFUNC__
#define __MEMBERFUNC__

#include <iostream>
#include <map>

namespace chapter7
{
    namespace memberfunc
    {

        class CTest
        {
        public:
            CTest() { m_Val = 0; }
            void Set(int arg) const
            {
                // m_Val = arg; compile error...
            }
            void Func() const {}
            void Func0() {}
            void Func1()
            {
                Func0();
                std::cout << this << "\n";
            }
            void Func2()
            {
                Func0();
                std::cout << this << m_Value << "\n";
            }
            virtual void vFunc() {}
            static void sFunc()
            {
                // std::cout << this << "\n"; compile error..
            }

            void constFunc() {std::cout << "non const FUnction...\n"; }
            void constFunc() const {std::cout << "Const Func....\n";}

            int m_Value;
            int m_Val;
        };

        class Cparent
        {
        public:
            void Func1() {}
            void Func(int arg) { std::cout << "int!!"
                                           << "\n"; }
        };

        class CChild : public Cparent
        {
        public:
            void Func1(int arg) {}
            void Func(double arg) { std::cout << "double!!"
                                              << "\n"; }
        };

        class ConstError
        {
            public:
            ConstError() {m_Val = 0;}
            void Func() {}
            //void Func1() const {Func();}   // error
            //ConstError& Func2() const {return *this;}  // error
            //ConstError* Func3() const {return this;}  // error
            //객체 자신 혹은 포인터 반환은 안됨

            const ConstError& Func4() const {return *this;}
            const ConstError* Func5() const {return this;}
            // const 타입으로 반환해야 가능함
            int m_Val;
        };

        class NeedConst
        {
            public:
            NeedConst() {m_Val=0;}
            virtual void VFunc() {m_Val=1;}

            int m_Val;
        };
        class ChildConst : public NeedConst
        {
            virtual void VFunc() {}
        };

    } // namespace memberfunc

} // namespace chapter7

#endif