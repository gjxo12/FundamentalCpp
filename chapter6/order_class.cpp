#include<iostream>
#include<tchar.h>

class Cparent
{
public:
	Cparent() {
		std::cout << "Cparent - consturctor" << "\n";
		m_pInt = new int;
	}
	~Cparent() {
		std::cout << "Cparent - destroyor" << "\n";
		delete m_pInt;
	}
	int* m_pInt;
};

class Cchild : public Cparent
{
public:
	Cchild() {
		std::cout << "Cchild - constructor" << "\n";
		*m_pInt = 123456;
	}
	~Cchild() {
		std::cout << "Cchild - destroyor:  " <<  *m_pInt << "\n";
	}
};

int order_class()
{
	//Cchild c;
	Cparent* pParent = new Cchild;
	delete pParent;
	return 0;
}
//��ó������, ��ó�� ���� - �����Ϸ��� �ڵ����� �˾Ƽ� �׷��� �ڽ��� ���� -> �θ� ������ ȣ�� / �Ҹ��ڵ� ��������
//virtual: �߿��ѵ�, Cchild�� �Ҹ��ڸ� ȣ���ϱ� �����̴� .�� Cchild ��ü pParent�� �Ҹ��ϴ� ���� ����� �Ҹ� �۾� X
// �ϳ��� �������� �߰��ϸ鼭 Ȯ��
//�����Լ��� �ϳ��� �ִ� Ŭ������ vfptr�̶�� ���� �Լ� ���̺� ����