#include <iostream>

#define TESR_VALUE //���Ǹ� ����
#define MULTI(x,y) ((x) * (y)) // �� ���� ������ ���� ���ǰ� �ʿ�

//undef: define ��ũ�θ� ����
//���Ǻ� ������!!
#ifdef UNICODE // IDE ���� ��ũ��?
typedef wchar_t TCHAR;  //���϶�
#define TSTR(str) L##str //##: ��ū ������, �ΰ��� ��ū�� �ϳ���
#else //�����϶�
typedef char TCHAR;
#define TSTR(str)  str
#endif 

void WCHAR_c()
{
	//TCHAR* str = const_cast<TCHAR*>(TSTR("Hello World?"));
	//������ ����: Ÿ���� �ٸ��ٰ� ��
}

int Define()
{
	std::cout << MULTI(1 + 2, 1 + 2) << "\n";
	return 0;
}


