#include<iostream>

typedef int (TARR)[2];
typedef int (*PARR)[2];
// arr의 타입을 표기하기 위함 -> int[2] arr ... 이건 아니다
// TARR은 arr과 같은 타입으로 표기함 -> 그래서 TARR*이 가능
// PARR은 arr 타입의 포인터 타입

int arr[2] = {1,2};

template<typename T>
void ArrayPrint(T arg) //인자의 타입 T가 포인터 타입, arg는 배열을 가리키는 포인터로
{
    std::cout << (*arg)[0] << "  " << (*arg)[1] << "\n";
}

int Func(int arg) {return arg;} //Func의 타입은 int(int)로 타입명(파라미터 타입명) 으로 가능
template<typename T>
void CallFunc(T arg)
{
    std::cout << arg(1) << "\n";
}

void main()
{
    TARR* p1 = &arr;
    PARR p2 = &arr;
    std::cout << (*p1)[0] << "  " << (*p1)[1] << "\n";
    std::cout << (*p2)[0] << "  " << (*p2)[1] << "\n";

    ArrayPrint<int (*)[2]>(&arr);
    //템플릿 타입을 이용하여 arr 타입을 표기
    //컴파일 타임에 템플릿 함수가 구체화 된다.

    CallFunc<int (*)(int)>(Func); 
    // 함수의 포인터 [int(*)(int)]로 넘기면 CallFunc가 구체화 된다.
    //함수 이름(Func)은 r-value로 함수 본체의 메모리 주소를 나타낸다. -> arg가 함수를 가리키는 메모리 주소(함수 포인터)
}