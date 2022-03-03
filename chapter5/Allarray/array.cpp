#include<iostream>

int Func(int arg[])
{
    arg[0] = 1;
    arg[1] = 2;
    arg[3] = 3;
    arg[4] = 4;
    return sizeof(arg);
}

int Func2(int (&arg)[4])
{
    arg[0] = 1;
    arg[1] = 2;
    arg[3] = 3;
    arg[4] = 4;
    return sizeof(arg);
}

int main()
{
    int arr[4] = {0};
    int s = Func(arr);
    int ss = Func2(arr);

    std::cout << arr[0] << "\n";
    std::cout << arr[1] << "\n";
    std::cout << arr[2] << "\n";
    std::cout << arr[3] << "\n";
    
    std::cout << "arr size..:" << sizeof(arr) << "\n";
    std::cout << "s size..:"  << s << "\n"; // arg가 int*이므로 sizeof(int*)로서 포인터 크기가 반환
    std::cout << "ss size..:"  << ss << "\n"; ///참조 타입으로 


    std::cout << "===========================================================\n";

    int arr2[2][3];
    int s1 = sizeof(arr2); // 24:
    int s2 = sizeof(arr2[0]); // 12: arr은 2개의 요소 arr[0], arr[1]
    int s3 = sizeof(arr2[0][0]); // 4: arr[0]는 3개의 int 객체가 모인것

    int** pparr = (int**)arr2; // arr2를 int** 타입으로 형변환
    int ss1 = sizeof(pparr);
    int ss2 = sizeof(pparr[0]);
    int ss3 = sizeof(pparr[0][0]);
    std::cout << ss1 << "  " << ss2 << "  " << ss3 <<  "  " << sizeof((int**)arr2) << "\n";
    // pparr = int** pparr[0] = int*
    return 0;
}
