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
	//���� ��ü������ ������ ȣ���� �Ұ�����. malloc�� void*�� ��ȯ
	//free(pt);

	CTest* A = new CTest;
	CTEST_B* B = (CTEST_B*)A;
	delete B; // ��� �������� Ÿ�Ը��� üũ�Ͽ� ��ġ�ϴ°Ÿ� �Ҹ�!

}
// new�� ���������� malloc�� delete�� free�� ȣ����...
// �ᱹ �� ���� �߰����� ó���� �ϴµ� �ٷ� �����ڿ� �Ҹ����� ȣ����!!

void new_delete()
{
	CTest* arr = new CTest[2];
	delete [] arr;
	//�� ��� �Ҹ��ڴ� ��� 2���� �Ҹ��ϴ°��� �˱�?
	//�迭 Ÿ���� malloc�� free�� �״�� ȣ������ ����
	//�Ҵ�ǰ� �����Ǵ� �޸� ������ �ٸ�...
	//�� ������ �迭 ����� ������ �����ϴ°� �Ҵ�ǰ� ���� �ּҿ� ���� �޷θ� �Ҵ�
	
	CChild* pc = new CChild[2];
	std::cout << *(int*)((BYTE*)pc - 4) << "\n";
	//���� 2�� ���;ߵǴµ�.. 2���ϱ� ó�� �޸𸮴� ��Ұ���, ������ 2���� �޸�ĭ�� �Ҵ�!
	//pc�� ����Ű�� �޸� �ּҿ��� 4��ŭ �۾��� �迭 ��Ҽ��� ����� ������...
	delete[] pc;

}