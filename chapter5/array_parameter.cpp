#include<iostream>

int func(int (&arg)[4])
{// �迭�� ���� Ÿ������ �����ϸ� �ƹ� ������ ����...
// �ȱ׷��� size�� �������� ũ��� ��ȯ��
// �迭�� �޸� ����� �ּҴϱ� �����ͷ� ����
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


//�迭 ����� ����
//: ����� �����ϱ� �ѵ� �ֱ��� ������? -> �߿��Ѽ� �����϶� �� ������ ����������!!
//ex) int count = 1024      //�����߿� ���� ����
//    int arr[count] = {0}  // ����