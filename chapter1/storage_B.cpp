//storage_A.cpp와 비교하세요

int a_valB;
int a_valcommon; // link error
//같은 이름의 전역변수는 실행 공간에 한번만 가능
static int a_valcommon;

int Func1(double arg) { return 1; }
double Func2(int arg) { return 2.0; }
int Func3(int arg) { return 32; } // 중복 링크 에러

class aTest1 {
public:
	int m_Int;
};
class aTest2 {
public:
	int m_val;
};
