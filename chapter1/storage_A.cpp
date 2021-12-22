//storage_B.cpp 와 비교하세요..

int a_valA;
int a_valcommon;
static int a_valcommon;

static int a_valA;
static int a_valA;// error
//같은 이름의 정적 변수는 한 오브젝트 공간에 한번만!

int Func1(int arg) {return 1;}
int Func2(int arg) { return 2; }
int Func3(int arg) { return 3; } // 중복 링크 에러
int FuncA(int arg) { return 4; }
//double FuncA(int arg) { return 4; }
// 반환 타입이 다르다면 같은 소스 파일에 정의 불가!

class aTest1 {
public:
	char m_char;
};
class aTest2 {
public:
	int m_val;
};
class aTestA {
public:
	int m_val;
};
class aTestA {
public:
	int m_val;
};

// 같은 이름의 클래스는 한 오브젝트 공간에 한번만 정의 가능