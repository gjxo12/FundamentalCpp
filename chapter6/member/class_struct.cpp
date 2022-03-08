/*
컴파일러에 따른 구조체와 클래스를 구별함
ex) .c / .cpp -> 컴파일러에 따라 구조체에서 맴버 함수 가능
둘의 차이는 -> 접근자 (public, private)
== 클래스는 구조체를 포함!

*/
#include"chapter6/member.h"


void printoffset()
{
	std::cout << offsetof(CTest,CTest::m_char) << "  ";
	std::cout << offsetof(CTest,CTest::m_int) << "  ";
	std::cout << offsetof(CTest,CTest::m_double) << "  ";
}

int class_struct()
{
	CTest t;
	t.m_char = 'A';
	t.m_int = 1;
	t.m_double = 3.14;
	
	printoffset(); //맴버에 접근하기 위해서는 오프셋 정보가 필수
	// 실제로 메모리 영역에 포함되는건 일반 맴버 변수인 위 3개
	// 정적 변수, 맴버함수는 클래스 객체에 있을 필요가 없다!!
	return 0;
}
// 실제 출력을 보면 0,4,8인데 구조체 맴버 맞춤 에 의해 오프셋 타입 크기가 설정되어 있어 그럼
// /ZP8 형식으로 컴파일 옵션이 되어 있음 gcc는 -fpack-struct[=n]