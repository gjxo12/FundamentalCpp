#include<iostream>

class CTest //(B)
{
public:
    CTest(int a,int b){
        m_valA = a;
        m_valB = b;
    }
    int m_valA;  ///(B-1)
    int m_valB; //(B-2)
};

CTest g_Test(1,2); //(1)

int getValA(); //(2)

int main()
{
    std::cout << getValA(); //(3)
}

// (1)의 생성자 호출 -> (3)의 함수 호출, A.cpp에 정의되어 있으니 (5) 실행 -> 그럼 1??
// 그런데 클래스의 맴버 변수에 접근할때 순서가 다르다
// static, 중복 문제, 다른 파일에서 함수 타입 이름 중복 등을 확인
// 이런 중복 문제를 피하기 위해 namespace를 활용할 것이다...