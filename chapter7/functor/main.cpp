/**
 * Functor: 함수는 아니지만 함수처럼 사용할 수 있는 클래스?
 * operator()를 재정의하는데 의의
 * 정보의 관리라는 측면에서 객체 지향적
 */

#include<iostream>
#include<algorithm>

class CFunctor
{
    public:
    CFunctor() {m_Sum = 0;}

    int operator() (int arg) // () 표현 재정의
    {
        m_Sum += arg;
        return m_Sum;
    }

    int m_Sum = 0;
};

// STL구문들.. 간소화하고 빠르게 작성하기 위한 Template 코드들..
// 공부가 필요하다
template<class Iterator, class Functor> inline
Functor for_each(Iterator start, Iterator end, Functor func){
    for(; start != end; ++start){
        func(*start); // 반복을 수행하는 함수이다..
    }
    return func;
} 

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    
    CFunctor f; //
    for(int i=0;i<10;i++){
        f(arr[i]);
    }
    std::cout << f.m_Sum << "\n";
    std::cout << for_each(&arr[0],&arr[10],f).m_Sum << "\n";

    

}