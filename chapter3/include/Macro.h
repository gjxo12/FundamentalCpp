//ANSI 호환 미리 정의된 매크로
// __FILE__  , __LINE__ : 주로 디버깅용,로깅용
// 현재 소스 파일 이름 __FILE__
#define D_FILE_NAME __FILE__ 
char S1_FILE_NAME[] = __FILE__;
char S2_FILE_NAME[] = D_FILE_NAME;



//컴파일된 헤더
//중복된 작업을 한번만 하도록!!
//VC: pch     gcc: gch
//거의 변하지 않는 내용을 단 한번만 컴파일하여 재활용