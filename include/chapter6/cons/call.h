#ifndef __CALL__H
#define __CALL__H

#include <iostream>
namespace call
{
    class CParent
    {
    public:
        CParent()
        {
            std::cout << "CParent - Constructor!!"
                      << "\n";
        }
        ~CParent()
        {
            std::cout << "CParent - Destructor!!"
                      << "\n";
        }
    };

    class CChild : public CParent
    {
    public:
        CChild() { std::cout << "CChild - Constructor!!"
                             << "\n"; }
        ~CChild() { std::cout << "CChild - Destructor!! "
                              << "\n"; }
    };
} // namespace call
#endif

/*
CChild()

[선처리 영역이 존재]: 부모 클래스 생성자 호출, 맴버가 클래스 타입일 경우 생성자 호출...
... 기타 선처리...   이 같은 내부동작이 있음

{
    std::cout << "CChiled - Constructor"
}
~CChiled() {....}


[후처리 영역 존재]: 맴버가 클래스 타입일 경우 소멸자 호출, 부모 클래스 소멸자 호출...
... 기타 후처리... 이 같은 내부동작이 있음
*/