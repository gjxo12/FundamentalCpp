## **Name Mangling**

```c
int Func() {return 0;}

int Func(int arg) {return arg;}
```

- 위 코드는 컴파일이 되는가? gcc / g++ 
- 우리는 중복정의에 대해 어떻게 알고 있는가??
- 이 중복정의를 해결하고 함수와 관련된 정보를 담기 위해 Name Mangling 
- C++ 에서 모든 함수에 대해서 중복정의가 있건 없건 이름을 변형하기 시작함 -> Name Mangling
- 고유한 정보는 인자들의 개수와 타입으로, 반환 타입은 왜 아닌지 생각해보자.

### C Compiler Name Mangling
 - 잘 아시다시피 _가 붙음
 - __stdcall 규약이면 인자 타입 크기의 합이 나옴
 - VC 기준

### C++ Compiler Name Mangling 
 ```c++
 int Func1() {return 0;}
 void Func2() {}
 void Func3(int arg1) {}
 void Func4(int arg1, int arg2) {}
 void Func5(double arg1, double arg2) {}
 void Func6(double arg1, double arg2) {}
 void Func7(int arg1, double arg2) {}
 void Func8(double arg1, int arg2) {}
 ```

 - 디버깅을 많이 해보거나 바이너리를 분석해보면 알수도 있음
 - 함수명[@@...] 이렇게 알수없는 이름이 붙음
 - 프로시저, Function, void, int 등의 의미를 포함하여 나타낸다.
 - GCC의 경우 좀 더 알아보기 쉬움
 - **인자들의 타입 정보는 무조건 들어가게 된다.**  

----------

## **extern "C"**

- Name Mangling을 할 때, C++ 방식이 아닌 C 방식으로 하시오.