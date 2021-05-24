/*
컴파일러에 따른 구조체와 클래스를 구별함
ex) .c / .cpp -> 컴파일러에 따라 구조체에서 맴버 함수 가능
둘의 차이는 -> 접근자 (public, private)
== 클래스는 구조체를 포함!

*/

#include<stdio.h>

class CTest
{
public:
	char m_char;
	int m_int;
	double m_double;
	
	static int m_sint;
	int memberfunc()
	{
		return m_int;
	}
};

void printoffset()
{
	int offsetc = (int)(&(((CTest*)0)->m_char));
	int offseti = (int)(&(((CTest*)0)->m_int));
	int offsetd = (int)(&(((CTest*)0)->m_double));
	printf("%d %d %d", offsetc, offseti, offsetd);
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