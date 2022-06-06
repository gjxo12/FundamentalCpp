class CD1A
{
public:
    int m_D1A;
};
class CD2A : virtual public CD1A
{
public:
    int m_D2A;
};

class CD1B
{
public:
    int m_D1B;
};
class CD2B : virtual public CD1B
{
public:
    int m_D2B;
};
class CD3 : virtual public CD2A, virtual public CD2B
{
public:
    int m_D3;
};

//이 친구는 메모리구조가 어떨까...?
// 먼저 vbptr이 3개 있어야 함을 알고 생각하기
/*
       CD3     -- 1        CD3가 가리키는 테일블의 항목으로 들어갈 오프셋의 순서 및 검색트리
        |                  노드를 먼저 그리고 아래로부터 탐색
        |
    |-----------|
    |           |
2-- CD2A       CD2B --4
    |           |
    |           |
1-- CD1A       CD1B --3
*/