## 가상상속에서의 메모리 구조
가상 기저 클래스(Virtual Base Class)
 - virtual로 상속한 경우 상속되는 부모 클래스
 - 메모리는 하나만 생성되고 생성자 호출도 한번만

 vfptr(virtual function table) / vbptr(virtual base table)

 디버그 시 보이는 해당 포인터 메모리 영역을 확인
  메모리 절약 효과와 성능에 대해 잘 판단해야함



## 가상 상속의 구조
  - virtualinheritance.h 참조
  - virtual 키워드를 사용한 자식 클래스에는 vbptr 메모리 생성(왠만하면 위에..)
  - 보통 vfptr / vbptr / 메모리구조 의 순으로 있음
  - vbbptr A (0~20) / vbptr B (0~12) 라고 가정해서 오프셋을 가짐 (4byte라 생각하자)
  - CTop과 떨어져 있는 오프셋을 생각..
  - 어떤 클래스의 조상 클래스 중에 가상 기저 클래스가 있다면 vbptr이 생성된다.