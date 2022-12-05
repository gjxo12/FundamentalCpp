```c++
class CParent1
{
    public:
    void Func1(){}
    void Func1_N(){}
    virtual void VFunc1(){}
    virtual void VFunc1_N(){}
};
class CParent2
{
    public:
    void Func2(){}
    void Func2_N(){}
    virtual void VFunc2(){}
    virtual void VFunc2_N(){}
};
class CChild : public CParnet1, public CParent2
{
    public:
    void Func1(){}
    void Func2() {}
    virtual void VFunc1(){}
    virtual void VFunc2(){}
};

void main()
{
    CChild c;

    c.Func1(); // CChild에 재정의 -> CChild 객체 주소
    c.Func1_N(); // CParent1 꺼 사용
    c.Func2(); // CChild에 재정의 -> CChild 객체 주소
    c.Func2_N(); // CPaent2 꺼 사용하는데.. 주소가 다를거임

    // vfptr을 가진 클래스가 기준이 되야함
    c.VFunc1(); // 실제 호출은 CChild::VFunc1 -> 얘는 CParent1에 속하니 &c
    c.VFunc1_N(); /// 위와 마찬가지
    c.VFunc2(); // CChild::VFunc2 지만, CParent2의 VTABLE을 사용....
    c.VFunc2_N(); // 위와 마찬가지..
}


```