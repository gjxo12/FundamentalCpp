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
//Ŭ���� �Լ� �����ʹ�.. ���ΰ� �ʿ�..

void main()
{
	int arr1[1] = { 1 };
	int arr2[1];
	//arr2 = arr1; arr2�� l_value�� �ƴϴϱ� ������!!

	int* parr = arr1;
	if (arr1 == (void*)&arr1) {

	}

	if (value_func == &value_func) {
		std::cout << "same\n";
	}

	PFUNC p1 = &value_test::Memberfunc;
	std::cout << p1 << "  " << sizeof(p1);

}

//l_value: = �����ε� �迭 �̸��̳� �Լ��̸��� ���� ���� l_value�� �ƴ�
//r_value: = �����ε� �̸����� ���� �ɼ� ����, �޸� ����� ��Ʈ ���� ��Ÿ����, �޸� ����� �ּҸ� ��Ÿ���� ���