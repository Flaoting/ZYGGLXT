#ifndef SALARYTABLE_H_
#define SALARYTABLE_H_
#include "OperateTable.h"
#include "Student.h"
#include "Teacher.h"
#include "ConClassPrice.h"
/*********************************************************
��ʦ�Ĺ��ʱ��������ݲ�
*********************************************************/

class SalaryTable 

{
protected:
	
	int totalSalary;		//��нˮ

	Teacher teacher;		//��ʦ������

	void caculateSalary();  //������нˮ
	
	
	int HowMuchInShort();

	int getClassTypeOutPrice(int key);

	int HowMuchInDisplay();

public:
	
	SalaryTable(Teacher &);
	
	SalaryTable(const SalaryTable&);
	
	~SalaryTable();
	
	SalaryTable operator =(const SalaryTable&);

	void showAllTable();	//չʾ��λ��ʦ�����пα�
	void briefShow();		//���м�̵�չʾ

};
#endif // !SALARYTABLE_H_


