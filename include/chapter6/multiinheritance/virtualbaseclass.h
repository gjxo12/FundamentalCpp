#ifndef __VIRTUALBASECLASS__H
#define __VIRTUALBASECLASS__H

#include <iostream>

namespace chapter6
{
    namespace virtualbaseclass
    {
        class CTop
        {
        public:
            CTop() {}   // 명시적 생성자
            int m_Top;
        };

        class CMiddleA : virtual public CTop
        {
        public:
            int m_MiddleA;
        };

        class CMiddleB : virtual public CTop
        {
        public:
            int m_MiddleB;
        };

        // virtual 키워드로 중복 문제 해결, virtual로 상속되어 있으며 이를 Virtual Base Class 라함
        // 이 메모리 구조는 상속횟수와 상관업시 1개다!! 
        class CBottom : public CMiddleA, public CMiddleB
        {
        public:
            CBottom(){
                m_Top = 10;
                m_MiddleA = 21;
                m_MiddleB = 22;
                m_Bottom=30;
            }
            int m_Bottom;
        };
        /*
          CTop을 보면 생성자 호출 순서를 생각하는데.. CBottom 생성자 -> A / B 생성자 호출 -> CTop() 생성자는 2번불리는가??
          물론 1번인데.. 누가 호출할 것인가? A? B?: 상속받는 마지막 클래스인 CBottom이 호출함.
          가상 상속의 경우 신중히 선택하고 애초에 다이아몬드 설계를 피하자
        */
    }
}
#endif