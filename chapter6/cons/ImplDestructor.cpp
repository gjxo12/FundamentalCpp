typedef int BYTE;

class CTest1{
    public:
    BYTE m_Data;
};

class CTest2{
    public:
    ~CTest2() {}
    BYTE m_Data2;
};

class CTestp3{
    public:
    BYTE m_Data;
};


class CTest3 : public CTestp3{
    public:
    BYTE m_Data;
};

class CTestp4{
    public:
    BYTE m_Data;
};


class CTest4 : public CTestp4{
    public:
    ~CTest4() {}
    BYTE m_Data;
};

class CTestp5{
    public:
    ~CTestp5() {}
    BYTE m_Data;
};


class CTest5 : public CTestp5{
    public:
    BYTE m_Data;
};

class CTestp6{
    public:
    ~CTestp6() {}
    BYTE m_Data;
};

class CTest6 : public CTestp6{
    public:
    ~CTest6() {}
    BYTE m_Data;
};

void bar()
{
    CTest1 T1;
    CTest2 T2;
    CTest3 T3;
    CTest4 T4;
    CTest5 T5;
    CTest6 T6;
}

