#include<iostream>

class CTest {
public:
	CTest() {
		m_value = 1;
	}
	//CTest(const CTest& obj) {}
	void ShowValie()
	{
		std::cout << m_value << "\n";
	}
	int m_value;
};

int main_constructor()
{
	CTest c1;
	c1.m_value = 3;

	//복사 생성자: 자신의 참조 타입을 인자로 받는것!
	CTest c2(c1);     //복사 생성자 호출
	c2.ShowValie();

	CTest c3 = c1;    // 복사 생성자 호출
	c3.ShowValie();

	//복사 생성자 값을 보면 없는데 아무것도 안해서 그럼

	CTest c4;
	c4 = c1;
	c4.ShowValie();
	return 0;
}

//복사 생성자가 없으면 3,3,3 이 출력? -> 암시적 복사 생성자 생성 -> 
//값은 왜?? 선처리 영역에서 복사 생성자 및 맴버에 대해 메모리 복사 이뤄짐
//명시적: 부모,맴버 클래스의 기본 생성자를!!! 암시적이면 부모나 맴버 클래스의 복사 생성자와 얕은 복사를 수행!!!!


//객체의 값에 의한 호출을 하는 경우도 복사 생성자 호출
// 깊은 복사를 하는 이유? 한쪽 객체가 소멸되어도 남아있는 객체가 소멸된 영역의 참조를 피하게끔