#include "chapter6\classtypeconversion\classtest.h"

using chapter6::classconversion::CTestB;

int classtypeconversion()
{
    chapter6::classconversion::CTestA ta;
    ta.m_Test = 7;

    // ta를 CTestB& 로 타입 변환하려함.. 에러인 친구들은 상관없는 타입에 대해 암시적 형변환을 허락하지 않음
    CTestB& rtb1 = ta;
    CTestB& rtb2 = (CTestB&)ta; // 그저 명시적 형변환
    CTestB& rtb3 = static_cast<CTestB&>(ta); // static cast는 서로 상속 관계에 있을때 사용가능!
    CTestB& rtb4  =reinterpret_cast<CTestB&>(ta);
    return 0;
}


/*
    int i = 3;
    double d3 = (double &)i;
    double &rd3 = (double &)i;
    // 얘들은 명시적이니 괜찮
    
    double &rd1 = i;
    double &rd2 = (double)i;
    // 참조 타입 객체는 r-value로 초기화 불가..
    // 참조 타입 변환은 값이 아닌 메모리가 반환된다...
*/