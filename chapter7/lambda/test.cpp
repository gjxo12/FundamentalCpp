int A(double a,double b) {return (int)(a+b);}

template<typename RT, typename ...ATs> // 템플릿 가변인자를 사용하기 위함 ...ATS는 typename이 가변 갯수만큼
RT TFunc(ATs... args)
{
    return A(args...);
}

void test()
{
    int R = TFunc<int, double, double>(3.2,3.8);
}