#include<iostream>
#include<time.h>

int CustomRand(int count)
{
    int arr[count];
    for(int i=0;i<count;i++)
    {
        arr[i] = rand();
    }
    return arr[rand() % count];

}

int main()
{
    const int count = 1024;
    int arr[count] = {0}; // []첨자 자리에 꼭 상수가 올 필요는 없다.

    
    const int count2 = 1024;
    int* pCount = (int*)&count2;
    *pCount = 512;
    // 강제로 상수 변수 count2의 값을 변경
    //const는 객체의 이름에 적용될뿐, 메모리 블록에 지정되는것은 아님
    // 여기서 const2는 512인데...

    int arr2[count2] = {0};
    std::cout << count2 << "  " << sizeof(arr2) / sizeof(int) << "\n";
    // const는 컴파일러가 매크로처럼 취급해서 아예 1024로 취급 -> 속도 향상
    //배열 요소의 개수는 실행 시점에 결정할수 없음

    std::cout << "========================================================\n";
    srand(time(NULL));
    int count3 = rand() * 10; // max value: 327,670 -> stack overflow
    std::cout << CustomRand(count3) << "\n";
    // 그래서 가변 크기 배열처럼 동작하는 vector를 활용

}