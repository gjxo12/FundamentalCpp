#include<iostream>

class CTestA
{
public:
    CTestA() {std::cout << "CTestA::Consturctor!  " << "\n" ;}
    ~CTestA() {std::cout << "CTestA::Destructor!  " << "\n";}
};

class CTestB
{
public:
    CTestB(){std::cout << "CTestB::Constructor! " << "\n";}
    ~CTestB(){std::cout << "CTestB::Destructor!  " << "\n";}
};

class CTestC
{
public:
    int m_value;
};

class CParent
{
public:
    ~CParent() {}
};
class CChild : public CParent
{
public:
    int m_Value;
};

int main()
{
    CTestA* pa = new CTestA;
    CTestB* pb = (CTestB*)pa;
    delete pb;
    // 대상 포인터의 타입만을 체크하여 타입과 일치하는 클래스의 소멸자를 호출한 뒤 메모리 영역 해제
    // 결국 new와 delete는 동적 생성 클래스 객체를 위한것

    std::cout << "======================================================\n";

    CTestA* Tarray = new CTestA[2];
    delete [] Tarray;

    // 어떻게 생성자 소멸자 2번인것을 알 수 있을까? 생성이야 2가 적혀있으니 문제없음
    // new [] delete [] 는 당연히 maalloc과 free를 그대로 사용하지 않음
    // new의 과정에서 메모리 크기에 추가적으로 4byte가 더 들어옴 -> 배열 요소 갯수 저장용
    // delete [] 하면 메모리주소에서 4를 빼고 그곳에서 요소 갯수를 확인

    std::cout << "======================================================\n";
    
    int* p = new int[2];
    CTestC* C = new CTestC[2];
    delete p;
    delete C; 
    // 소멸자가 없는 경우 int나 클래스(CTestC)나 소멸자의 [] 구분은 무의미
    // 여기서도 암시적 소멸자를 실행하지는 않는다

    return 0;
}
