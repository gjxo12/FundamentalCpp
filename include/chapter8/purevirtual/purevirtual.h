#ifndef __PUREVIRTUAL__
#define __PUREVIRTUAL__

#include <iostream>

namespace chapter8
{
    namespace purevirtual
    {
        class CTest
        {
        public:
            virtual void VFunc() = 0;
        };
        class CChildA : public CTest
        {
        public:
            virtual void VFunc() { std::cout << "ChildA..: \n"; }
        };
        class CChildB : public CTest
        {
        public:
            virtual void VFunc() { std::cout << "ChildB..: \n"; }
        };

        class CParent
        {
        public:
            CParent() { Func(); }
            void Func() { VFunc(); }
            virtual void VFunc() = 0;
        };
        class CChild : public CParent
        {
            public:
            virtual void VFunc() {std::cout << "CChild::VFunc..\n";}
        };
    }

}

#endif