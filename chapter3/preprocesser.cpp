#include <iostream>

#define TESR_VALUE //정의만 가능
#define MULTI(x,y) ((x) * (y)) // 이 같이 순서로 인해 주의가 필요

//undef: define 매크로를 해제
//조건부 컴파일!!
#ifdef UNICODE // IDE 지정 매크로?
typedef wchar_t TCHAR;  //참일때
#define TSTR(str) L##str //##: 토큰 연산자, 두개의 토큰일 하나로
#else //거짓일때
typedef char TCHAR;
#define TSTR(str)  str
#endif 

void WCHAR_c()
{
	//TCHAR* str = const_cast<TCHAR*>(TSTR("Hello World?"));
	//컴파일 에러: 타입이 다르다고 함
}

int Define()
{
	std::cout << MULTI(1 + 2, 1 + 2) << "\n";
	return 0;
}


