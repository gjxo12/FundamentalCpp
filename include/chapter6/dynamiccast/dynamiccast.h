#ifndef __DYNAMICCAST__H
#define __DYNAMICCAST__H

namespace chapter6
{
    namespace dynamiccast
    {
        class CParent
        {
        public:
            char m_Type;
        };

        class CChildA : public CParent
        {
        public:
            CChildA()
            {
                m_Type = 'A';
                m_ChildA = 1;
            }
            int m_ChildA;
        };
        class CChildB : public CParent
        {
        public:
            CChildB()
            {
                m_Type = 'B';
                m_ChildB = 2;
            }
            int m_ChildB;
        };

        int GetValue(CParent* pParent) // 인자가 부모 클래스의 포인터 타입
        {
            if(pParent->m_Type == 'A')
            {
                CChildA* pC = static_cast<CChildA*>(pParent);
                return pC->m_ChildA;
            }
            else if(pParent->m_Type == 'B')
            {
                CChildB* pC = static_cast<CChildB*>(pParent);
                return pC->m_ChildB;
            }
            return 0;
        }

    }
}
/*
 * 런타임 타입 정보를 사용하여 타입 변환을 하는 연산자: RTTI
 * 상속 관계에서 부모 클래스에서 자식 클래스의 타입 변환은 허용되지 않는다 -> classtypeconversion에서 확인했다.
 * 그런데.. 포인터 타입에서 부모 클래스에서 자식 클래스의 강제 타입 변환과 static_cast는 허용했다
 * 포인터는 왜 허용하는가..?
 */

#endif