#ifndef __MEMBER__H
#define __MEMBER__H

#include<iostream>
#include<stddef.h>

class CTest
{
public:
	char m_char;
	int m_int;
	double m_double;
	
	static int m_sint;
	int memberfunc()
	{
		return m_int;
	}
}; // 실제 메모리 변수에는 일반 맴버 변수

void printoffset();
int class_struct();


class CEmpty
{
    public:
    CEmpty() {};
    ~CEmpty(){};
};

class CVirtualEmpty
{
public:
  CVirtualEmpty () {};
  virtual ~CVirtualEmpty() {};
};


#endif

