#ifndef __INITREF__H
#define __INITREF__H

namespace InitRef // 상수 타입과 래퍼런스 타입은 초기화 리스트를 사용해야함
{
    class CParent
    {
        public:
        CParent() : m_Val(1), m_Ref(m_Val), m_CVal(7)
        {
            m_Val = 1;
            m_Ref = m_Val;
            m_CVal = 7;
            //가장 처음엠만 초기화하는 애들
            // 선처리 영역에서 이미 초기화가 진행된다....
        }
        int m_Val;
        int& m_Ref;
        const int m_CVal;
    };

} // namespace name

#endif
