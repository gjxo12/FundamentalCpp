#ifndef __Common__
#define __Common__
// 빌드: 최종 목적 바이너리를 생성하기 위한 전처리, 컴파일, 링크의 과정
// 링크: 수많은 목적 파일들이 프로세스 메모리 가상 공간에 있을떄 서로가 맞물릴 수 있도록 주소를 변경해줌
// 전처리: include.. "__": 동일한 디렉토리 탐색, <>면 INCLUDE환경봔수랑 /I 옵션 

int g_CommonValue;     //링크 에러(중복)
static int g_StaticValue; // 각 오브젝트파일에서만 유효한 전역 변수
void FuncCommon()      //링크 에서(중복)
{

}
//전역 변수와 함수가 중복으로 정의되어 링크 에러 발생,
//staticㅇ은 각 오브젝트 파일에서만 유효함!
//그래서 ㄷ전역 변수는 extern, 함수는 본체 없이, 정의 말고 선언!!

#endif