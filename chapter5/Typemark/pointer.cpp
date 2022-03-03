#include<iostream>

int main()
{
    char* pC = NULL;
    int* pI = NULL;
    double* pD = NULL;
    std::cout << (long)(pC + 1) - (long)pC << "\n";
    std::cout << (long)(pI + 1) - (long)pI << "\n";
    std::cout << (long)(pD + 1) - (long)pD << "\n";
    // sizeof(type)의 크기를 생각할것
    //* 간접연산자는 메모리 주소로부터 sizeof(type) 크기의 블록을 나타낸다.

}