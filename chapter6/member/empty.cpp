#include"chapter6/member.h"

int main()
{
    CEmpty e;
    CVirtualEmpty ve;

    int size1 = sizeof(CEmpty);
    int size2 = sizeof(CVirtualEmpty);
    std::cout << size1 << "  " << size2 << "\n";
}

// 맴버 객체가 전혀 없다. 
// 클래스의 크기는 반드시 0보다는 커야한다.
// 가상 함수의 경우에는 가상 함수 테이블로 인한 크기가 또 자리잡는다.