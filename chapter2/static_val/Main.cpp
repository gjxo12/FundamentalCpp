#include <iostream>

extern int g_A;

int GetTwo() {return 2;}

int main()
{
    static int s_a;
    static int s_b = 0;
    static int s_c = 1;
    static int s_d = GetTwo(); // �� ģ���� ���� ������ �޸� �ʱ�ȭ ������.. �� �ٸ�
    // 
    std::cout << s_a << "  " << s_b << "  " << s_c << "  " << s_d << "\n"; 

    std::cout << "=========================================================================\n";

    std::cout << g_A << "\n";  // �� �׻� 2�� �������� �ʴ´�...1�� ���ü� ����
    // g_B�� �⺻������ 0�̹Ƿ�  
    // g_B�� ���� �ʱ�ȭ�ǵ��� �Ѵ� -- �ּ��� �ƴ� �κе�..

}