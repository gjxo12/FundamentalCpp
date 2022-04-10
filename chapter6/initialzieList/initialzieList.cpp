#include "chapter6/initializeList/initializatioinList.h"
#include "chapter6/initializeList/initializatioinList2.h"

int main()
{
    InitializationList::CChild c(1);
    InitializationList2::CChild c2(1);

    std::cout << c.m_PValue << "\n";
    std::cout << c.m_Member.m_MValue << "\n";
    std::cout << c.m_CValue << "\n";
    // 인자있는 생성자 -> 명시적이라 부모 클래스와 맴버 클래스의 기본생성자가 호출

    std::cout << c2.m_PValue << "\n";
    std::cout << c2.m_Member.m_MValue << "\n";
    std::cout << c2.m_CValue << "\n";
    // 초기화 리스트로 인자있는 생성자를 호출하도록 함
    
}