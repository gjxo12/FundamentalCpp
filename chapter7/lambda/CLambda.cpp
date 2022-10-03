#include "chapter7/lambda/lambda.h"

using chapter7::lambda::CLambda;

// Lambad의 기본: cpature var
int chapter7::lambda::foo()
{
    int vx = 1000;
    int rx = 0;
    int R = [=,&rx](int arg)->int // 값 변수, 참조 변수
    {
        rx = 10;
        return arg + rx + vx;
    }(1);// = 은 값변수, 순서대로 변수에 대해 정의 가능
    return R;
}

int chapter7::lambda::bar()
{
    int x = 100;
    return [x](int arg1) ->int {
        return [x,arg1](int arg2)->int {
            return x + arg1 + arg2;
        }(1);
    }(10);
}


void chapter7::lambda::test()
{
    int vx = 100;
    int rx = 0;

    int R1 = [vx,&rx](int arg) -> int
    {
        rx = 10;
        return vx+rx+arg;
    }(1);

    CLambda lambda(vx,rx);
    int R2 = lambda(1);

    std::cout << R1 << "\n";
    std::cout << R2 << "\n";
}

int FuncSave(int arg){return arg;}

void chapter7::lambda::Func()
{
    int (*pFunc1)(int);
    pFunc1 = &FuncSave;
    int R1 = pFunc1(1);
    // FuncSave와 같은 함수 포인터 타입을 만들기

    typedef int (*PFUNC)(int);
    PFUNC pFunc2 = &FuncSave;
    int R2 = pFunc2(1);
    // typedef로 함수 포인터 타입 정의하고 정의된 타입의 변수를 생성 

    auto pFunc3 = &FuncSave;
    int R3 = pFunc3(1);

    int x = 10;
    int y = 1;
    auto lambda = [x,&y]()->int{
        return x + y;
    };

    int L1 = lambda();
    x = 20;
    y = 2;
    int L2 = lambda();

    std::cout << L1 << "\n";
    std::cout << L2 << "\n";
    // L2의 경우 x가 처음에 들어올때 const int로 10이 먼저 들어옴
    // x를 변경해도 람다 내부엔 영향이 없으며 y는 참조 지정임
}



// 람다를 전역 변수에 영구적으로 저장하여 어떤 함수에서도 사용하길 원한다면?
// functional 객체를 사용
std::function<int(int)> g_Lambda;
// function 객체 생성, 람다 함수의 시그니처를 입력: int 타입 인자를 하나를 받아 int로 return
void Functioanl()
{
    int vx = 100;
    int rx = 10;
    g_Lambda = [vx,&rx](int arg)->int {
        return vx + rx + arg;
    };
}