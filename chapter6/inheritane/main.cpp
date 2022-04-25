#include "chapter6/inheritance/friend.h"
#include <iostream>

int main()
{
    CTestString ts = "abc";
    ts = ts + "def";
    std::cout << ts.c_str() << "\n";

    CTestString ts2 = "ABC";
    ts2 = "DEF" + ts2; // 연산자 앞에 붙은 인자는 암시적 변환이 절대 이루어지지 않는다.. 전위 연산자가 필요하다..
    std::cout << ts2.c_str() << "\n";
}
