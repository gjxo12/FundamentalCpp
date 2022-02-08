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
    if(strcpy(pVSPerson->m_Name,str)){
        return 1;
    }
    else{
        return 0;
    }
}

int bar(char* str)
{
	char* name = str;
	void* pData = malloc(sizeof(placeclass) + strlen(name));
	placeclass* pl = new (pData)placeclass;
	strcat(pl->m_Name, name);
    if(strcpy(pl->m_Name,str)){
        return 1;
    }
    else{
        return 0;
    }
}

TEST(Placement, fist){
    EXPECT_EQ(1, foo("Hi This is Test"));
}
TEST(Placement, second){
    EXPECT_EQ(1, bar("Hi This is Test"));
}


