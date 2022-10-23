#include "chapter7/lambda/lambda.h"
#include "chapter7/lambda/CFunction.h"

using chapter7::CFunction::CFunction;
using chapter7::CFunction::Func;
using chapter7::lambda::CLambda;
using chapter7::lambda::CTest;

CFunction<double(int, int)> lambda;
CFunction<double(int, int)> func;
// 이같이 람다오ㅘ 함수저장을 위한 CFunction 객체 두개

double Divide(int a, int b)
{
    if (b != 0)
    {
        return (double)a / b;
    }
    return 0;
}

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

    // 람다 저장 클래스
    Func([](int arg)
         { std::cout << arg << "\n"; }); // 실제 대입된 람다의 타입이 됨..
    // 함수 시그니처: 기본적으로 반환 타입과 인자들의 타입까지 모아놓은 정보

    // 람다 템플릿.. CFunction
    double vx = 0.3;
    double rx = 0;

    lambda = [vx, &rx](int a, int b) -> double
    {
        rx = 0.4;
        return vx + rx + a + b;
    };
    func = &Divide;
    // 람다와 함수를 대입 받아서 사용가능..
    std::cout << lambda(1, 2) << "\n";
    std::cout << func(1, 2) << "\n";


    return 0;
}