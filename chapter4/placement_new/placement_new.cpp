#include <iostream>
#include <string.h>
#include <memory>
// GCC에서 placement new를 사용하기 위함, vs에서는 사용한 곳 앞뒤에 매크로 사용
/*
  #pragma push_macro("new")
  #undef new
  ....
  #pragma pop_macro("new")
*/
class CPerson
{
public:
	char* m_Name;
};

class CVSPerson //이게 가변 크기 클래스
{
public:
	char m_Name[1];
};

// 둘의 차이는 데이터의 위치!!!
// 위는 데이터 영역을 가리키는 포인터, 아래는 클래스 객체 메모리에 실제 클래스의 정보가 모두 담김
// 아래의 장점: 실제 객체으ㅐㅣ 크기만큼 메모리만 읽으면 되서 오버헤드가 없다..또한 얘는 얕은 복사(메모리복사)..
// 근데 얘는.. 가장 마지막 맴버에 대해서만 배열 타입으로 선언해야되고.. 두 개 이상은 불가능..

class placeclass
{
public:
	placeclass() {
		m_age = 1;
		m_Name[0] = NULL; //strcat을 위함
	}
	int m_age;
	char m_Name[1];
};
//이처럼 가변 클래스에 생성자가 추가


int placemnet_new()
{
	// new (ponter of memory Block) Type

	char* name = "place class test";
	void* pData = malloc(sizeof(placeclass) + strlen(name));
	//malloc으로 실제 객체의 크기만큼 메모리만 할당 받기

	placeclass* pl = new (pData)placeclass;
	//이런식으로 할당된 메모리 주소 넣기!
	// new (pointer of memory bloc) TYPE

	std::cout << strcat(pl->m_Name, name) << "\n";
	std::cout << pl->m_Name << "\n";
	return 0;
}

int main()
{
	CPerson* pPerson = new CPerson;
	pPerson->m_Name = "Hong gildong";
	
	char* name = "KIM Hansu";
	CVSPerson* pVSPerson = (CVSPerson*)malloc(sizeof(CVSPerson) + strlen(name));
	//가변 크기 클래스 객체 생성

	pVSPerson->m_Name[0] = NULL;
	std::cout << strcat(pVSPerson->m_Name, name) << "\n";
	std::cout << pVSPerson->m_Name << "\n";
	placemnet_new();
}
