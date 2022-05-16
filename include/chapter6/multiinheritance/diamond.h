#ifndef __DIAMOND__H
#define __DIAMOND__H

#include <iostream>

namespace chapter6
{
    namespace diommond
    {
        class CTop
        {
        public:
            int m_Top;
        };

        class CMiddleA : public CTop
        {
        public:
            int m_MiddleA;
        };

        class CMiddleB : public CTop
        {
        public:
            int m_MiddleB;
        };

        class CBottom : public CMiddleA, public CMiddleB
        {
        public:
            CBottom(){
                //m_Top = 10; //Ctop이 중간 부모 둘에게 상속되고 중간부모는 CBottom에 상속되면서 CTop의 모든 맴버가 Bottom에 중복상속
                // 그래서 MiddleA냐 MiddleB냐 모호함
                CMiddleA::m_Top = 10; // 이렇게 모호한 것을 없애버리면 그만
                m_MiddleA = 21;
                m_MiddleB = 22;
                m_Bottom=30;
            }
            int m_Bottom;
        };
    }
}
#endif