#ifndef __COPY3__H
#define __COPY3__H

#include <iostream>

namespace copy3
{
    class CTest
    {
    public:
        CTest() : m_RefVal(m_Val)
        {
            m_Val = 1;
            m_pInt = new int;
            *m_pInt = 2;
        }
        ~CTest()
        {
            if (m_pInt)
            {
                delete m_pInt;
            }
        }
        int m_Val;
        int &m_RefVal;
        int *m_pInt;
    };

} // namespace name

#endif
