#include <iostream>

extern int g_val;
//extern int s_val;
//
int g_val2;
class CTest;

int main()
{
    //int g_val = 1;
    //s_val = 2;
    //std::cout << "extern: " << g_val << "  static: " << s_val;
    
    g_val2 = 1; 
    std::cout << "chapter2 Extern_static...." << g_val << "\n";
    /*
    CTest t;
    t.m_val = 1;
    클래스는 이 파일에 CTest의 정의를 해줘야한다. 각 소스파일마다...
    그래서 헤더파일에 작성하고 소스 파일에서 헤더를 포함하는 방식으로 작성
    class_def 디렉토리에서 중복 클래스 정의를 살펴보자.
    */
}