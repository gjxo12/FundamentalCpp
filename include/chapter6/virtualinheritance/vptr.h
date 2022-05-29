class CD1
{
public:
    int m_D1;
};

class CD2 : virtual public CD1
{
public:
    virtual ~CD2() {} // virtual function...
    int m_D2;
};

// 메모리 구조를 생각
/*

      ----CD2`   vfptr
     |    CD2`   vbptr  ---|  -4 |
     |    CD2`   m_D2   ---|   8 |
CD2  |    CD1    m_D1
     |-------

        x86 / Zp1
*/
// CD1은 가상 기저 클래스: 가장 밑, vfptr을 가지며(가상 소멸자, 가장 위)
// vbptr은 자기 자신 클래스의 오프셋 -> CD2 클래스 -> CD2 시작인 vfptr의에 대한 오프셋 -4
// 두번째는 CD1의 오프셋이면 vbbptr에서 8만큼
