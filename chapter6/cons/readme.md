```c++
class Point{
    public:
    int x;
    int y;
};

struct Point{
    int x;
    int y;
}

void main()
{
    Point pt;
    pt.x = 100;
    pt.y = 200;
}
```

다들 잘 알다시피 c++에서 클래스와 구조체의 차이는 public이냐 private이냐 이다.

여기서 class Point는 생성자 / 소멸자가 있는 것일까..?
이 절에서는 암시적 생성자와 소멸자의 원리를 알아보자

간단히, 명시적으로 정의되어 있지 않을때, 필요하지 않다면 단연 정의하지 않는다.

예시를 확인할수 있다. --> `ImplConstructor.cpp / ImplDestructor.cpp` 

### 선처리 영역 / 후처리 영역
`call.h`
```
CChild()

[선처리 영역이 존재]: 부모 클래스 생성자 호출, 맴버가 클래스 타입일 경우 생성자 호출...
... 기타 선처리...   이 같은 내부동작이 있음

{
    std::cout << "CChiled - Constructor"
}
~CChiled() {....}


[후처리 영역 존재]: 맴버가 클래스 타입일 경우 소멸자 호출, 부모 클래스 소멸자 호출...
... 기타 후처리... 이 같은 내부동작이 있음

```