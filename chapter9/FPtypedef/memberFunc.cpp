class CTest
{
public:
    int Add(int a, int b) { return a + b; }
    int subTract(int a, int b) { return a - b; }
};

typedef int (CTest::*PFUNC)(int a, int b); // 맴버함수 포인터 타입을 정의하는데..

class CParent
{
public:
    int Add(int a, int b)
    {
        return a + b;
    }
};

class CChild : public CParent
{
public:
    int Subtract(int a, int b)
    {
        return a - b;
    }
};

typedef int (CParent::*PPFUNC)(int a, int b);
typedef int (CChild::*PCFUNC)(int a, int b);

void main()
{
    PFUNC pFunc = &CTest::Add;
    // PFUNC 객체에 ADD를 대입: 우측 표현에 & 연산자 필수

    CTest t;
    CTest *pT = &t;

    int Sum1 = (t.*pFunc)(1, 2);
    int Sum2 = (pT->*pFunc)(1, 2);
    // 보통 이와같이 표현함에 주의

    int Size = sizeof(PFUNC);
    // 중요한 이 사이즈는 얼마일까?
    // 컴파일러마다 좀 다름

    PPFUNC pFFUNC1 = &CParent::Add;
    PPFUNC pFFUNC2 = &CChild::Add;
    PPFUNC pFFUNC3 = &CChild::Subtract; // Add 는 부모와 자식 모두의 맴버 함수이지만, subtract은 CChild에만 소속됨

    PCFUNC pCFUNC1 = &CParent::Add;
    PCFUNC pCFUNC2 = &CChild::Add;
    PCFUNC pCFUNC3 = &CChild::Subtract;

    CChild *pC = new CChild;
    CParent *pP = pC;

    (pP->*pFFUNC1)(1, 2);
    (pP->*pCFUNC1)(1, 2); // pP는 부모 클래스 포인터 타입인데 CChild의 맴버 함수들임
    (pC->*pFFUNC2)(2, 3); // CParent의 함수는 단연 CChild의 맴버 함수이다.
    // UpCasting 을 잘 이해해보자..

    /**
     * 맴버 함수 포인터에 대입될수 있는것은 시그니처에 포함된 클래스의 맴버함수만
     * 맴버 함수는 상속된 것도 포함
     * 시그니처에 포함된 클래스 객체와 자식 클래스 객체만이 맴버 함수 포린터 호출 가능
     */
}