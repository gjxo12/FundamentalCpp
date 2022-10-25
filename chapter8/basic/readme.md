## 가상함수의 호출 어셈블리

```
mov eax, dword ptr [PT]
// 메모리 주소를 eax에 넣는다: eax는 시작주소

mov edx, dword ptr [eax]
// eax가 가리키는 주소의 4byte 값, edx에 넣는다.
// vfptr이 있다.

mov eax, dword ptr [edx]
// edx가 가리키는 주소의 4byte eax에 넣는다.
// 가상 함수 테이블의 처음 4byte에는 무엇이 있는가?
// VFunc1의 주소를
call eax
....
```