#ifndef  FATHER_TABLE_H_
#define FATHER_TABLE_H_
#include <string>
#include "People.h"
using namespace std;

class FatherTable 

	//����һ������࣬ӵ�б�ͷ��������������������ID
	//����������ʦ�Ŀα��ѧ���Ŀγ̱�Table����ʦ�Ĺ��ʱ� SalaryTable

{
protected :
	
	//char dataHeader[30];

	char name[20];//����������

	int ID;//�����ߵ�״Ԫ��Ψһʶ���

	string selfName;

public :

	FatherTable(People*);
	FatherTable();

	void display();//չʾһ��
	void saveFatherTable();//���浽�ļ���
	void updateFather();//����FatherTable
	
	virtual string getSelfName();

};

#endif // ! FATHER_TABLE_H_

