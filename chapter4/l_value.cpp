#include<iostream>

void value_func() {};

class value_test
{
public:
	int v1;
	int v2;
	void Memberfunc() {}
};

typedef void(value_test::*PFUNC) ();
//클래스 함수 포인터니.. 공부가 필요..

void main()
{
	int arr1[1] = { 1 };
	int arr2[1];
	//arr2 = arr1; arr2가 l_value가 아니니까 에러다!!

	int* parr = arr1;
	if (arr1 == (void*)&arr1) {

	}

	if (value_func == &value_func) {
		std::cout << "same\n";
	}

	PFUNC p1 = &value_test::Memberfunc;
	std::cout << p1 << "  " << sizeof(p1);

}

//l_value: = 좌측인데 배열 이름이나 함수이름과 같이 모든게 l_value는 아님
//r_value: = 우측인데 이름으로 값이 될수 있음, 메모리 블록의 비트 상태 나타내기, 메모리 블록의 주소를 나타내는 상수