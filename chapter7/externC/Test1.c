#include "chapter7/externC/externC.h"

void Func(int arg);
void Func1() {}
void Func2() {}
void Func3() {}
void main()
{
    Func(1);
    /**
    * 위에서 에러도 뜨고 빌드하면 에러가 발생함
    * 외부(Test.cpp)에서 Func를 찾아야 하는데..
    * Name Maangling된 형식이 C / C++이 다르기 때문에
    * 

    *   C는 _Func란 이름으로 찾으려 하구
    *   C++은 _Z... 이란 이름으로 오브젝트에 기록했기 때문에 링크 에러!
    * 그래서 C 형식으로 맞춤. c++ 은 C Name Mangling을 사용할수 있기 때문
    */


   /*
   * 왜 헤더 파일에 extern C 를 했는데 에러가 발생하는가..? 
   * __cplusplus 매크로를 사용한다!
   * 왜 사용하는가? 생각해보면 쉽다!
   */
}