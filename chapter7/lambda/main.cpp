#include "chapter7/lambda/lambda.h"
#include "chapter7/lambda/CFunction.h"

using chapter7::lambda::CLambda;
using chapter7::lambda::CTest;
using chapter7::CFunction::Func;

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

    //람다 저장 클래스
    Func([](int arg){std::cout << arg << "\n";});// 실제 대입된 람다의 타입이 됨..

    return 0;
}