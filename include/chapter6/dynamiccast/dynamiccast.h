#ifndef __DYNAMICCAST__H
#define __DYNAMICCAST__H

namespace chapter6
{
    namespace dynamiccast
    {
        class CParent
        {
        public:
        virtual ~CParent(){}
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
            if(pParent->m_Type == 'A') // 각각 또 안에서는 부모 클래스 포인터 타입(CParent*) 에서 자식들로 또 변환됨...
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
            // 위와 같은 상황들 떄문에!! (자식 -> 부모 -> 자식 ) 그래서 강제 타입 변환이나 static_cast를 허용함
        }

        int GetValue2(CParent* pParent)
        {
            CChildA* pCA = dynamic_cast<CChildA*>(pParent);
            if(pCA)
            {
                return pCA->m_ChildA;
            }
            CChildB* pCB = dynamic_cast<CChildB*>(pParent);
            if(pCB)
            {
                return pCB->m_ChildB;
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
 * 
 * RTTI: run time에 타입 정보를 알게한다 -> 가상 함수 테이블에 데이터를 담도록, VS는 이 타입 정보 객체를 가상 함수 테이블에 넣었다.
 * 하위 호환성, 클래스의 구조는 안바뀌도록, 첫번째 이전에 포인터 공간을 만듬.
 * 그래서 사용할수 있는게 type_info의 typeid() name... 
 */

#endif