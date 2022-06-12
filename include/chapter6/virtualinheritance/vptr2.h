#ifndef __VPTR2__H
#define __VPTR2__H

class CD1A
{
public:
    int m_D1A;
};

class CD1B
{
public:
    int m_D1B;
};

class CD2 : public CD1A, virtual public CD1B // CD1B만 가상 상속
{
public:
    int m_D2;
};

//여기서의 메모리 구조는..?
/*

     |          -CD1A- m_D1A           | // 가상 상속이 아니니 CD1A에 대한 메모리 구조
     |----------------------------------|
     |        |         vbptr   -- -4   |
     |        |         m_D2    -- 8    |
CD2  |   CD2`---------------------------|
     |          CD1B    m_D1B      (가상 기저 클래스 (vbptr))
     |----------------------------------|
*/
//오프셋은 vptr.h와 같이 됨

#endif