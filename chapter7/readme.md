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
