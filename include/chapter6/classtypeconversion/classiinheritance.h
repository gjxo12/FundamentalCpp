#ifndef __CLASSINHERITANCE__H
#define __CLASSINHERITANCE__H

namespace chapter6
{
    namespace classinheritance
    {
        class CParentA
        {
        public:
            CParentA() { m_Val = 1; }
            int m_Val;
        };

        class CParentB
        {
        public:
            CParentB() { m_Val = 2; }
            int m_Val;
        };

        class CChild : public CParentA, public CParentB
        {
        public:
            CChild() { m_Val = 3; }
            int m_Val;
        };

        /*
        다중 상속된 CChild의 메모리 구조가 어떻게 되어있는지 생각
        */
    }
}

#endif