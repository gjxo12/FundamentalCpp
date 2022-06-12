class CParent
{
public:
    int m_Parent;
};

class CChild : public CParent
{
public:
    int m_Child;
};

int classtypeconversion5()
{
    CChild *pC = new CChild;

    CParent *pP1 = pC;
    CParent *pP2 = (CParent *)pC;
    CParent *pP3 = static_cast<CParent *>(pC);
    CParent *pP4 = reinterpret_cast<CParent *>(pC);
    // 자식에서 부모로의 변환은 허용, 다이어그램 생각

    CParent *pP = new CParent;

    CChild *pC1 = pP; // 허용된다면 변환된 포인터를 가지고 이상한 메모리 접급할수 있음
    CChild *pC2 = (CChild *)pP;
    CChild *pC3 = static_cast<CChild *>(pP);
    CChild *pC4 = reinterpret_cast<CChild *>(pP);

    return 0;
}
