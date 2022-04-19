/*
  operator TYPE () 
  {

  }
  클래스 타입은 때떄로 다른 타입으로 변환될 필요가 있음
  이때, 변환 규칙을 정해주는 것이 타입 변환 연산자
*/

#include<string>
#include<string.h>
#include<iostream>
#include<typeinfo>

class CLength
{
public:
	CLength() { m_Length = 0; }
	CLength(char* str)
	{
		m_Length = strlen(str);
	}
	CLength(std::string str) {
		m_Length = str.length();
	}
    void operator = (char* str){
        m_Length = strlen(str);
    }
    void operator = (std::string str){
        m_Length = str.length();
    }
    operator int () {
        return m_Length;
    }

private:
	int m_Length;
};

int main()
{
    std::string stringObj = "string";
    //const char* p1 = stringObj;        // error
    // 변환이 필요할때, 변환 연산자 호출, 
    // gcc이니 basic_string까지 들어가 convert 부분을 찾아보기
    const char* p2 = stringObj.c_str();

    CLength L1 = "123456789";   // const char*
    CLength L2 = std::string("12345"); // std::string
    int len1 = L1;
    int len2 = L2;
    // 왜 빌드가 되고 실행이 되는지 타입 변환 연산자 쪽을 보기
    std::cout << L1 << "  " << L2 << "\n";
    std::cout << len1 << "  " << len2 << "\n";
    std::cout << typeid(L1).name() << "  " << typeid(len1).name();
    return 0;
}