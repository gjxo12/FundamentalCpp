### 함수 시그니처(Signature)
  - 일반적으로 사용하는 것을 기준으로.. 
  - 함수 인자들의 타입, 순서, 반환 타입, 함수 호출 규약, const, 함수가 속한 클래스 등


----------

### Callng Convention: 함수 호출 규약
- 32bit msvc

```c++
int Plus(int a,int b);

int main(){
    int Sum = Plus(1,2);
}

int Plus(int a,int b)
{
    return a + b;
}
```

```
_Sum$ = -4                                          ; size = 4
_main   PROC
        push    ebp
        mov     ebp, esp
        push    ecx

        1. -> 지금 함수가 종료된 이후 다시 ebp를 복원, 그러기 위해 스택에 저장
        2. -> 최초 esp에 있다 ebp를 스택에 저장후, ebp에 esp 대입!
        3. -> 이후 push로 스택이 자라남: 함수 반환 결과가 저장될 것임
        알다시피 지역 객체니 스택에 잠깐 생성되고 반환후 사라짐

        push    2
        push    1
        4. -> 인자를 오른쪽에서 왼쪽으로 순서대로 입력하는것이 일반적인 규약
        
        call    int Plus(int,int)                      ; Plus
        add     esp, 8
        10. -> Plus 함수는 끝, 스택에 1 / 2 를 제거함: esp를 2칸 내려서
        스택을 정리할때는 pop 연산보다 add연산이 효율적

        mov     DWORD PTR _Sum$[ebp], eax
        11. -> eax의 값을 ebp -4에 대립
        
_main   ENDP

_a$ = 8                                       ; size = 4
_b$ = 12                                                ; size = 4
int Plus(int,int) PROC                           ; Plus
        push    ebp
        mov     ebp, esp
        5. -> 1 / 2와 같은 역할: 그러면서 스택 가장 위에는 main의 ebp
        
        mov     eax, DWORD PTR _a$[ebp]
        add     eax, DWORD PTR _b$[ebp]
        6. -> 현재 ebp는 esp와 같은 위치: +8은 ebp를 아래로 2칸, 그 값은 1이다.
        7. -> 3칸 아래로 감. eax는 1 + 2가 됨.

        pop     ebp 
        ret     0
        8. -> 함수의 역할은 끝,
        9. -> ret를 통해 복귀 주소로 돌아감: 스택에 저장되어 있는 esp를 통해
int Plus(int,int) ENDP                           ; Plus

```

### 스택의 기본 개념 
- main에서 더학기 함수인 Plus를 호출해서 그 결과를 Sum 변수에 담음
- 스레드 스택: 스레드 마다 생성되는 메모리 영역(LIFO)
- esp 레지스터: 스택에서 현재 위치를 나타냄
- push / pop 입출력 명령어
- 스택이 자란다 -> 보통 메모리가 큰쪽에서 작은 쪽으로 스택이 커진다.
- push 1: esp를 4만큼 감소시키고 esp가 가리키는 위치에 값을 입력 = (mov , sub)
- ebp 레지스터: 고정된 위치를 가리키는, 함수가 시작되는 순간에 기준점으로 설정
- eax 레지스터: 보통 함수의 반환 결과를 담는다.

----------

### 함수 호출 규약
 - 함수의 인자들이 역순으로 스택에 입력되어 전달되는점
 - 일반적으로 반환 값은 eax 레지스터에 대입
 - 함수가 반환된 후 사용되지 않는 인자의 스택 영역을 호출한 함수가 정리

위와 같은 특징들이 함수 호출 규약, 예제의 Plus 함수가 위의 원칙을 따름

보통 컴파일러에서 기본으로 설정된 함수 호출 규약이 **cdecl**이다.

VC++의 경우 **stdcall**과 **fastcall**이 있음

----------

### **stdcall**
 - 기존 코드에 아래의 라인을 함수의 선언 및 정의 부분에 지정해본다.
```c++
   int__stdcall Plus(int a,int b);
```
- 위와 같이 반환 타입과 함수 이름 사이에 호출 규약을 지정해주면 된다.
- stdcall은 마지막에 `ret 8`로 스택의 esp가 가리키는 복귀 주소를 pop하면서 esp에 다시 한번 8을 더하고 점프
- 즉, 함수가 반환되기 전에 인자들의 스택 부분을 먼저 정리함
  - cdecl과 마찬가지로 인자를 오른쪽에서 왼쪽으로 스택에 입력하여 전달
  - 결과는 eax에 대입하여 반환
  - 인자의 스택 영역을 호출된 함수가 정리
- cdecl과의 차이는 **함수로 전달된 인자의 스택 영역을 누가 정리하는가!?**
  - cdecl 은 호출한 main 함수가 / stdcall은 해당 함수가 직접
  - **caller** / **callee**
  - cdecl
    - 가변 인자 함수를 가능하게 함: printf()
  - stdcall
    - 바이너리 코드의 양을 줄일 수 있음


왜 함수 호출 규약을 여러개로 나누는가..?
- 64bit x64 시스템에는 통일된 함수 호출 규약을 사용한다!
- cdecl stdcall fastcall thiscall 등이 통합되었다.
  
x64 레지스터
- x64 시스템에 ecx나 edx가 있는 이유는 rcx, rdx가 같은 레지스터를 가리킨다. 
- 4바이트면 e, 8바이트면 r
- x64에서 함수 호출 규약에 따른 스레드 스택 변화를 생각하기

- **이 호출 규약으로 함수가 어떻게 호출되고 반환되는지 이해하면 좋음**
- **C++ 코드 분석시 도움이 되고 현상이나 버그도 이해가능**
----------

