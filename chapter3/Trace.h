#pragma once
#include<iostream>
#define A_Trace \
std::cout << "A_TRACE: " << __FUNCTION__ << "\n";

void B_TRACE()
{
	std::cout << "B_TRACE: " << __FUNCTION__ << "\n";
}

//매크로 방식과 함수 방식의 Tracer