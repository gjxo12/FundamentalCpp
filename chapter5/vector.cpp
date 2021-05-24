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
	//배열은 안전성을 위한 참조로, 클래스는 값에 의한 호출로 복사 생성자가...
	//vector는 힙에 존재한다. 객체는 스택에 실제 값은 힙에!!!!
	return 0;
}