//storage_B.cpp �� ���ϼ���..

int a_valA;
int a_valcommon;
static int a_valcommon;

static int a_valA;
static int a_valA;// error
//���� �̸��� ���� ������ �� ������Ʈ ������ �ѹ���!

int Func1(int arg) {return 1;}
int Func2(int arg) { return 2; }
int Func3(int arg) { return 3; } // �ߺ� ��ũ ����
int FuncA(int arg) { return 4; }
//double FuncA(int arg) { return 4; }
// ��ȯ Ÿ���� �ٸ��ٸ� ���� �ҽ� ���Ͽ� ���� �Ұ�!

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

// ���� �̸��� Ŭ������ �� ������Ʈ ������ �ѹ��� ���� ����