#include <iostream>
#include <string.h>
#include <memory>
#include <gtest/gtest.h>

class CPerson
{
public:
	char* m_Name;
};

class CVSPerson 
{
public:
	char m_Name[1];
};

class placeclass
{
public:
	placeclass() {
		m_age = 1;
		m_Name[0] = NULL;
	}
	int m_age;
	char m_Name[1];
};
int foo(char* str)
{	
	char* name = str;
	CVSPerson* pVSPerson = (CVSPerson*)malloc(sizeof(CVSPerson) + strlen(name));
	pVSPerson->m_Name[0] = NULL;
	strcat(pVSPerson->m_Name, name);
    return strcmp(pVSPerson->m_Name,name);
}

int bar(char* str)
{
	char* name = str;
	void* pData = malloc(sizeof(placeclass) + strlen(name));
	placeclass* pl = new (pData)placeclass;
	strcat(pl->m_Name, name);
    return strcmp(pl->m_Name,name);
}

TEST(Placement, fist){
    EXPECT_EQ(0, foo("Hi This is Test"));
}
TEST(Placement, second){
    EXPECT_EQ(0, bar("Hi This is Test"));
}


