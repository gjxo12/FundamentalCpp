#include<iostream>

class CTest //(B)
{
public:
    CTest(int a,int b){
        m_valA = a;
        m_valB = b;
    }
    int m_valA;  ///(B-1)
    int m_valB; //(B-2)
};

CTest g_Test(1,2); //(1)

int GetValA(); //(2)

int main()
{
    std::cout << GetValA(); //(3)
}

// (1)�� ������ ȣ�� -> (3)�� �Լ� ȣ��, A.cpp�� ���ǵǾ� ������ (5) ���� -> �׷� 1??
// �׷��� Ŭ������ �ɹ� ������ �����Ҷ� ������ �ٸ���
// static, �ߺ� ����, �ٸ� ���Ͽ��� �Լ� Ÿ�� �̸� �ߺ� ���� Ȯ��
// ���⼭�� A.cpp �����ڰ� ���ڰ� �ִµ� å���� ����.. ������ �翬�� g_test �ʱ�ȭ ������ ����..
// �̷� �ߺ� ������ ���ϱ� ���� namespace�� Ȱ���� ���̴�...