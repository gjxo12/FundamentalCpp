//array and pointer
#include<iostream>

int array_test1()
{
	int arr[3] = { 1,2,3 };
	int* parr = (int*)arr;
	std::cout << parr[2];
	return 1;
}
//�� �ڵ�� ���� 1�����϶��� ������ ����!!!

//char s[] = "ABC"
//char *s1[] = "ABC
//s1�� �����ͷμ� �޸� ����� �ּҸ� ��Ÿ���� ���̿� char type���� 1����Ʈ�� �޸� ��� ����

void array_test2()
{
	int arr[2][3] = { {11,12,13},{21,22,23} };
	int** parr = (int**)arr;
	std::cout << parr[0];
	//std::cout << parr[1][2];
	//���ܰ� �߻���.. parr[0]�� int* ���ٵ� �̰� 12��. '12'��� �ּ�..? �޸𸮰� ���������...
}
//parr�� �������� ��, ��õ Ÿ���� int*�̴�. parr�� ����Ű�� �޸� �ּҷκ��� sizeof(int*) ũ�� ������
//x86, x64�� ���� ��õ ũ�Ⱑ �ٸ�.. (4,8)...

void array_matrix2()
{
	int arr[2][3] = { {11,12,13},{21,22,23} };
	int* arrp[2] = { arr[0],arr[1] };
	int** ppar = (int**)arrp;
	std::cout << ppar[1][2] << "\n";
	std::cout << arrp[0] << "  " << ppar[0];
}
//���� �߿���.. 
//ppar�� �迭 ��ü arrp�� �޸� �ּҸ� ����Ű�� arrp�� arr[0]�� arr[0]�� ��� �޸��� �ּ�!!�� ����
//å�� �׸��� �� ����!!!