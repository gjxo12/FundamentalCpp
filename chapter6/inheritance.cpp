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

	// +연산자에만 private 지정 맴버를 접근하도록 해주자!! -> 클래스 안에도 해주고 함수 및 클래스에 키워드 사용 가능
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


//클래스 메모리 구조 살펴보기!
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
	ts = ts + "qqqq"; // 복사 대입 연산자이다.. 복습해보기
	std::cout << ts.c_str();

	CChild c;
	c.m_PValue = 1;
	// 메모리 구조에서 static 맴버와 함수는 클래스의 메모리 구조에 포함 안된다!!
	
	c.Cparent::same_value = 2; // 같은 맴버 변수를 가질때 접근방법
	//same_value는 CChild 영역에 2개, 그중 하나는 부모클래스 메모리 영역임 자식쪽에서 부모쪽으로 탐색함(기본)
}