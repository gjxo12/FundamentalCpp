/*
operator TYPE () {code..}

Visual studio �����...: ����� �ɼǿ��� ����� �ڵ常 üũ ����..
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
	//Cstring: MFC��,  ATL������ ����
	std::string str = "String...";
	const char* p1 = str.c_str();
	//const char* p1 = str;  ����... str�� const char* ����ȯ �Ұ� �׷��� c_str() �� ����ϱ�

	//std::string data = "0123456789";
	//std::string::size_type len = data;

	return 0;
}