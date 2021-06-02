#include<iostream>

extern int g_A;
int main()
{
    //Func();
    //std::cout << CTest::s_val << std::endl;

    // 초기화 순서를 제어해보자 
    //프로세스가 시작될 경우 가장 먼저 가상 메모리가 구성, 
    //전역 변수 정적 전역 변수 정적 맴버 변수 함수 초기화
    //정적 지역 변수의 함수 초기화

    std::cout << g_A << std::endl;
    // g_A가  g_B보다 먼저 초기화 된다면!! 원하는 2를 뽑을 수 있다!!
}