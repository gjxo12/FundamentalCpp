#include <iostream>

class CParnetA
{
private:
    int m_AVal;

public:
    int Add(int a, int b)
    {
        std::cout << "Add this: " << this << "\n";
        return a + b;
    }
};

class CParentB
{
    int m_BVal;

public:
    int Subtract(int a, int b)
    {
        std::cout << "Subtract this: " << this << "\n";
        return a - b;
    }
};

class CChild : public CParnetA, public CParentB
{
public:
    int m_CVal;
};

class COther
{
public:
    int m_OVal;
};

class CGranfChild : public COther,
                    public CChild
{
public:
};

typedef int (CChild::*PFUNC)(int a, int b); // CChild 맴버 함수 포인터를 정의

int main()
{
    PFUNC pFunc = NULL; // 맴버 함수 포인터 선언
    CChild *pC = new CChild;
    std::cout << "Main pC:  " << pC << "\n";

    pFunc = &CChild::Add; // 포인터가 실제 함수에 대입될때 this를 pC로부터 변환
    int sum = (pC->*pFunc)(3, 1);
    // pFunc에는 Add가

    pFunc = &CChild::Subtract;
    int Gap = (pC->*pFunc)(3, 1);
    // pFunc에는 subtract이

    // pFunc의 타입이 PFUNC이니까 얘의 시그니처에 포함된 클래스가 CChild고 얘가 기준 클래스가 된다.
    delete pC;

    /**
     * 실행시의 출력값을 생각해보기
     * this: 맴버 함수 안의 this는 해당 맴버 함수가 정의된 클래스의 메모리 시작 주소
     * add는 CParentA, subtract은 CParnetB에 정의되니 this의 메모리 시작 주소를 그림으로 생각해보기
     * 시그니처의 클래스 타입이 CChild인 맴버함수 포인터 타입 pFunc에 맴버 함수가 대입되는 순간,
     * CChild의 주소를 기준으로 해당 맴버함수가 정의된 실제 클래스의 메모리 주소 차이를 기억하여
     * 호출시, 객체의 주소에 상대 주소 차이로 this로 변환..
     * 그림을 통해 x86 시스템에서 pFunc의 메모리 주소가 어떻게 되는지 생각하기, offset이  맴버 함수 포인터에 저장됨
     */


    // 이렇게 되어있다면 CGranfChild의 메모리 구조는?
    CGranfChild* pGC = new CGranfChild;
    PFUNC pFunc2 = &CChild::Subtract;
    int Gap2 = (pGC->*pFunc2)(5,1);
    // 여기서 CCHild 주소로 변환시켜서 컴파일러가 this 오프셋을 계산함
    // CChild* pC = pGC;
    // int Gap2 = (pC->*pFunc2)(5,1); 이렇게 어셈블리어로 표현됨

    // 여기서 중요한건, 맴버 함수 포인터 타입, 시그니처에는 클래스 타입이 반드시 들어가야한다


    delete pGC;

    return 0;
}
