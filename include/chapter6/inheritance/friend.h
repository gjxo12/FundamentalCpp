#include <string.h>
#include <memory>
#define OPERATOR_PLUS_LPCSTR
class CTestString
{
public:
    CTestString();
    CTestString(const char *str);
    CTestString(const CTestString &copy);
    ~CTestString();
    CTestString &operator=(CTestString rhs);
#ifdef OPERATOR_PLUS_PLCSTR
    CTestString operator+(const char *str);
#endif
    CTestString operator+(const CTestString &rhs); // 이 연산자가 사용되면 "def"형변환을 위한 생성자가 한번더 호출됨
    friend CTestString operator+(const char *str, const CTestString &rhs);
    // cpp의 전위+ 연산자를 사용하기 위해 private로 숨겨진 Pimpl을 접근하도록 친구를 지정
    const char *c_str();

private:
    class impl;
    std::unique_ptr<impl> Pimpl;
};