typedef int BYTE;
//생성자 자체가 불필요함: 암시적 생성자 X
class CTest1{
    public:
    BYTE m_Data;
};
//명시적 생성자 정의
class CTest2{
    public:
    CTest2() {}
    BYTE m_Data2;
};

class CTestp3{
    public:
    BYTE m_Data;
};

// 상속받는데 생성자가 불필요함 ->> 암시적 생성자 X
class CTest3 : public CTestp3{
    public:
    BYTE m_Data;
};

class CTestp4{
    public:
    BYTE m_Data;
};

// 명시적 생성자 정의
class CTest4 : public CTestp4{
    public:
    CTest4() {}
    BYTE m_Data;
};

class CTestp5{
    public:
    CTestp5() {}
    BYTE m_Data;
};
// 부모 클래스에 생성자 정의, 부모 클래스의 생성자는 자식 생성자가 호출해야함
// 컴파일러가 자식 클래스의 생성자를 암시적으로 생성
class CTest5 : public CTestp5{
    public:
    BYTE m_Data;
};

class CTestp6{
    public:
    CTestp6() {}
    BYTE m_Data;
};
// 명시적 생성자 정의
class CTest6 : public CTestp6{
    public:
    CTest6() {}
    BYTE m_Data;
};

void foo()
{
    CTest1 T1;
    CTest2 T2;
    CTest3 T3;
    CTest4 T4;
    CTest5 T5;
    CTest6 T6;
}

