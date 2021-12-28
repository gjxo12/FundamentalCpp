extern int g_val = 0;
static int s_val = 0; // Link error: undefined reference...
// A.cpp 내부에서만 사용할 수 있다!!


extern int g_val2;
class CTest
{
public:
    int m_val; 
};
