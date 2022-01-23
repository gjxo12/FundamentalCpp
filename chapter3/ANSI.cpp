#include "../include/Macro.h"
//#include "Trace.h"

int ANSI()
{
	std::cout << D_FILE_NAME << "\n";
	std::cout << S1_FILE_NAME << "\n";
	std::cout << S2_FILE_NAME << "\n";
	//실행 결과로 알 수 있는것
	//매크로 전개는 컴파일 되는 대상에 대해 일어남 -> Macro.h
	return 0;
}

int ANSI_main()
{
	//A_Trace;
	//B_TRACE();
	//매크로 방식이 제대로 동작함
	//여기서 사용해야 하는것은 매크로 방식으로 사용되는 A_Tracer가 알맞음
	
	return 0;
}