#pragma once
#include<iostream>
#define A_Trace \
std::cout << "A_TRACE: " << __FUNCTION__ << "\n";

void B_TRACE()
{
	std::cout << "B_TRACE: " << __FUNCTION__ << "\n";
}

//��ũ�� ��İ� �Լ� ����� Tracer