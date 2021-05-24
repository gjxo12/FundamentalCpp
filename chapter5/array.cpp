//array and pointer
#include<iostream>

int array_test1()
{
	int arr[3] = { 1,2,3 };
	int* parr = (int*)arr;
	std::cout << parr[2];
	return 1;
}
//위 코드와 같이 1차원일때는 문제가 없다!!!

//char s[] = "ABC"
//char *s1[] = "ABC
//s1은 포인터로서 메모리 블록의 주소를 나타내는 차이와 char type으로 1바이트의 메모리 블록 영역

void array_test2()
{
	int arr[2][3] = { {11,12,13},{21,22,23} };
	int** parr = (int**)arr;
	std::cout << parr[0];
	//std::cout << parr[1][2];
	//예외가 발생함.. parr[0]는 int* 일텐데 이건 12다. '12'라는 주소..? 메모리가 접근허용을...
}
//parr은 포인터일 뿐, 원천 타입은 int*이다. parr이 가리키는 메모리 주소로부터 sizeof(int*) 크기 단위ㅣ
//x86, x64에 따라 원천 크기가 다름.. (4,8)...

void array_matrix2()
{
	int arr[2][3] = { {11,12,13},{21,22,23} };
	int* arrp[2] = { arr[0],arr[1] };
	int** ppar = (int**)arrp;
	std::cout << ppar[1][2] << "\n";
	std::cout << arrp[0] << "  " << ppar[0];
}
//뭔가 중요함.. 
//ppar은 배열 객체 arrp의 메모리 주소를 가리키고 arrp의 arr[0]는 arr[0]이 담긴 메모리의 주소!!를 가짐
//책의 그림을 꼭 보기!!!