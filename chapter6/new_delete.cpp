/*
�Ͻ��� ����, �Ҹ���: �����Ϸ��� �ݵ�� �ʿ��ϴ� �ϸ� ������
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
	//�Ͻ��� ������ ȣ��: �θ� Ŭ������ �����ڰ� ȣ��Ǿ� �ϴµ� �ڽ��� ȣ���ؾ� ��!!!, �Ҹ��ڵ� ��������!!
	CTest6 t6;
	return;
}

