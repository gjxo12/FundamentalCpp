class CTest
{
public:
    int Add(int a, int b) { return a + b; }
    int subTract(int a, int b) { return a - b; }
};

typedef int (CTest::*PFUNC)(int a,int b); // 맴버함수 포인터 타입을 정의하는데..

void main()
{
    PFUNC pFunc = &CTest::Add;
    // PFUNC 객체에 ADD를 대입: 우측 표현에 & 연산자 필수

    CTest t;
    CTest* pT = &t;
    
    int Sum1 = (t.*pFunc)(1,2);
    int Sum2 = (pT->*pFunc)(1,2);
    // 보통 이와같이 표현함에 주의

    
    int Size = sizeof(PFUNC);
    // 중요한 이 사이즈는 얼마일까?
    // 컴파일러마다 좀 다름
}