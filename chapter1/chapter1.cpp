#include <iostream>
#include <bitset>
//#include <atlstr.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
//#include <stdint.h>
using namespace std;


void TypeMinMAx() {
    int i = 1; // 2의 보수법을 사용할거라 00000.....001(32비트)
    cout << "min signed int: " << (i << 31) << " \n";
    cout << "max signed int: " << ~(i << 31) << "\n";

    unsigned int ui =0;
    cout << "min unsigned int: " << ui << "\n"; // 최대
    ui = -1;
    cout << "max unsigned int: " << ui << "\n";;
     

    char c = 1; // 1바이트 부호있는 정수로도 가능: 1111,1111 ~ 0111,1111, [0000,0001] 현재 값
    c = c << 7; // 1000,0000
    cout << int(c) << "\n";
    c = c >> 7; // 비트 연산할때, 부호비트가 있다면 1로 채우고 없으면 0으로 채움!!! [1111,1111]
    cout << int(c) << "\n";
    cout << bitset<32>(c) << "\n"; // bitset을 이용한 비트표현

    // << 좌측은 2를 곱하고 >> 우측은 2를 나눈다!!

    char a = 8; // 0000,0010
    cout << (a << 2) << "   " << (a >> 2) << "\n";  // 8*2*2 , 8/2/2
    cout << "=====================================================================\n\n";
}

void TypeRightbitOperator() {
    cout << "Practice Shift Operator.....\n";
    char c = 0x02; //0000,0010
    c >> 1; // 0000,0001
    cout << (int)c << "\n";

    c = 0x82; // 1000,0010
    c = c >> 1; // 1100,0001
    cout << (int)c << "\n";

    unsigned char uc = 0x02;
    uc = uc >> 1;  // 0000,0001
    cout << int(uc) << "\n";

    uc = 0x82;
    uc = uc >> 1; //0100,0001 -> 양수니까 최왼쪽은 항상 0!!
    cout << int(uc) << "\n";
    cout << "=====================================================================\n\n";
}

void TypeFloat() {

    cout << "Float....." << "\n";
    // 부호부 1 지수부 8 가수부 23 => 32bit float
    // 0000,0000 -> -127 .... 1111,1111 -> 128 로 표현
    unsigned int ui = 0xc11b0000;
    float f;
    // -9.6875 -> -1001,1001(binary) -> -1.0011011*2^3 [부호부 음수, 지수부 3 가수부 001,1001]
    memcpy(&f, &ui, 4);
    cout << f << "\n";

    float f2 = 33554432 + 3;
    __int64 ll2 = 33554432 + 3;
    cout << "value f2: " << f2 << "  " << "value ll2; " << ll2 << "\n";

    //부동소수점: 아주 작은수와 큰 수를 표현학 위함
    //무한, Nan(not a number)
    cout << "Infinete..... and Not number......... \n";
    unsigned int inf = 0x7f800000; // 부호비트 0, 지수부 1, 가수부가 모두 0인게 중요
    unsigned int nan = 0xffffffff; // 모든 비트를 1로 채우는 것
    float a, b;
    memcpy(&a, &inf, 4);
    memcpy(&b, &nan, 4);
    cout << a << "    " << b << "\n";

    cout << "=====================================================================\n\n";
}

bool Check_HangleCode(wchar_t cha) {
    //\유니코드 한글로 번호확인
    //cout << (wchar_t)0xac00 << endl;
    if (cha >= 0xac00 && cha <= 0xd7ac) {
        if ((cha - 0xac00) % 28 == 0) return true;
    }
    return false;
}

void func(const char* str) { cout << "const char*.. " << "\n"; }
void func(char* str) { cout << "char* ..." << "\n"; }
void func(void* str) { cout << "void*..." << "\n"; }
void func(string str) { cout << "string..." << "\n"; }

