//�ʱ�ȭ ����Ʈ
/*
class ... 
[
	��ó�� ����.... �θ� Ŭ���� ����, �ɹ��� Ŭ���� Ÿ���̸� ������ ȣ�� ... ��Ÿ ��ó�� : �����ڴ� �⺻ ������!
] ��
{
	������ ��� ����... 
	��...
}
*/
//�� ���� ������ �ִµ�? initialize list�� ��ó�� ������ �����Ͽ� ���� ���ϴ� �ٸ� �����ڸ� ȣ���� �� �ִ�.
// �Ʒ��� �ڵ�� �� ������ ����� �ڵ��̴�.
// ȣ�� ������ �� �˱�, �ʱ�ȭ ����Ʈ�� ����ϴµ� �ش� Ŭ������ �⺻ �����ڰ� ���ٸ�?? -> ����� �翬�� �����ϴ°�!
#include <iostream>
class Cparent
{
public:
	Cparent() { m_pvalue = 0; }
	Cparent(int arg) { m_pvalue = arg; }
	int m_pvalue;
};

class Cmember
{
public:
	Cmember() { m_mvalue = 0; }
	Cmember(int arg) { m_mvalue = arg; }
	int m_mvalue;
};
class Cchild : public Cparent
{
public:
	Cchild(int arg) : Cparent(arg), m_member(arg+1), m_cvalue(arg+2)
	{// ���� �ٲ�: �⺻ �����ڰ� �ƴ� �ٸ� �����ڰ� ȣ��ǵ���!!!
	 // �� ó�� �ٸ� ������ ȣ��!	
	}
	int m_cvalue;
	Cmember m_member;
};

int main_initialize()
{
	Cchild c(1);
	std::cout << c.m_pvalue << std::endl;
	std::cout << c.m_member.m_mvalue << std::endl;
	std::cout << c.m_cvalue << std::endl;
	return 0;
}