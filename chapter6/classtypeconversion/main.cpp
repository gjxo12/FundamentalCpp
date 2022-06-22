#include "chapter6/classtypeconversion/classiinheritance.h"
#include "chapter6/classtypeconversion/classconversionmulti.h"
#include <iostream>

using chapter6::classinheritance::CChild;
using chapter6::classinheritance::CParentA;
using chapter6::classinheritance::CParentB;

int main()
{
    CChild *pC = new CChild;

    CParentB *pB1 = pC;
    CParentB *pB2 = (CParentB *)pC;
    CParentB *pB3 = static_cast<CParentB *>(pC);
    CParentB *pB4 = reinterpret_cast<CParentB *>(pC);

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

    std::cout << "============================================================================================\n";
    // 다중 상속
    // 보면 2번째 부모인 CParentB로 변환 / 타입 변환 할때, 포인터 값이 변한다.
    chapter6::classconversionmulti::CChild *PC = new chapter6::classconversionmulti::CChild;
    chapter6::classconversionmulti::CParentB *PB1 = PC;
    chapter6::classconversionmulti::CParentB *PB2 = (chapter6::classconversionmulti::CParentB *)PC;
    chapter6::classconversionmulti::CParentB *PB3 = static_cast<chapter6::classconversionmulti::CParentB *>(PC);
    chapter6::classconversionmulti::CParentB *PB4 = reinterpret_cast<chapter6::classconversionmulti::CParentB *>(PC);

    std::cout << "PC: " << PC << "\n";
    std::cout << "PB1: " << PB1 << "\n";
    std::cout << "PB2: " << PB2 << "\n";
    std::cout << "PB3: " << PB3 << "\n";
    std::cout << "PB4: " << PB4 << "\n";

    std::cout << "PB1: " << PB1->m_Val << "\n";
    std::cout << "PB2: " << PB2->m_Val << "\n";
    std::cout << "PB3: " << PB3->m_Val << "\n";
    std::cout << "PB4: " << PB4->m_Val << "\n"; // 결과를 보면 CParrentB의 주소는 오프셋 4만큼 떨어져있음, 실제 객체의 메모리 시작 주소를 구하기 위해
    // 클래스 포인터 타입 변환을 한다. -> 실제 객체의 정확한 메모리 주소를 구하는 과정이 클래스 포인터 타입 변환이다!!
    // reinterpret의 목적은 절대적으로 포인터 값을 유지하면서 타입을 변환. 그 결과로 가리키는 메모리 주소와 그값을 확인가능!!
    // renterpreter의 사용이유는 COM 떄문이다.

    std::cout << "============================================================================================\n";
    // 반대로 다중상속 Parent를 Cchild로 변환해보자
    chapter6::classconversionmulti::CParentB *pPB = new chapter6::classconversionmulti::CParentB;
    // chapter6::classconversionmulti::CChild* *PC1 = pPB; // compile error
    chapter6::classconversionmulti::CChild *PC2 = (chapter6::classconversionmulti::CChild *)pPB;
    chapter6::classconversionmulti::CChild *PC3 = static_cast<chapter6::classconversionmulti::CChild *>(pPB);
    chapter6::classconversionmulti::CChild *PC4 = reinterpret_cast<chapter6::classconversionmulti::CChild *>(pPB);

    std::cout << "pPB: " << pPB << "\n";
    std::cout << "pC1: " << PC2 << "\n";
    std::cout << "pC2: " << PC3 << "\n";
    std::cout << "pC3: " << PC4 << "\n";
    
    // 결과는 4byte씩 감소하고 reinterpreter는 원본과 같을테니 변하지 않음
    // 클래스 포인터 타입 변환은 변환되는 목적 클래스 객체의 실제 메모리 주소를 구한다!!


    std::cout << "============================================================================================\n";
    /*
      클래스 포인터 타입에서 중요한것은 아래와 같다.
      1. 코드의 안정성을 위해 static_cast를 이용하자
      2. 포인터 타입 변환의 목적은 실제 객체의 메모리 주소로 바꾸는 것!
      3. reinterpterte는 그저 포인터 값만을 전달한다.
      4. 가상 함수가 있으면 vfptr이 메모리에 생성된다
    */
    delete pC;
}