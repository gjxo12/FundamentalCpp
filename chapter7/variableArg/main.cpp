#include <stdarg.h>
#include <iostream>

void Func(int vas, ...)
{
    va_list arg_ptr;        // char*에 대한 재정의
    va_start(arg_ptr, vas); // arg_pptr을 첫번째 가변 인자의 주소로
    // char a1 = va_arg(arg_ptr,char); // 타입으로 변환하고 ptr을 다음으로
    int a2 = va_arg(arg_ptr, int);
    double a3 = va_arg(arg_ptr, double);
    char *a4 = va_arg(arg_ptr, char *);
    va_end(arg_ptr);
    // c++ 에서 가변인자를 다루기 위한 ㅋ키워드들

    std::cout << "  " << a2 << "  " << a3 << "  " << a4 << "\n";
}

void Func_str(int vas, ...)
{
    va_list arg_ptr;
    va_start(arg_ptr, vas);
    char *str = va_arg(arg_ptr, char *);
    va_end(arg_ptr);

    std::cout << str << "\n";
}

class CTest
{
public:
    CTest() { m_V = 0; }
    CTest(const CTest &obj) { m_V = obj.m_V + 1; }
    int m_V;
};

void CFunc(CTest arg)
{                  // 고정 인자 함수?
    CTest t = arg; // 여기서는 어떤 생성자의 호출인가?
    std::cout << "CFunc: " << t.m_V << "\n";
}

void VAFunc(int vas, ...)
{
    va_list arg_ptr;
    va_start(arg_ptr, vas);
    CTest t = va_arg(arg_ptr, CTest); //
    va_end(arg_ptr);
    std::cout << "VAFunc: " << t.m_V << "\n";
}

int main()
{
    char a1 = '1';
    int a2 = 2;
    double a3 = 3.14f;
    char *a4 = "HUR";
    Func(0, a2, a3, a4);

    std::string str = "String..";
    Func_str(0, str.c_str());
    // string 객체넘길때 주의

    CTest t;
    CFunc(t); // 여기서는 어떤 생성자의 호출인가?
    VAFunc(0, t);
    // 가변 인자는 값에 의한 호출방식으로 전달,
    // 복사 생성자가 호출되지 않음, 오직 메모리 복사만 발생

    return 0;
}

/*
 * 호출 규약에 따른 스택정리
 * cdecl / stdcall: 이 둘의 차이는 전달된 인자의 스택 정리를 누가 담당하는가?
 * cdecl: caller  stdcall: callee -> 절대로 가변인자 함수를 만들수 없음
 */