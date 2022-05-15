#include "chapter6\multiinheritance\multiinheritance.h"
//chapter6\multiinheritance\multiinheritance.h
int main()
{
    chapter6::multiinheritance::CChild c;
    chapter6::multiinheritance::CParentA* pA = &c;
    chapter6::multiinheritance::CParentB* pB = &c;
    chapter6::multiinheritance::CChild* pC = &c;
    // c의 주소값 연산이니 포인터 변수로 c의 주소값을 똑같이 가질까??
    // CPatentB의 경우 메모리 구조가 CChild가 시작하는 것보다 4byte 떨어져 있으니 적절히 조절이 필요!!
    // 각 클래스에 최초로 선언된 맴버함수를 호출할떄, 실제 클래스의 시작 주소를 넘겨야함...(상속받은건 제외)

    int Ret1 = pA->GetAVal();
    int Ret2 = pB->GetBVal();
    int Ret3 = pC->GetCVal();

    std::cout << "pA: " << pA << "\n";
    std::cout << "pB: " << pB << "\n";
    std::cout << "pC: " << pC << "\n";

    int Ret11 = c.GetAVal();
    int Ret22 = c.GetBVal();
    int Ret33 = c.GetCVal();
    // 객체를 통한 호출에서도 내부에서는 객체의 포인터를 넘겨서 처리된다.

    /*
      클래스의 맴버 함수는 실제 시작 주소인 this를 기준으로 맴버 변수에 접근하도록 컴파일됨
      함수가 호출전 해당 클래스의 시작주소를 this에 넘겨야함
      다중 상속의 두번째 부모ㅓ처럼 시작 주소가 자식 클래스와 일치하지 않으면 컴파일러는 적절히 오프셋을 조절해서 this에 부모 클래스의 시작주소를 넘긴다.
    
    */


    return 0;
}