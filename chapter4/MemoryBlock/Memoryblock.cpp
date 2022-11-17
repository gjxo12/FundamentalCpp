#include<iostream>

class CTest
{
public:
  int m_V1;
  int m_V2;
  int m_value;
  void MemberFunc() {} // 맴버 함수는 함수 이름이 주소를 나타내는 r-value가 불가능
};

typedef void (CTest::*PFUNC) ();

void Func() {};

void address_addr()
{
	int arr1[1] = {1};
	// 1이 채워진 메모리 블록 이름을 arr1이라 하겠다
	int arr2[1];

	//arr2 = arr1;  compile error
	//이는 arr2가 l-value가 아니다

	int* pArr = arr1; 
	// pArr은 배열 이름이 아니라 포인터 객체의 이름 -> l-value
	// arr1이 r-value이다.. 이전까지 l-value라 했다
	// 배열 이름은 메모리 블록의 주소를 나타내는 r-value가 가능

	
	if(arr1 == (void*)&arr1){
		std::cout << "Equal!!!!" << "\n";
	}
	//배열 이름이 메모리 블록의 주소임을 보임
	//&로 메모리 블록의 주소를 나타냄
}

void address_func(){
	//함수 이름이기에 주소 연산자로 이름이 곧 주소이다.
	if(Func == &Func){
		std:: cout << "Equals..?" << "\n";
	}

	//PFUNC p1 = CTest::MemberFunc; 컴파일에러.. 
	PFUNC p2 = &CTest::MemberFunc;
	//명시적으로 함수 주소의 본체를 사용함을 나타냄
}


int main()
{
	int a = 1;
	int b = a;

	int* pA = &a;
	int* pB = pA;


	CTest t;
	t.m_V1 = 1;
	t.m_V2 = 2;
	t.m_value = 1;
	// t가 가리키는 12byte 블록에서 m_V1은 오프셋 0에 크기는 4
	// m_V2는 오프셋 4에 크기는 4

	CTest t2 = t;
	// r-value는 대입식의 우측 변에 사용: 메모리 비트 상태가 나타내는 값

	std::cout << t2.m_value << "\n";

	std::cout << "========== address adde ====================================\n";

	address_addr();

	std::cout << "========== address Function ====================================\n";

	address_func();
}
