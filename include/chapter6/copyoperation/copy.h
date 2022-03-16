#ifndef __COPY__H
#define __COPY__H

#include<iostream>

namespace copy
{
    class CTest
    {
        public:
        CTest()
        {
            m_Value = 1;
        }
        CTest(const CTest& obj) {}
        // 복사 생성자는 자신의 const 참조 타입을 인자로 받는 생성자/ 가능한 const로 안전하게
        void ShowValue() {std::cout << m_Value << "\n";}
        int m_Value;
    };

    class CTestArr
    {
        public:
        int m_Array[3];
    };

} // namespace name

#endif

//선처리 영역을 표시하면 아래와 같다.
/*
부모 클래스 기본 생성자
  맴버가 클래스 타입일 경우 기본 생성자 호출
    ..기타 선처리... // 선처리 영역 끝
생성자 블록
생성자 블록 끝
 */
