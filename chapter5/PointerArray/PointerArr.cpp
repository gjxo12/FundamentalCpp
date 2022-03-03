#include <iostream>


/*
char s1[] = "ABC";
char *s1 = "ABC";

문자열 ABC가 들어있는 메모리 블록
문자열 ABC가 들어있는 메미로 블록의 주소 : l-value로서 주소

*/

int main()
{
    int arr[3] = {1,2,3};
    int *Parr = (int*)arr;
    std::cout << Parr[2] << "\n";   //OK

    int arr2[2][3] = {{1,2,3}, {100,200,300}};
    int* arr2P[2] = {arr2[0],arr2[1]}; // Solution
    int **Parr2 = (int**)arr2P; 
    std::cout << Parr2[1][2] << "\n"; //Exception
    //Parr2[1] 은 int*이므로 arr2[0][1]인 2라는 값을 주소로 알아버림..

}