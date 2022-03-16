#ifndef __COPY2__H
#define __COPY2__H

#include<iostream>

namespace copy2
{
    class CTest
    {
        public:
        CTest()
        {
            m_Value = 1;
        }
        CTest& operator = (const CTest& obj){
            m_Value = 3;
            return *this;
        }
        
        void ShowValue() {std::cout << m_Value << "\n";}
        int m_Value;
    };
} // namespace name

#endif

/*
컴파일러에 의해 생성된 암시적 복사 생성자의 선처리 영역
부모 클래스와 맴버 클래스에 대해 복사 생성자가 호출됨
맴버가 기본 타입일 경우 매모리 복사도 이루어짐..

명시적은 기본 생성자만 호출되며 기본 타입에 대해 메모리 복사 X
*/

/*
  복사 대입 연산자의 경우
컴파일러가 부모 클래스에 대해 복사 대입 연산자 호출
맴버가 클래스 타입일 경우 복사 대입 연산자 호출
맴버가 기본 타입일 경우 메모리 복사
맴버가 배열 타입일 경우 원소에ㅔ 따라 반복 수행
*/

