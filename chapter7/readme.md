### 함수 시그니처(Signature)
  - 일반적으로 사용하는 것을 기준으로.. 
  - 함수 인자들의 타입, 순서, 반환 타입, 함수 호출 규약, const, 함수가 속한 클래스 등

### Callng Convention: 함수 호출 규약
- 32bit msvc

```
_Sum$ = -4                                          ; size = 4
_main   PROC
        push    ebp
        mov     ebp, esp
        push    ecx
        push    2
        push    1
        call    int Plus(int,int)                      ; Plus
        add     esp, 8
        mov     DWORD PTR _Sum$[ebp], eax
        xor     eax, eax
        mov     esp, ebp
        pop     ebp
        ret     0
_main   ENDP

_a$ = 8                                       ; size = 4
_b$ = 12                                                ; size = 4
int Plus(int,int) PROC                           ; Plus
        push    ebp
        mov     ebp, esp
        mov     eax, DWORD PTR _a$[ebp]
        add     eax, DWORD PTR _b$[ebp]
        pop     ebp
        ret     0
int Plus(int,int) ENDP                           ; Plus

```

### 스택의 기본 개념 
- main에서 더학기 함수인 Plus를 호출해서 그 결과를 Sum 변수에 담음
- 스레드 스택: 스레드 마다 생성되는 메모리 영역(LIFO)
- esp 레지스터: 스택에서 현재 위치를 나타냄
- push / pop 입출력 명령어
- 스택이 자란다 -> 보통 메모리가 큰쪽에서 작은 쪽으로 스택이 커진다.
- push 1: esp를 4만큼 감소시키고 esp가 가리키는 위치에 값을 입력 = (mov , sub)


