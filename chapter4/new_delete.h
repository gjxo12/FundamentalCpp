#pragma once
class CTest
{
public:
	CTest() {
		//std::cout << "CTEST : class crerator....." << "\n";
	}
	~CTest() {
		//std::cout << "CTEST : class destroy....." << "\n";
	}
	int m_value = 0;
};

class CTEST_B
{
public:
	CTEST_B() {
		std::cout << "CTEST_B : class crerator....." << "\n";
	}
	~CTEST_B() {
		std::cout << "CTEST_B : class destroy....." << "\n";
	}
};

class Cparent
{
public:
	~Cparent() {}
};

class CChild: public Cparent {
public:
	int m_value=0;
};