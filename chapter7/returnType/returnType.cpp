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

CTest &Func_ref(){
    CTest tt;
    tt.m_V = 1;
    return tt;
    // eax = &tt: 주소를 eax에 대입
    // 어셈블리가 매우 간단해짐, 성능이 월등히 좋음
    // 클래스를 반환할때 거의 대부분 참조타입.
}

CTest2 Func2() {
    CTest2 t2;
    t2.m_V = 1;
    //t영역 12byte 확보
    return t2;
    // 8바이트보다 큰 클래스 반환 타입이라면??
    // CTest의 크기가 12라면 두 배 크기인 24를 스택에 마련해 놓을것이다.
    // 처음 12는 반환 임시 영역으로 호출하는 함수:caller 가 반환 값을 임시로 저장하기 위해 설정하는 영역
}

/*
 * 반환 타입이 클래스일 경우..
 * 컴파일러는 스택에 임시로 ㅋ클래스 크기만큼 영역을 확보함
 * 간단하게 caller 는 반환 인자 영역을 callee에게 전달
 * callee는 반환 인자 영역에 반환 값을 복사하고 종료
 * 그 후 caller는 반환 인자 영역에서 반환 임시 영역으로 반환 결과를 옮김
 * 컴파일러는 최적화를 수행할텐데.. 우리는 동작 원리를 보고싶다..
*/


