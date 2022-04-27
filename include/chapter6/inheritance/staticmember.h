#ifndef __STATICMEMBER__H
#define __STATICMEMBER__H

class CParent
{
public:
    inline static int s_Value;
    inline static int s2_Value;
};

class CChild : public CParent
{
public:
    inline static int s2_Value;
};
// inline 키워드로 처리 : 구현 cpp파일에 int [클래스명]::[변수명]; 으로 명시해야되는 링크에러 방지

// int CChild::s_Value; gcc에서는 c++14 이상 표준 위반


class Cconst
{
    public:
    //inline static const int a_constVal1;  inline사용시 초기화 필요,
    inline static const int a_constVal2=2;
    inline static const int a_constVal3=3;
};

#endif