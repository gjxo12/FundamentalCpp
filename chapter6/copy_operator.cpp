#include<iostream>

/* 컴파일러에 의한 암시작 복사 생성자 
  ... 부모 class 복.생 
  맴버가 클래스 타입이면 복.생
  기본 타입이면 메모리 복사
  참조 타입일 경우 복사
*/

class CTEST
{
public:
	CTEST& operator = (const CTEST& obj)
	{
		m_value = 3;
		return *this;
	}
	void showValue() { std::cout << m_value << "\n"; }
	int m_value;
};

int main()
{
	CTEST t;
	t.m_value = 5;

	CTEST t1(t);
	t1.showValue();

	CTEST t2 = t;
	t2.showValue();
	//위의 복사 생성자는 5가 나옴 -> 암시적으로 컴파일러가 생성, 명시적 복사 생성자가 없으니

	CTEST t3;
	t3 = t;
	t3.showValue();
	// operator 연산 수행
	return 0;
}

