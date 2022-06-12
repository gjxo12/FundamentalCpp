class CTestA
{
};

class CTestB
{
};

int classtypeconversion4()
{
    CTestA* pTA = new CTestA;
    
    CTestB* pTB1 = pTA;
    CTestB* pTB2 = (CTestB*)pTA;
    CTestB* pTB3 = static_cast<CTestB*>(pTA);
    CTestB* pTB4  =reinterpret_cast<CTestB*>(pTA);

    // 클래스 포인터 타입 A* 에서 B*로의 타입 변환 -> 참조 타입 결과와 같다..

    return 0;
}
