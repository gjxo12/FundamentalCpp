/*
operator TYPE () {code..}

Visual studio 디버깅...: 디버그 옵션에서 사용자 코드만 체크 해제..
*/

#include<string>
#include<cstring>
#include<iostream>
#include<typeinfo>
#include<atlstr.h>
class CLength
{
public:
	CLength() { m_Length = 0; }
	CLength(char* str)
	{
		//m_Length = _tcslen(str);
	}
	CLength(CString& str) {
		m_Length = str.GetLength();
	}
private:
	int m_Length;
};

int main_type()
{
	//Cstring: MFC용,  ATL에서도 가능
	std::string str = "String...";
	const char* p1 = str.c_str();
	//const char* p1 = str;  에러... str은 const char* 형변환 불가 그러니 c_str() 꼭 사용하기

	//std::string data = "0123456789";
	//std::string::size_type len = data;

	return 0;
}