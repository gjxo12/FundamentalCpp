#ifndef __CLASSTEST__H
#define __CLASSTEST__H

namespace chapter6
{
    namespace classconversion
    {
        class CTestA
        {
        public:
            int m_Test;
        };
        class CTestB
        {
        public:
            int m_Test;
            // CTestB(const CTestA& obj) {}
        };
    }
}

#endif