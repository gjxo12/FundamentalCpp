#ifndef __EQUAL__H
#define __EQUAL__H
#include<iostream>
namespace equal
{
    class CTest
    {
    public:
        CTest() {}
        CTest(int arg)
        {
            m_Val = arg;
        }
        void operator = (int arg)
        {
            m_Val = arg + 1;
        }

        bool operator== (const CTest a){
            std::cout << a.m_Val << "\n";
            return true;
        }
        int m_Val;
    };

} // namespace name

#endif
