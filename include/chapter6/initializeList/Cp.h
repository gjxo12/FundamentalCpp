#ifndef __Cp__H
#define __Cp__H

#include<iostream>

class CP1
{
    public:
    CP1(int arg)
    {
        std::cout <<"CP1" << "\n";
    }
};

class CP2
{
    public:
    CP2(int arg)
    {
        std::cout <<"CP2" << "\n";
    }    
};

class CM1
{
    public:
    CM1(int arg)
    {
        std::cout <<"CM1" << "\n";
    }    
};

class CM2
{
    public:
    CM2(int arg)
    {
        std::cout <<"CM2" << "\n";
    }    
};

class CPCM : public CP1, public CP2
{
    public:
    CPCM() : m_M2(1), m_M1(2), CP2(3), CP1(4)
    {
        std::cout << "CMPM" << "\n";
    }
    // 위의 초기화 리스트가 없으면 문제...
    // 명시적 생성자의 선처리 영역... 오직 기본 생성자만 호출한다..
    // 상속받은 놈들의 기본 생성자는 없다.. 
    CM1 m_M1;
    CM2 m_M2;

};


#endif