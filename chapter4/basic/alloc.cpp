#include <iostream>
#include<bitset>

class CTest
{
public:
	CTest(){}
	~CTest() {}
};

CTest g_T; // 전역 객체

typedef std::bitset<8> BYTE;

int main()
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

	CTest t;  //지역 객체
	CTest* pT = (CTest*)malloc(sizeof(CTest)); // 클래스객체
	//malloc이 호출되는 순간 어떤 클래스 타입의 객체가 생성되는지 알수 없음..
	//여기서는 전역, 지역 생성자 두번만 호출됨
	free(pT);
	// 동적으로 할당된 객체 pT는 해체할 수 없음.. 인자로 받은 포인터의 주소를 가지고 해제함
	//그래서 new delete가 나왔는데 타입의 크기를 알고서 작동


}
// new는 내부적으로 malloc을 delete는 free를 호출함...
// 결국 이 둘은 추가적인 처리를 하는데 바로 생성자와 소멸자의 호출임!!