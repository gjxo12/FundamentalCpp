class CTest  //(A)
{
public: 
    CTest(int a,int b) { 
        m_valA = a; 
        m_valB = b;
    }
    int m_valB; // (A-1)
    int m_valA; // (A-2)
};

extern CTest g_test(1,2); //(4)

int GetValA() {return g_test.m_valA;} // (5)