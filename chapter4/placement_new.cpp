#include <iostream>
#pragma warning(disable:4996)

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

void cvs_class()
{
	CPerson* pPerson = new CPerson;
	pPerson->m_Name = "Kim dong hwan";
	
	char* name = "KIM Park";
	CVSPerson* pVSPerson = (CVSPerson*)malloc(sizeof(CVSPerson) + strlen(name));
	//가변 크기 클래스 객체 생성

	pVSPerson->m_Name[0] = NULL;
	strcat(pVSPerson->m_Name, name);
	
}

int placemnet_new()
{
	char* name = "place class test";
	void* pData = malloc(sizeof(placeclass) + strlen(name));
	//malloc으로 실제 객체의 크기만큼 메모리만 할당 받기

	placeclass* pl = new (pData)placeclass;
	//이런식으로 할당된 메모리 주소 넣기!
	// new (pointer of memory bloc) TYPE

	strcat(pl->m_Name, name);
	return 0;
}