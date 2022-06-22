#include "chapter6/classtypeconversion/classconversionvirtual.h"

using chapter6::classconversionvirtual::CChild;
using chapter6::classconversionvirtual::CParent;

void chapter6::classconversionvirtual::classconversionvirtual()
{
    CChild* pC = new CChild;
    
    CParent* pP1 = pC;
    CParent* pP2 = (CParent*)pC;
    CParent* pP3 = static_cast<CParent*>(pC);
    CParent* pP4 = reinterpret_cast<CParent*>(pC);
    // 8byte가 커지는데 오프셋 테이블을 이용해 쉽게 자식 클래스에서 부모로 변환 가능하다

    CParent* pP = new CParent;

    CChild* pC1 = pP;                               //error             
    CChild* pC2 = (CChild*)pP;                      //error
    CChild* pC3 = static_cast<CChild*>(pP);         //error
    CChild* pC4 = reinterpret_cast<CChild*>(pP);
    // 부모에서 자식으로 변환시 변환을 위한 오프셋 계산이 불가
    // 일반 상속과 달리 가상 상속은 클래스 사이의 순서와 위치가 유동적이기 때문에.. 
    // 오프셋 계산이 불가하다.. 여러개의 클래스들이 상속 받는다 가정해서 메모리를 그려보자.


    //classtypeconver5.cpp 와 똑같은데 차이는 클래스의 가상 상속 차이임...
    // 에러가 발생하는데 CChild의 메모리 구조를 생각해야함
    // 

    delete pC;
    delete pP;

}

/*     헤더 파일의 클래스 메모리 구조: 가상 상속은 유동적이다.
       ------------------------------
      |           vbptr             | 0
      |   CChild` m_Chhiild         | 8
CChild-------------------------------
      |   CParent | m_parent
      |------------------------------
      |
      ------------------------------
*/
