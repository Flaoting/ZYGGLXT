#ifndef SALARYTABLE_H_
#define SALARYTABLE_H_
#include "FatherTable.h"
/*********************************************************
��ʦ�Ĺ��ʱ��������ݲ�
*********************************************************/

class SalaryTable 

{
protected:

	char ownerName[20];//����������

	int ownerID;//�����ߵ�״Ԫ��Ψһʶ���
	
	int totalSalary; //��нˮ

	void caculateSalary();  //������нˮ
public:
	
	SalaryTable();
	~SalaryTable();
	void showAllTable();	//չʾ��λ��ʦ�����пα�
	void briefShow();		//���м�̵�չʾ

};
#endif // !SALARYTABLE_H_
