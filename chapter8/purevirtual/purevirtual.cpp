/**
 * 순수 가상 함수: 절대 객체를 생성할 일도.. 함수를 호출할 일도 없는 인터페이스
 *
 */
#include "chapter8/purevirtual/purevirtual.h"
#include "chapter8/purevirtual/foo.h"

using chapter8::purevirtual::CTest;
using chapter8::purevirtual::CChildA;
using chapter8::purevirtual::CChildB;
using chapter8::purevirtual::CChild;

void main()
{
  foo();
  CTest* pIInterace = NULL;

  pIInterace = new CChildA;
  pIInterace->VFunc();

  pIInterace = new CChildB;
  pIInterace->VFunc();

  // 이같이 CTest의 객체를 생성할 필요가 없는 장점!!
  // 순수 가상함수가 있다는것은 인터페이스 타입으로만 사용하겠다 이것이 추상클래스 -> 이는 객체가 생성될수 없다! 
  // -> 절대로 호출되어서는 안된다!!!

  CChild c; // 이런식으로 막 우회해서 순수 가상 함수를 호출할수 있긴 있다.. 하지만 하지말자.. 제발..
}