void TypeString() {
    //utf-n:Unicode를 실제 컴퓨터의 타입으로 대응시킨 것, n비트의 배수로 한 문자를 표현
    //wchar_t: UTF-16 32 를 지원하는 데이터 타입.. L매크로 사용
    Check_HangleCode(L'주');

    //strlen: 문자열 시작부터 NULL을 찾는데 같은 문자열에 대해서도 strlen 100번하면 100번 모두 검색...
    //실제 문자열이 저장되는 장소는 힙 영역!!  문자열은 특별한 타입이 없다!!!
    // 문자열을 다룰때는 가능하면 해당 클래스가 제공하는 인터페이스를 사용해서 다루자!

    string str2 = "ABCDEF";
    cout << "string: " << str2.c_str() << "  size: " << str2.size() << "\n";

    string str3 = "abc가나다묭DEF";
    transform(str3.begin(), str3.end(), str3.begin(),::tolower);
    cout << "string: " << str3.c_str() << "\n";
    // 왜 한글은 꺠지는가? 한글은 2바이트!! UTF-8일땐 3바이트
    //묭: 146과 68이 10진수로 표현됨.. 146은 변환을 하지 않음! 일단 변하는 이유는 2바이트중 하나가 아스키와 중복되어 발생
    //이를 위해
    
    string test = "묭묭묭";
    cout << "String: " << test << "\n";
    //....... 나중에 한글 바이트 십진수 출력해서 확인해보기

    //문자열 타입 변환: 문자열은 타입이 없다! 문자열은 어떻게 인자로 넘길까??
    //문자열은 상수로서 메모리 어딘가에 위치하는데... 결국 메모리 주소인 포인터가 가장 알맞다.

    func("Hello Man~~~~~"); // 컴파일러는 가장 어울리는 (const* char, char*) 를 선택
    cout << "=====================================================================\n\n";
}

// void Type5() {
//     time_t t;  
//     time(&t);  // //현재 시간.
//     tm* St = localtime(&t); //  현재 tm 설정..
//     cout << St->tm_hour << "\n";  //tm 구조체의 값 확인
    
//     St->tm_mday += 40; // 현재 가지는 시간변환
//     mktime(St); //자동 갱신.. 10 + 40 =50 -> 당월의 일수로 자동계산
//     cout << St->tm_year + 1000 << "년\n";
//     cout << St->tm_mon + 100 << "월\n";
//     cout << St->tm_mday << "일\n"; // 얘만 제대로 출력

// }

int GetValue() {
    int a = 1;
    return a;
}

int& GetReference() {
    int a = 2;
    return a;
}

void Func(int& arg) { // 좌측값
    cout << "lvaue" << "\n";
}

void Func(int&& arg) { // 우측값 &&두개로
    cout << "Rvalue" << "\n";
}



void Type6() {
    //참조 타입은 포인터와 완전히 같은 방식으로 동작한다... 참조 타입을 위한 메모리 영역이 확보됨.
    const int& ra = 1; //메모리 공간이 확보되서 초기화가능
    int* pa = (int*)&ra;
    // 참조 타입은 145line와 다르게 주소 연산자가 생략되고 간접 연산자가 생략된다.
    *pa = 2;
    cout << ra << "\n";
    // 참조 타입: 포인터 영역 마련 -> 변수의 주소가 포인터 영역에 써짐
    // cosnt: 포인터 영역 뿐 아니라, int 객체의 임시 영역에 상수 대입, -> 임시 영역의 주소가 포인터 영역에 써짐
    // 메모리 변화가 어떻게 되는지 확인해야됨....
    
    //lvalue rvalue
    Func(1);   //Rvalue Reference
    int a = 1; 
    Func(a);   // Lvalue Reference
    Func(GetValue()); //Rvalue Reference
    Func(GetReference());// Lvalue Reference
    // 결국 우측값 참조역시 실제로 포인터가 사용됨... 메모리 사용에 임시 영역이 마련되고 값이 복사된 뒤에 임시 영역의 주소가 넘어감
    // 결국 참조란 포인터를 쉽게 쓰기위해 포장한 것이다!!!
}

void Type7() {
    //typedef 이미 알려진 타입을 새로운 이름으로 정의..? ; 필요
    typedef int ARR_INT_THREE[3]; 
    //       int arr[3];         typedef int arr[3];      typedef int ARR_INT_THREE[3];
    //1) 원하는 타입을 선언    2) 선언문 앞에 typedef    3) 선언문의 객체 이름을 정의하고자하는 타입 이름으로
    
    typedef double (*Function_pointer)(int a, int b); //함수 포인터도 위와 같다...

    //auto: 컴파일 타임에 자동으로 타입 추론, stl과 자주 사용
    
    
    
}

int main()
{
    TypeMinMAx(); // 기본 비트 연산
    TypeRightbitOperator(); // 쉬프트 연산
    
    // 데이터모델: 우리가 배운 타입의 크기는 플랫폼에 따라 다르다!!.
    // char short long long (8,16,64)
    // int long pointer -> 플랫폼에 따라 확인 ex) ILP64(64비트)

    // x86 32비트 시스템은 윈도우와 리눅스 ILP32(int,long,pointer 4바이트)
    // x64 시스템은 윈도우: LLP64 리눅스: LP64

    TypeFloat(); // flaot
    TypeString(); // Charactor 
    //Type5(); //Time with struct tm
    //Type6(); // Reference
    //Type7();

    return 0;
}

