#include<iostream>

/* �����Ϸ��� ���� �Ͻ��� ���� ������ 
  ... �θ� class ��.�� 
  �ɹ��� Ŭ���� Ÿ���̸� ��.��
  �⺻ Ÿ���̸� �޸� ����
  ���� Ÿ���� ��� ����
*/

class CTEST
{
public:
	CTEST& operator = (const CTEST& obj)
	{
		m_value = 3;
		return *this;
	}
	void showValue() { std::cout << m_value << "\n"; }
	int m_value;
};

int main()
{
	CTEST t;
	t.m_value = 5;

	CTEST t1(t);
	t1.showValue();

	CTEST t2 = t;
	t2.showValue();
	//���� ���� �����ڴ� 5�� ���� -> �Ͻ������� �����Ϸ��� ����, ����� ���� �����ڰ� ������

	CTEST t3;
	t3 = t;
	t3.showValue();
	// operator ���� ����
	return 0;
}

