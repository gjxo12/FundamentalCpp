#include <iostream>

extern int g_A;

int GetTwo() {return 2;}

int main()
{
    static int s_a;
    static int s_b = 0;
    static int s_c = 1;
    static int s_d = GetTwo(); // 이 친구는 전역 변수와 달리 초기화 순서가.. 좀 다름
    // 
    std::cout << s_a << "  " << s_b << "  " << s_c << "  " << s_d << "\n"; 

    std::cout << "=========================================================================\n";

    std::cout << g_A << "\n";  // 즉 항상 2가 나오지는 않는다...1이 나올수 있음
    // g_B는 기본값으로 0이므로  
    // g_B가 먼저 초기화되도록 한다 -- 주석이 아닌 부분들..

}