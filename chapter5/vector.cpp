#include<vector>
#include<iostream>

void func2(int arg[])
{
	arg[0] = 10;
}

void func3(std::vector<int> a) {
	a[0] = 11;
}

int main()
{
	std::vector<int> v(1);
	int arr[1] = { 0 };
	v[0] = 0;
	func2(arr);
	func3(v);
	std::cout << arr[0] << "  " << v[0] << '\n';
	//�迭�� �������� ���� ������, Ŭ������ ���� ���� ȣ��� ���� �����ڰ�...
	//vector�� ���� �����Ѵ�. ��ü�� ���ÿ� ���� ���� ����!!!!
	return 0;
}