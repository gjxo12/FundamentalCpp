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

int getValA(); //(2)

int main()
{
    std::cout << getValA(); //(3)
}

// (1)�� ������ ȣ�� -> (3)�� �Լ� ȣ��, A.cpp�� ���ǵǾ� ������ (5) ���� -> �׷� 1??
// �׷��� Ŭ������ �ɹ� ������ �����Ҷ� ������ �ٸ���
// static, �ߺ� ����, �ٸ� ���Ͽ��� �Լ� Ÿ�� �̸� �ߺ� ���� Ȯ��
// �̷� �ߺ� ������ ���ϱ� ���� namespace�� Ȱ���� ���̴�...