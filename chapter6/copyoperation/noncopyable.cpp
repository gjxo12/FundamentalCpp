#include "chapter6/copyoperation/noncopyable.h"

class NonTest : public noncopyabble{
    public:
    int m_Val;
};

void Non(){
    NonTest t0;
    t0.m_Val = 1;

    NonTest t1 = t0; // 암시적 복사 생성자

    NonTest t2; 
    t2 = t0; // 암시적 복사 대입 연산자
    // 부모 클래스의 생성자들을 호출할텐데.. 정의가 없다.. / 그전에 private니 에러다
}