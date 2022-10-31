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
## 가상함수 테이블 생성

- 가상 함수 테이블의 항목에는 가상함수의 주소가 들어있다.
- 가상 함수 테이블은 클래스 객체가 아니라 클래스마다 하나씩 존재
- 컴파일 시점에 소스 코드애 정의된 클래스에 virtual 이 있으면 생성한다.
- 객체가 생성될때 객체의 vfptr에 해당 클래스의 가상 함수 테이블의 주소를 설정
