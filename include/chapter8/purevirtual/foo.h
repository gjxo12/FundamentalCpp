class test
{
public:
    void Func();
};
class test2
{
public:
    virtual void Func2() = 0; // 이렇게 하면 순수 가상 함수
    virtual void Func3() {}
};

void foo();