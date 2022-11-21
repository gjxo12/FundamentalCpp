#include "chapter8/inheritanceVitrual/inheritanceVitrual.h"

using chapter8::inheritanceVitrual::CParent;
using chapter8::inheritanceVitrual::CChild;
using chapter8::inheritanceVitrual::C;

int main()
{
    CChild c;
    CParent* pParent = &c; 
    // pParent는 CParent* 타입이지만, 얘의 실제 객체는 vfptr의 CChild 가상함수 테이블을 가리킴..
    // 컴파일러는 VFunc가 가상 함수 테이블의 몇번째 항목인지 정보를 기억하게됨

    pParent->VFunc();
    // 가상 함수는 오직 vfptr이 가리키는 VTable과 가상 함수의 인덱스 정보만으로 호출한다..!!

    C cc;
    // 자 여기서 VTable이 어떤 모양일까..? 그려봐야 한다!

}

/**
 * 실제 타입의 가상함수가 호출되는 원리는..?
 * 중요: vfptr은 하나만 존재한다 -> 클래스 메모리 시작 위치에... -> 다중 상속 가상함수에서 정의를 깬다!
 */