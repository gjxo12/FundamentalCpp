## 가상 상속
- vfptr이 메모리 시작위치에 없을수도 있음
- 물려받은 vfptr이 main vfptr이 아닐경우 추가적으로 vfptr이 생성됨
- 이런 이유들 떄문에 컴파일러마다 가상 상속을 구현하지 않기도함
- vbptr이라는 virtual base table 이라는걸 생각하기

```c++

class CParent
{
    public:
    virtual void VFuncP() = 0;
    int m_Parent;
};
class CChild : virtual public CParent
{
    public:
    virtual void VFuncP() {}
    //virtual void VFuncC() {} 유무의 차이
    int m_Child
}
```

- 위 코드에서 메모리 구조가 매우매우 복잡함