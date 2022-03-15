#ifndef __CALL2__H
#define __CALL2__H

#include <iostream>
namespace call2
{
    class CParent
    {
    public:
        CParent() { m_pInt = new int; }
        ~CParent() { delete m_pInt; }
        int *m_pInt;
    };

    class CChild : public CParent
    {
    public:
        CChild() { *m_pInt = 99999; }
        ~CChild() { std::cout << "call2:: CChiled destructor... " << *m_pInt << "\n"; }
    };
} // namespace call2
#endif