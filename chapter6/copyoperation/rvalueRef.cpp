#include "chapter6/copyoperation/rvalueRef.h"

CText GetText()
{
    CText temp("Hello Men..\n");
    return temp; //이 temp가 소멸될것이다..
}