#include <iostream>
#include "new_delete.h"
#include<bitset>
//CTest g_t;

typedef std::bitset<8> BYTE;

void chater4_170()
{
	int* p1 = (int*)malloc(sizeof(int));
	*p1 = 1;
	
	int* p2 = new int;
	*p2 = 2;

	int* parr1 = (int*)malloc(sizeof(int) * 2);
	parr1[0] = 0;
	parr1[1] = 1;

	int* parr2 = new int[2];
	parr2[0] = 2;
	parr2[1] = 3;

	free(p1);
	delete p2;

	free(parr1);
	delete[] parr2;

	//CTest t;

	//CTest* pt = (CTest*)malloc(sizeof(CTest));
	//동적 객체에서는 생성자 호출이 불가능함. malloc은 void*만 반환
	//free(pt);

	CTest* A = new CTest;
	CTEST_B* B = (CTEST_B*)A;
	delete B; // 대상 포인터의 타입만을 체크하여 일치하는거만 소멸!

}
// new는 내부적으로 malloc을 delete는 free를 호출함...
// 결국 이 둘은 추가적인 처리를 하는데 바로 생성자와 소멸자의 호출임!!

void new_delete()
{
	CTest* arr = new CTest[2];
	delete [] arr;
	//이 경우 소멸자는 어떻게 2개를 소멸하는것을 알까?
	//배열 타입은 malloc과 free를 그대로 호출하지 않음
	//할당되고 해제되는 메모리 구조가 다름...
	//그 구조는 배열 요소의 개수를 저장하는게 할당되고 다음 주소에 실제 메로리 할당
	
	CChild* pc = new CChild[2];
	std::cout << *(int*)((BYTE*)pc - 4) << "\n";
	//원래 2가 나와야되는데.. 2개니까 처음 메모리는 요소갯수, 다음에 2개의 메모리칸에 할당!
	//pc가 가리키는 메모리 주소에서 4만큼 작아져 배열 요소수가 저장된 영역임...
	delete[] pc;

}