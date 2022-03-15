#include "chapter6/cons/call.h"
#include "chapter6/cons/call2.h"
#include "chapter6/cons/call3.h"

int main()
{
    call::CChild c;
    std::cout << "=====================================================\n";
    call2::CChild c2;
    //이 헤더를 보면 선처리 영역 / 후처리 영역에 대한 이해를 할 수 있다.

    std::cout << "=====================================================\n";
    std::cout << "=====================================================\n";
    call3::CParent* pParent = new call3::CChild;
    delete pParent; // 부모가 아닌 자식의 소멸자가 호출될 것임, 소멸자 후처리 영역에 의해 부모 소멸자도 호출

    return 0;
}

//출력을 보면 부모 -> 자식 일텐데 생성자 블록 호출 순서에 대해 좀 더 보자 -> 헤더파일 go
