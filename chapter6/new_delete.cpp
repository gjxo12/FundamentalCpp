/*
암시적 생성, 소멸자: 컴파일러가 반드시 필요하다 하면 생성함
*/

#include<Windows.h>

class CTest1
{
public:
	BYTE m_Data;
};

class CTest2
{
public:
	CTest2() {}
	BYTE m_Data;
};

class CTestP3
{
public:
	BYTE m_Data;
};

class CTest3 : public CTestP3
{
public:
	BYTE m_Data;
};
class CTestP4
{
public:
	BYTE m_Data;
};

class CTest4 : public CTestP4
{
public:
	CTest4() {}
	BYTE m_Data;
};

class CTestP5
{
public:
	CTestP5() {}
	BYTE m_Data;
};

class CTest5 : public CTestP5
{
public:
	BYTE m_Data;
};

class CTestP6
{
public:
	CTestP6() {}
	BYTE m_Data;
};

class CTest6 : public CTestP6
{
public:
	CTest6() {}
	BYTE m_Data;
};

void test2()
{
	CTest1 t1;
	CTest2 t2;
	CTest3 t3;
	CTest4 t4;
	CTest5 t5;
	//암시적 생성자 호출: 부모 클래스의 생성자가 호출되야 하는데 자식이 호출해야 함!!!, 소멸자도 마찬가지!!
	CTest6 t6;
	return;
}

