#include<iostream>

class CTest {
public:
	CTest() {
		m_value = 1;
	}
	CTest(const CTest& obj) {}
	void ShowValie()
	{
		std::cout << m_value << "\n";
	}
	int m_value;
};

int main()
{
	CTest c1;
	c1.m_value = 3;

	CTest c2(c1);
	c2.ShowValie();

	CTest c3 = c1;
	c3.ShowValie();

	CTest c4;
	c4 = c1;
	c4.ShowValie();
	return 0;
}