#ifndef OPERATETABLE_H_
#define OPERATETABLE_H_
#include "OperateMode.h"
#include "Table.h"
#include "stdafx.h"
#include "TableInfo.h"	//�����ļ��ĵ�ַ

class OperateTable : public OperateMode 
{
	//����ѧ���α����

protected :

	Table table;
	TableInfo saveAddress;

	bool checkIsThisTable();
	bool changeThisTable();
	bool addLesson();
	bool deleteLesson();

	int checkHowLongBelonging(Table TEATab);

public:

	OperateTable( Table &tab);
	OperateTable();
	~OperateTable();

	//�Ը����麯��������д 

	virtual bool readPreFile();			//��ȡǰ���ļ��������ݶ�������ǰ��Table
	
	virtual bool saveThisFile();		//���浱ǰ�ļ����ѵ�ǰ��Table�����ļ�
	
	bool saveThisFile(int ruler);

	bool readPreFile(string name);

	bool readPreFile(string name, int ordinal);//��������˵ĵڼ����α�
	
	bool updateThisTable();                //��������α�

	bool transformSTToCSV();

	bool transformTTToCSV();

	Table getTable();			//���������table����

};
#endif // !OPERATETABLE_H_

