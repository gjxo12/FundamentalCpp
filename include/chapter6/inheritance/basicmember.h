#ifndef __BASICMEMBER__H
#define __BASICMEMBER__H

namespace chapter6
{
    namespace inheritance
    {
        class basicmember
        {
        public:
            basicmember &operator=(basicmember &obj)
            { // 복사 대입 연산자..
                m_PVal = obj.m_PVal;
                return *this;
            }
            void operator=(int arg) // 일반 대입 연산자..
            {
                m_PVal = arg;
            }

            operator int() // 타입 변환 연사자는 상속 가능
            {
                return m_PVal;
            }

            basicmember &operator+(int arg) // 재정의된 일반 연산자는 상속 가능
            {
                m_PVal += arg;
                return *this;
            }

            int m_PVal;
        };
        class basicmemberChild : public basicmember
        {
        public:
            int m_CVal;
        };
    }
}
// 생성자와 소멸자 대입 연산자에 대해 상속이 될것인가??
#endif