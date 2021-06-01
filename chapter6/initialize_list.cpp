//초기화 리스트
/*
class ... 
[
	선처리 영역.... 부모 클래스 생성, 맴버가 클래스 타입이면 생성자 호출 ... 기타 선처리 : 생성자는 기본 생성자!
] 끝
{
	생성자 블록 시작... 
	끝...
}
*/
//위 같은 동작이 있는데? initialize list는 선처리 영역을 제어하여 내가 원하는 다른 생성자를 호출할 수 있다.
// 아래의 코드는 위 내용을 요약한 코드이다.
// 호출 순서를 잘 알기, 초기화 리스트를 사용하는데 해당 클래스에 기본 생성자가 없다면?? -> 결과는 당연히 생각하는것!
#include <iostream>
class Cparent
{
public:
	Cparent() { m_pvalue = 0; }
	Cparent(int arg) { m_pvalue = arg; }
	int m_pvalue;
};

class Cmember
{
public:
	Cmember() { m_mvalue = 0; }
	Cmember(int arg) { m_mvalue = arg; }
	int m_mvalue;
};
class Cchild : public Cparent
{
public:
	Cchild(int arg) : Cparent(arg), m_member(arg+1), m_cvalue(arg+2)
	{// 여길 바꿈: 기본 생성자가 아닌 다른 생성자가 호출되도록!!!
	 // 위 처럼 다른 생성자 호출!	
	}
	int m_cvalue;
	Cmember m_member;
};

int main_initialize()
{
	Cchild c(1);
	std::cout << c.m_pvalue << std::endl;
	std::cout << c.m_member.m_mvalue << std::endl;
	std::cout << c.m_cvalue << std::endl;
	return 0;
}