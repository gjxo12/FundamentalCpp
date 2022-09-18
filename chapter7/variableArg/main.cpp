#include<stdarg.h>
#include<iostream>

void Func(int vas, ...)
{
    va_list arg_ptr;  // char*에 대한 재정의
    va_start(arg_ptr,vas); // arg_pptr을 첫번째 가변 인자의 주소로
    //char a1 = va_arg(arg_ptr,char); // 타입으로 변환하고 ptr을 다음으로
    int a2 = va_arg(arg_ptr,int);
    double a3 = va_arg(arg_ptr,double);
    char* a4 = va_arg(arg_ptr,char*);
    va_end(arg_ptr);
    // c++ 에서 가변인자를 다루기 위한 ㅋ키워드들
    

    std::cout <<  "  " << a2 << "  " << a3 << "  " << a4 << "\n";
}

void Func_str(int vas,...){
    va_list arg_ptr;
    va_start(arg_ptr,vas);
    char* str = va_arg(arg_ptr,char*);
    va_end(arg_ptr);

    std::cout << str << "\n";
}

int main()
{
    char a1 = '1';
    int a2 = 2;
    double a3 = 3.14f;
    char* a4 = "HUR";
    Func(0,a2,a3,a4);

    std::string str = "String..";
    Func_str(0,str.c_str());
    // string 객체넘길때 주의
}