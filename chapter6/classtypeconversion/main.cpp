#include "chapter6/classtypeconversion/classiinheritance.h"
#include <iostream>

using chapter6::classinheritance::CChild;
using chapter6::classinheritance::CParentA;
using chapter6::classinheritance::CParentB;

int main()
{
    CChild* pC = new CChild;

    CParentB* pB1 = pC;
    CParentB* pB2 = (CParentB*)pC;
    CParentB* pB3 = static_cast<CParentB*>(pC);
    CParentB* pB4 = reinterpret_cast<CParentB*>(pC);

    std::cout << "pC: " << pC << "\n";   // CChild의 메모리 주소
    std::cout << "pB1: " << pB1 << "\n"; // 타입을 CParentB로 변환 -> 메모리 주소가 그림상으로 어떤지 생각해보기
    std::cout << "pB2: " << pB2 << "\n"; // 클래스 포인터 타입 변환으로 실제 객체의 메모리 시작 주소를 구하기 위해
    std::cout << "pB3: " << pB3 << "\n"; // 클래스 포인터 타입 변환을 한다.
    std::cout << "pB4: " << pB4 << "\n"; // 안변했을텐데... reinterpetrt_cast의 목적으로 절대적으로 포인터 값을 유지하면서 타입 변환

    std::cout << "pC: " << pC << "\n";
    std::cout << "pB1: " << pB1->m_Val << "\n";
    std::cout << "pB2: " << pB2->m_Val << "\n";
    std::cout << "pB3: " << pB3->m_Val << "\n";
    std::cout << "pB4: " << pB4->m_Val << "\n";

    delete pC;
}