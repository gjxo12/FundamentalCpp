메모리 블록이란? 변수를 정의한다 -> 크기를 가지면서 연속된 메모리 영역

[addr,   size,   type,   bit size, value] 로 생각

    &     sizeof   typeid      
- int a;   가상 메모리의 어떤 주소에 4byte 크기의 메모리 블록 이름은 a
- int b=1;
- char* c = NULL;


일반적으로 메모리 블록의 이름은 l-value이다

값이 설정될 수 있는 모든 메모리 블록을 가리킨다.

Think: `const int a= 1; / int arr[1] = {0}; ... a ? arr ?`

r-value는 대입식의 우측 변에 사용: 메모리 비트 상태가 나타내는 값

또는, 메모리 블록의 주소를 나타낸다.