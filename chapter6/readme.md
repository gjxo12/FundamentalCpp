### 클래스에서의 상속 접근 지정자


부모------------자식 
- public    : public    protected    private
- protected : protected protected    private
- provate   : X          X           X

### 정적 맴버의 상속

```c++
class CTest
{
    public:
    static int s_Value;
};
void main()
{
    CTest t1, t2;
    t1.s_Value = 1;   
    t2.s_Value = 2;
    CTest::s_Value = 3;
    // 위 3줄은 모두 s_Value를 바라보며 최종적으로 하나뿐인 s_Value는 3이다.
    // 링크 에러가 발생: 선언만 되어있지 정의가 안되어잇다... static 키워드..
    // int CTest::s_Value -> 전방선언... 그래서 클래스 외부 정의에 이렇게..
}
```

### 접근 지정자를 사용한 Static 변수: `staticmember.h`

- 정적 맴버 변수가 정의되면서 객체 / 생성자 호출
- 정적 맴버 변수(`static CTestA s_A;`) 생성자 호출은 정적 맴버가 선언된 클래스이다. 
- 즉, 이 맴버가 선언된 클래스가 해당 정적 맴버의 생성자를 호출할수 있는가? 접근 가능한가?
```c++
class CTestA
{
    private:
    CTestA() {}
};
class CTestB
{
    private:
    CTestB() {}
    public:
    static CTestA s_A;
    static CTestB s_B;
    // 생성자 호출 환경이 여기 CTestB이다.
};
CTestA CTestB::s_A; // CTestA의 생성자가 private..
CTestB CTestB::s_B; // 생성자가 호출되는 환경이 cTestB에서.. 이것이 싱글톤
```

### 기본 클래스 함수의 상속
- 이제껏 생성자, 소멸자, 대입 연산자, 타입 변환 연산자 확인
- 일반 맴버 함수와 위의 기본 클래스 함수들의 상속 관계
- **생성자는 상속되지 않는다**: 자식 클래스가 생성되는순간 부모 클래스의 생성자 호출, 이것이 상속은 아니다.
- **대입 연산자도 상속이 안된다**