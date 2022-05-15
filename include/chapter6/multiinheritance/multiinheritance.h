#ifndef __MULTIINHERITANCE__H
#define __MULTIINHERITANCE__H

#include <iostream>

namespace chapter6
{
    namespace multiinheritance
    {
        class CParentA
        {
        public:
            CParentA() { m_AVal = 1; }
            int GetAVal() { return m_AVal; }

            int m_AVal;
        };

        class CParentB
        {
        public:
            CParentB() { m_BVal = 2; }
            int GetBVal() { return m_BVal; }
            int m_BVal;
        };


        class CChild : public CParentA, public CParentB
        {
        public:
            CChild() { m_CVal = 3; }
            int GetCVal() { return m_CVal; }

            int m_CVal;
        };
        // 다중 상속의 경우 두 번쨰 부모클래스부터 시작 주소가 자식 클래스의 주소와 일치하지 않는다!!!
         // 물론 첨인 CChile와 CParentA는 같다. 
    }
}
#endif