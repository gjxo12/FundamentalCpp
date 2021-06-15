#include<iostream>
#include<string>

#define OPERATOR_PLUS_LPCSTR


class CTestString
{
public:
	CTestString() {
		memset(m_data, NULL, 1024);
	}
	CTestString(const char* str) {
		memset(m_data, NULL, 1024);
		strcat(m_data, str);
	}
	CTestString& operator = (const char* str) {
		memset(m_data, NULL, 1024);
		strcat(m_data, str);
		return *this;
	}
#ifdef OPERATOR_PLUS_LPCSTR
	CTestString operator+ (const char* str) {
		CTestString ts = *this;
		strcat(ts.m_data, str);
		std::cout << "OPERATOR PLUS USING?? \n";
		return ts;
	}
#endif // OPERATOR_PLUS_LPCSTR
	CTestString operator+(const CTestString& rhs) {
		CTestString ts = *this;
		strcat(ts.m_data, rhs.m_data);
		std::cout << "NO!! OPERATOR PLUS \n";
		return ts;
	}

	// +�����ڿ��� private ���� �ɹ��� �����ϵ��� ������!! -> Ŭ���� �ȿ��� ���ְ� �Լ� �� Ŭ������ Ű���� ��� ����
	friend CTestString operator+(const char* str, const CTestString& rhs) {
		CTestString ts;
		strcat(ts.m_data, str);
		strcat(ts.m_data, rhs.m_data);
		return ts;
	}

	const char* c_str()
	{
		return m_data;
	}
private:
	char m_data[1024];
};


//Ŭ���� �޸� ���� ���캸��!
class Cparent
{
public:
	int m_PValue;
	int same_value;
	static int a_PMember;
	int PFun() { return m_PValue; }
};

class CChild : public Cparent
{
public:
	int m_CValue;
	int same_value;
	static int s_CMember;
	int CFunc() { return m_CValue; }
};


int main()
{
	CTestString ts = "aaksjd";
	ts = ts + "qqqq"; // ���� ���� �������̴�.. �����غ���
	std::cout << ts.c_str();

	CChild c;
	c.m_PValue = 1;
	// �޸� �������� static �ɹ��� �Լ��� Ŭ������ �޸� ������ ���� �ȵȴ�!!
	
	c.Cparent::same_value = 2; // ���� �ɹ� ������ ������ ���ٹ��
	//same_value�� CChild ������ 2��, ���� �ϳ��� �θ�Ŭ���� �޸� ������ �ڽ��ʿ��� �θ������� Ž����(�⺻)
}