#include<iostream>

int func(int (&arg)[4])
{// 배열을 참조 타입으로 전달하면 아무 문제가 없음...
// 안그러면 size가 포인터의 크기로 반환됨
// 배열은 메모리 블록의 주소니까 포인터로 동작
	arg[0] = 1;
	arg[1] = 2;
	arg[2] = 3;
	arg[3] = 4;

	return sizeof(arg);
}

void Array()
{
	int arr[4] = { 0 };
	int a = func(arr);

	std::cout << arr[0] << "\n";
	std::cout << arr[1] << "\n";
	std::cout << arr[2] << "\n";
	std::cout << arr[3] << "\n";
	std::cout << "arr size.... :" << sizeof(arr) << "\n";
	std::cout << "arg size.... :" << a << "\n";

}


//배열 요소의 갯수
//: 상수만 가능하긴 한되 최근은 변했지? -> 중요한선 컴파일때 그 갯수가 정해지도록!!
//ex) int count = 1024      //실행중에 값을 가짐
//    int arr[count] = {0}  // 에러