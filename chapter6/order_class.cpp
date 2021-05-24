#include<iostream>
#include<tchar.h>

class Cparent
{
public:
	Cparent() {
		std::cout << "Cparent - consturctor" << "\n";
		m_pInt = new int;
	}
	~Cparent() {
		std::cout << "Cparent - destroyor" << "\n";
		delete m_pInt;
	}
	int* m_pInt;
};

class Cchild : public Cparent
{
public:
	Cchild() {
		std::cout << "Cchild - constructor" << "\n";
		*m_pInt = 123456;
	}
	~Cchild() {
		std::cout << "Cchild - destroyor:  " <<  *m_pInt << "\n";
	}
};

int order_class()
{
	//Cchild c;
	Cparent* pParent = new Cchild;
	delete pParent;
	return 0;
}
//선처리영역, 후처리 영역 - 컴파일러가 자동으로 알아서 그래서 자식이 먼저 -> 부모 생성자 호출 / 소멸자도 마찬가지
//virtual: 중요한데, Cchild의 소멸자를 호출하기 위함이다 .즉 Cchild 객체 pParent가 소멸하는 순간 제대로 소멸 작업 X
// 하나씩 지워보고 추가하면서 확인
//가상함수가 하나라도 있는 클래스는 vfptr이라는 가상 함수 테이블 생성