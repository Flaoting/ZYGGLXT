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

	char ownerName[20];//����������

	int ownerID;//�����ߵ�״Ԫ��Ψһʶ���

	string selfName;  //

public :

	FatherTable(People*);

	FatherTable();
	FatherTable(const FatherTable&);
	FatherTable operator=(const FatherTable&);
	void display();//չʾһ��
	
	virtual string getSelfName();

	string getOwnerName();

	int getOwnerID();
};

#endif // ! FATHER_TABLE_H_

