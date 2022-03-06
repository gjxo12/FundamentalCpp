#include<vector>
#include<iostream>

void Sum(int (&arg)[3]){
	int Sum = 0;
	int cnt = sizeof(arg) / sizeof(arg[0]);

	for(int i=0;i<cnt;i++){
		Sum += arg[i];
	}
	std::cout << Sum << "\n";
}

void Func(int arg[]) {arg[0]=1;}

void Func(std::vector<int> varg) {varg[0]=1;}

int main()
{
	int arr[3] = {1,2,3,};
	Sum(arr);
	std::vector<int> v(3);
	v[0] = 1, v[1] = 2,v[2] = 3;
	//Sum(v) 단연 타입이 다르므로 컴파일 에러
	std::cout << "==============================================\n";

	int arr2[1] = {0};
	std::vector<int> v2 {0};

	Func(arr);
	Func(v2);
	std::cout << arr[0] << "  " << v2[0] << "\n";

}