## 다중 상속 가상 함수

메모리 구조를 잘 생각해야한다 -> vfptr이 꼭 하나만 있어야 하는 규정은 없다
이는 VTable도 2개가 있다는 의미이다..

1. 클래스가 최상위 클래스이고 맴버 함수중에 가상 함수가 없다면 vfptr을 가지지 않는다
2. 클래스가 최상위 클래스이고 맴버 함수중에 가상 함수가 있다면 vfptr을 하나 가진다.
3. 부모 클래스들이 모두 vfptr을 가지고 있지 않을 경우, 
    자식 클래스의 맴버 함수중 가상 함수가 없다면 vfptr을 가지지 않는다
4. 부모 클래스들이 모두 vfptr을 가지고 있지 않을 경우,
    자식 클래스의 맴버 함수중에 가상 함수가 있을 경우 vfptr을 하나 가진다.
5. 부모 클래스들 중 하나라도 vfptr을 가지면, 자식 ㅋ클래스는 전체 vfptr을 그대로 물려받는다.
    부모가 n개면 자식도 n개다.. -> 가상상속은 예외..
6. 클래스에 vfptr이 있을 경우 클래스의 메모리 시작 위치에 vfptr을 놓기 위하여 부모 클래스의 메모리 위치를 변경시키기도 한다.
    - 부모 클래스에 vfptr이 없을 경우 자식 클래스의 vfptr을 메모리 시작 위치로 이동시킨다.
    - 자식 클래스는 vfptr을 가진 부모 클래스부터 메모리에 위치시킨다. 지정된 상속 순서를 기준으로 vfptr을 가진 클래스에 우선 순위를 두어 메모리 위치 지정
  ----------
### 3)
  ```c++
  class CParent1{};
  class CParent2{};
  class CChild : public CParent1, public CParent2 {};
  ```
- CParent1, CParent2는 vfptr을 가지는가? -> 최상위 클래스이고 가상함수가 없다.
- CChild는 가지는가? -> 가상함수가 없으니 가지지 않는다.
  ----------
### 4)
```c++
class CParent1{};
class CParent2{};
class CChild : public CParent1, public CParent2 {
virtual void VFunc() {};
};
```
- 얘는 vfptr이 몇개인가? -> 자식에서 가상 함수가 있으니 단 한개 가지게 된다.
----------
### 5)
```c++
class CParent1 {
    public:
    virtual void VFunc1() {}
};
class CParent2{
    public:
    virtual void VFunc2() {}
};
class CChild : public CParent1, public CParent2 {};

class CChild2 : public CParent1, public CParent2 {
    public:
    virtual void VFuncC1() {}
    virtual void VFuncC2() {}
};
```
- 여기서 CChild는 vfptr은 몇개일까? 물려받은 2개의 vfptr이 있다.
- 메모리 구조가 어떨지 생각해보기
----------
- 여기서 CChild2는 vfptr이 몇개일까? 
  - 항목 **5**에 따라 부모의 갯수와 마찬가지로 2개이다.
- 그럼 CChild2에 선언된 가상 함수는 어떤 vfptr이 가리키는 VTable일까..?
  - 간단히 생각하자, VTable1을 가리키는 vfptr이 CChild2의 메모리 시작 위치에 있으니 VTable1에 CChild2의 가상 함수 2개가 추가된다.
  - 어떤 클래스에서 처음으로 선언되는 가상 함수에 대해 그 시작위치는 메모리 시작위치에 존재한다.
----------

### 6번 내용은 코드로 실행해본다.

