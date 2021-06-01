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
	{// 여기서는 임시 객체를 통해 복사 생성을 할때, 우측값 참조로 얕은 복사를 수행하도록 해보자...
	 // 임시객체 tmp는 얕은 복사로 t의 m_Text 가리킴, 이것이 move 생성자
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