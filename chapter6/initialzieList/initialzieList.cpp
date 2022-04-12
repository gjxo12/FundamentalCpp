#include "chapter6/initializeList/Init.h"
#include "chapter6/initializeList/Init2.h"
#include "chapter6/initializeList/Cp.h"
//#include "chapter6/initializeList/InitRef.h"

int main()
{
    Init::CChild c(1);
    Init2::CChild c2(1);

    std::cout << "=====================================================\n";

    std::cout << c.m_PValue << "\n";
    std::cout << c.m_Member.m_MValue << "\n";
    std::cout << c.m_CValue << "\n";
    // 인자있는 생성자 -> 명시적이라 부모 클래스와 맴버 클래스의 기본생성자가 호출
    std::cout << "=====================================================\n";

    std::cout << c2.m_PValue << "\n";
    std::cout << c2.m_Member.m_MValue << "\n";
    std::cout << c2.m_CValue << "\n";
    // 초기화 리스트로 인자있는 생성자를 호출하도록 함

    std::cout << "=====================================================\n";

    CPCM c1;
    std::cout << "=====================================================\n";

    //InitRef::CParent c2; 정의 충돌....

}