#include <iostream>

extern int g_val;
//extern int s_val;
//
int g_val2;
class CTest;

int main()
{
    //int g_val = 1;
    //s_val = 2;
    //std::cout << "extern: " << g_val << "  static: " << s_val;
    
    g_val2 = 1; 
    std::cout << "chapter2 Extern_static...." << g_val << "\n";
    /*
    CTest t;
    t.m_val = 1;
    Ŭ������ �� ���Ͽ� CTest�� ���Ǹ� ������Ѵ�. �� �ҽ����ϸ���...
    �׷��� ������Ͽ� �ۼ��ϰ� �ҽ� ���Ͽ��� ����� �����ϴ� ������� �ۼ�
    class_def ���丮���� �ߺ� Ŭ���� ���Ǹ� ���캸��.
    */
}