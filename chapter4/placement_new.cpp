#include <iostream>
#pragma warning(disable:4996)

class CPerson
{
public:
	char* m_Name;
};

class CVSPerson //�̰� ���� ũ�� Ŭ����
{
public:
	char m_Name[1];
};

// ���� ���̴� �������� ��ġ!!!
// ���� ������ ������ ����Ű�� ������, �Ʒ��� Ŭ���� ��ü �޸𸮿� ���� Ŭ������ ������ ��� ���
// �Ʒ��� ����: ���� ��ü������ ũ�⸸ŭ �޸𸮸� ������ �Ǽ� ������尡 ����..���� ��� ���� ����(�޸𸮺���)..
// �ٵ� ���.. ���� ������ �ɹ��� ���ؼ��� �迭 Ÿ������ �����ؾߵǰ�.. �� �� �̻��� �Ұ���..

class placeclass
{
public:
	placeclass() {
		m_age = 1;
		m_Name[0] = NULL; //strcat�� ����
	}
	int m_age;
	char m_Name[1];
};
//��ó�� ���� Ŭ������ �����ڰ� �߰�

void cvs_class()
{
	CPerson* pPerson = new CPerson;
	pPerson->m_Name = "Kim dong hwan";
	
	char* name = "KIM Park";
	CVSPerson* pVSPerson = (CVSPerson*)malloc(sizeof(CVSPerson) + strlen(name));
	//���� ũ�� Ŭ���� ��ü ����

	pVSPerson->m_Name[0] = NULL;
	strcat(pVSPerson->m_Name, name);
	
}

int placemnet_new()
{
	char* name = "place class test";
	void* pData = malloc(sizeof(placeclass) + strlen(name));
	//malloc���� ���� ��ü�� ũ�⸸ŭ �޸𸮸� �Ҵ� �ޱ�

	placeclass* pl = new (pData)placeclass;
	//�̷������� �Ҵ�� �޸� �ּ� �ֱ�!
	// new (pointer of memory bloc) TYPE

	strcat(pl->m_Name, name);
	return 0;
}