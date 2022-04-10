#include "chapter6/copyoperation/copy.h"
#include "chapter6/copyoperation/copy2.h"
#include "chapter6/copyoperation/copy3.h"
#include "chapter6/copyoperation/rvalueRef.h"
#include "chapter6/copyoperation/equal.h"

void copyop()
{
    copy::CTest t0;
    t0.m_Value = 3;

    copy::CTest t1(t0); // 복사 생성자 호춯
    t1.ShowValue();

    copy::CTest t2 = t0; // 복사 생성자 호출 - 외우자-
    t2.ShowValue();

    copy::CTest t3;
    t3 = t0;
    t3.ShowValue();

    // 출력을 보면 복사 생성자 본체는 아무것도 안한다.. 
    // 명시적 복사 생성자 동작
    // 초기화 리스트를 통해 다른 생성자를 호출하지 않는 한
    // 선처리 영역에서는 부모 클래스와 맴버 클래스의 기본 생성자가 호출
    std::cout << "==================================================\n";
    //copy2.h
    copy2::CTest tt0;
    tt0.m_Value = 3;

    copy2::CTest tt1(tt0); // 암시적인 복사 생성자 
    tt1.ShowValue();

    copy2::CTest tt2 = tt0; // 암시적인 복사 생성자
    tt2.ShowValue();

    std::cout << "===================================================\n";
    //copy2 operator =
    copy2::CTest ttt0;
    ttt0.m_Value = 5;

    copy2::CTest ttt1(ttt0); // 암시적 복사 생성자: 기본 타입 메모리 복사 
    ttt1.ShowValue();

    copy2::CTest ttt2 = ttt0;// 암시적 복사 생성자: 기본 타입 메모리 복사
    ttt2.ShowValue();

    copy2::CTest ttt3;
    ttt3 = ttt0;
    ttt3.ShowValue();

}

void copyarr(){
    copy::CTestArr A;
    A.m_Array[0] = 1;
    A.m_Array[1] = 2;
    A.m_Array[2] = 3;

    copy::CTestArr B = A;
    // B의 맴버에 똑같이 복사가 된다.
    // 배열 전체의 메모리 영역을 통으로 복사 가능
}

void copyPointer()
{
    std::cout << "======== copyPointer ==========\n";
    copy3::CTest* pA = new copy3::CTest; // new에 의해 생성자 호출
    
    copy3::CTest B = *pA; // 암시적 복사 생성자..
    std::cout << B.m_RefVal << "\n";
    std::cout << *B.m_pInt << "\n";

    pA ->m_Val = 3;
    std::cout << B.m_RefVal << "\n";

    delete pA;
    
    //포인터는 값 복사, 참조 타입 변수에 대해 대상 복사
    // -> B..m_Refval은 pA->m_Val의 별칭!
    // 깊은 복사로 해야함.. 
}

void Equal(){
    equal::CTest t1 = 3;
    equal::CTest t2;
    t2 = 3;
    // 클래스 타입에서 등가 연산을 직접 정의해야만 등가 비교 가능
    if(t1 == t2){

    }
}

int main(int argc,char *argv[]){
    copyop();
    copyarr();
    copyPointer();
    CText t = GetText(); // 깊은 복사로 생성할텐데.. 
    Equal();
}

// 생성자 호출, 선처리 영역 등 잘 생각하기
// 맴버 변수가 있을때 잘 생각하기