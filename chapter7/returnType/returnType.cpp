#include "chapter7/returnType/returnType.h"

using chapter7::returnType::CTest;
using chapter7::returnType::CTest2;

CTest Func() {
    CTest t;
    t.m_V = 1;
    // t영역의 8 byte 확보
    return t;
    //여기서 반환 값을 설정: assembly 확인!
    // eax = t.m_E
    // edx = t.m_V
    
}

CTest2 Func2() {
    CTest2 t2;
    t2.m_V = 1;
    //t영역 12byte 확보
    return t2;
}


/*
 * 반환 타입이 클래스일 경우..
 * 컴파일러는 스택에 임시로 ㅋ클래스 크기만큼 영역을 확보함
 * 
*/


