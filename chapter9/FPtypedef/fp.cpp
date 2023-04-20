typedef int Myint;     // 이건 쉽지?
typedef int Myarr[16]; // 이건...?

// typedef는 타입을 특정 이름으로 잘 선언하고 맨 앞에 typedef를 붙여준다.
// 함수 포인터도 똑같다.. chapter1 참조

int Add(int a, int b) { return a + b; }

typedef int (*PADD)(int a, int b); // 함수 포인터 타입을 정의

int g_I = 3;

int Subtrack(int a, int b) { return a - b; }

double Devide(int a, int b) { return (double)a / (double)b; }

typedef int (*PASFUNC)(int a,int b);
typedef double (*PDIVIDE) (int a,int b);

int main()
{
    PADD pAdd1, pAdd2, pAdd3; // PADD 타입 객체를 선언
    pAdd1 = pAdd2 = pAdd3 = &Add;
    // 함수 포인터란 말그대로 해당 함수의 주소를 가진다.
    int sum1 = pAdd1(1, 2);
    int sum2 = pAdd2(1, 2);
    int sum3 = pAdd3(1, 2);

    // 어? 함수 포인터에 가장 기본적인 void*를 사용하면 개꿀아닌가?
    void *pI = &g_I;
    int i = *pI;
    // 얘는 쉽다? pI가 무엇을 가지는가? -> 그저 함수의 주소만을 가진다.. int 인데 함수 주소로 메모리 크기, 값을 아는가..

    void *pAdd = &Add;
    int Sum = pAdd(1, 2);
    // 얘는.. 메모리 크기랑 상관이 없어 보이는데..
    // 반환 타입이 무엇인가..? 이는 컴파일 시간에 알수없다..
    // 시그니처: 반환 타입, 인자들의 타입 정보 -> 함수 정보

    PASFUNC pAS;
    PDIVIDE pDivide;
    // 함수 포인터는 각각의 시그니처를 가진다. 이 시그니처가 일치해야한 한다.
    // Add, Subtract은 반환 타입과 인자 타입이 int로 일치한다.
    // 
    pAS = &Add;
    pAS = &Subtrack;
    pAS = &Divide; // 반환 타입과 인자타입을 보자.. devide 함수가 pAS의 반환 타입, 인자타입과 어떻게 되는가?
    pDivide = &Devide;
}