#include "chapter7/lambda/lambda.h"

using chapter7::lambda::CTest;
using chapter7::lambda::CLambda;



int main()
{
    std::cout << chapter7::lambda::foo() << "\n";
    std::cout << chapter7::lambda::bar() << "\n"; // 여기까지는 쉽다.. 

    CTest t;
    t.m_Value = 10;
    std::cout << t.Func() << "\n";
    
    chapter7::lambda::test();

    // 람다의 저장
    chapter7::lambda::Func();


    return 0;
}