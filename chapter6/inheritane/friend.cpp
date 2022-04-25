#include "chapter6\inheritance\friend.h"

class CTestString::impl
{
public:
    impl(){};
    impl(const char *str){}; // Impl 생성자에 이같이 꼭 정의를 만들어주기
    char m_data[1024];
};

CTestString::CTestString() : Pimpl(new impl())
{
    memset(Pimpl->m_data, NULL, 1024);
}

CTestString::CTestString(const char *str) : Pimpl(new impl(str))
{
    memset(Pimpl->m_data, NULL, 1024);
    strcat(Pimpl->m_data, str);
}

// for copy constructor: 복사 생성자 꼭 정의해주기
CTestString::CTestString(const CTestString &copy) : Pimpl(new impl(*copy.Pimpl)) {}

CTestString::~CTestString() = default;

CTestString &CTestString::operator=(CTestString rhs)
{
    swap(Pimpl, rhs.Pimpl);
    return *this; // operator= 연산자는 위와 같이 정의해주기
}

#ifdef OPERATOR_PLUS_PLCSTR
CTestString CTestString::operator+(const char *str)
{
    CTestString ts = *this;
    strcat(ts.m_data, str);
    return ts;
}
#endif

CTestString CTestString::operator+(const CTestString &rhs)
{
    CTestString ts = *this;
    strcat(ts.Pimpl->m_data, rhs.Pimpl->m_data);
    return ts; // 접근은 Pimp을 통해서 하기
}

const char *CTestString::c_str()
{
    return Pimpl->m_data;
}

CTestString operator+(const char *str, const CTestString &rhs)
{
    CTestString ts;
    strcat(ts.Pimpl->m_data, str);
    strcat(ts.Pimpl->m_data, rhs.Pimpl->m_data);
    return ts;
}// 전위형 연산을 위한 +연산자 정의
