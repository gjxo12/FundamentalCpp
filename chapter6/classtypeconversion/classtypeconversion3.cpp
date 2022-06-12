#include<iostream>
#include "chapter6/classtypeconversion/classconversion.h"


using chapter6::classconversion::CChild;
using chapter6::classconversion::CParent;

int classtypeconversion3()
{
    CChild c;
    c.m_Parent = 1;
    c.m_Child = 2;

    CParent &rp = c;
    CChild &rc = (CChild &)rp;
    
    std::cout << rc.m_Child << "\n";

    return 0;
}
