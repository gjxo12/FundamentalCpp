#include "Link_A.h"
#include "system_platform.h"
#include <iostream>


int main()
{

	//FuncAA();
	//함수임을 알려주지 않으므로 해당 함수의 본체를 찾을 수 없다.
	//에러 메세지를 확인하면 힌트가 있다!!! main.obj 링크에러..

	// 두 번쨰 경우는 중복으로 정의된 경우이다!! (Link_A.cpp, Link_B.cpp)
	// 젤 어렵다.. 라이브러리 중복이라 생각해보자.. 하아..
	//그래서 namespace를 사용하여 정리하더라.,.
}