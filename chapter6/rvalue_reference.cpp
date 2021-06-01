#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
class CText
{
public:
	CText(const char* Text)
	{
		m_Len = strlen(Text);
		m_Text = new char[m_Len + 1];
		strcpy(m_Text, Text);
	}
	CText(const CText& obj) //deep copy
	{// ���⼭�� �ӽ� ��ü�� ���� ���� ������ �Ҷ�, ������ ������ ���� ���縦 �����ϵ��� �غ���...
	 // �ӽð�ü tmp�� ���� ����� t�� m_Text ����Ŵ, �̰��� move ������
		m_Text = new char[obj.m_Len + 1];
		strcpy(m_Text, obj.m_Text);
		m_Len = obj.m_Len;
	}
	CText(CText&& obj)
	{
		m_Text = obj.m_Text;
		m_Len = obj.m_Len;
		obj.m_Text = NULL;
		obj.m_Len = 0;
	}
	~CText() {
		if (m_Text) {
			delete[] m_Text;
			m_Len = 0;
		}
	}
	char* m_Text;
	int m_Len;
};

CText GetText()
{
	CText tmp("Hi man....");
	return tmp;
}

int main_rvalue()
{
	CText t1("Hi HearthStone....");
	CText t2(t1);
	CText t = GetText();
	return 0;
}