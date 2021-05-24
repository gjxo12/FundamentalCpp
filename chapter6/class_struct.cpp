/*
�����Ϸ��� ���� ����ü�� Ŭ������ ������
ex) .c / .cpp -> �����Ϸ��� ���� ����ü���� �ɹ� �Լ� ����
���� ���̴� -> ������ (public, private)
== Ŭ������ ����ü�� ����!

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
	
	printoffset(); //�ɹ��� �����ϱ� ���ؼ��� ������ ������ �ʼ�
	// ������ �޸� ������ ���ԵǴ°� �Ϲ� �ɹ� ������ �� 3��
	// ���� ����, �ɹ��Լ��� Ŭ���� ��ü�� ���� �ʿ䰡 ����!!
	return 0;
}