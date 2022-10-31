#ifndef __VFUNCCALL__
#define __VFUNCCALL__

#include <iostream>

namespace chapter8
{
    namespace vfuncCall
    {
        class CParent
        {
        public:
            virtual void VFunc()
            {
                std::cout << "CParent - VFunc"
                          << "\n";
            }
        };

        class CChild : public CParent
        {
        public:
            virtual void VFunc()
            {
                std::cout << "CChild - VFunc"
                          << "\n";
            }
        };

        class A
        {
        public:
            void Func()
            {
                VFunc();
                A::VFunc();
            }
            virtual void VFunc()
            {
                std::cout << "A :: VFunc"
                          << "\n";
            }
        };

        class B : public A
        {
        public:
            virtual void VFunc()
            {
                std::cout << "B::VFunc"
                          << "\n";
            }
        };

    }
}

#endif