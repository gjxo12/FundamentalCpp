#include<iostream>

class A
{
public:
    void FuncPA()
    {
        void *p = this;
    }
    int m_AVal;
};

class B
{
public:
    void FuncPB()
    {
        void *p = this;
    }
    int m_BVal;
};

class ChildA : public A
{
public:
    void FuncCA()
    {
        void *p = this;
    }
    int m_CAVal;
};

class ChildB : public A
{
public:
    virtual ~ChildB() {}
    void FuncCB()
    {
        void *p = this;
    }
    int m_CBVal;
};

class ChildC : public A, public B
{
public:
    void FuncCC() { void *p = this; }
    int m_CCVal;
};

typedef void (A::*PAFUNC)();
typedef void (B::*PBFUNC)();
// this를 구하기 위한 thisoffset이 필요없음..
// 위 경우 thisoffset을 위한 공간을 만들지 않거나 만들더라고 0으로 넣음
// GCC는 후자 VS는 전자
typedef void (ChildA::*PCAFUNC)(); // this를 구하기 위한 오프셋이 필요없음..

typedef void (ChildB::*PCBFUNC)();
// 클래스의 메모리 구조를 생각.. vfptr|m_AVal|m_CBVal
// this 오프셋이 필요한가? ChildB 객체라면? 그렇지 않다면? 필요없는가?
// 8이 나온 이유를 생각해보자


typedef void (ChildC::*PCCFUNC)();

int main()
{
    int sizePA = sizeof(PAFUNC);
    int sizePB = sizeof(PBFUNC);
    int sizeCA = sizeof(PCAFUNC);
    int sizeBA = sizeof(PCBFUNC);
    int sizeCC = sizeof(PCCFUNC);

    std::cout << sizePA << "  " << sizePB << "  " << sizeCA << "  " << sizeBA << "  " << sizeCC << "\n";
    return 0;
}