#ifndef __INIT__H
#define __INIT__H

#include<iostream>

namespace Init
{
    class CParent
    {
        public:
        CParent()
        {
            m_PValue = 0;    
        }
        CParent(int Arg)
        {
            m_PValue = Arg;
        }
        int m_PValue;
    };

    class CMember
    {
        public:
        CMember()
        {
            m_MValue = 0;
        }
        CMember(int Arg)
        {
            m_MValue = Arg;
        }
        int m_MValue;
    };

    class CChild : public CParent
    {
        public:
        CChild(int Arg)
        {

        }
        int m_CValue;
        CMember m_Member;
    };

} // namespace name

#endif

/*
  아래처럼 기본 생성자나 복사 생성자의 선처리 영역에서는 호출할 생성자가 정해짐
  정해진 생성자가 아닌 내가 원하는 다른 생성자를 호출할 방법은??
  초기화 리스트는 어떤 동작을 지시하면 선처리 영역은 미리 정의된것이 아닌 지시한 내용으로 수정해서 진행
*/
