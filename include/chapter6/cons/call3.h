#ifndef __CALL3__H
#define __CALL3__H

#include <iostream>
namespace call3
{
    class CParent
    {
    public:
        CParent(){}
        virtual ~CParent(){}
    };

    class CChild : public CParent
    {
    public:
        CChild() {}
        virtual ~CChild() {}
    };
} // namespace call3
// 상속이 될수 있는 클래스의 소멸자(CParent)에는 virtual로 지정
// 자식에겐 안써도 virtual로 상속됨
// 부모에 virtual이 없다면? 자식 소멸자가 호출되지 않는다
#endif
