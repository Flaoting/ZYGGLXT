#ifndef OPERATETABLE_H_
#define OPERATETABLE_H_
#include "OperateMode.h"
#include "Table.h"
#include "stdafx.h"
#include "TableInfo.h"	//�����ļ��ĵ�ַ
#include "AddTABMenu.h"
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

	virtual bool saveThisFile();		//���浱ǰ�ļ����ѵ�ǰ��Table�����ļ�
	
	bool saveThisFile(int ruler);

	virtual bool readPreFile();			//��ȡǰ���ļ��������ݶ�������ǰ��Table
	
	bool readPreFile(string name);

	bool readPreFile(string name, int ordinal);//��������˵ĵڼ����α�
	
	bool updateThisTable();                //��������α�

	bool transformSTToCSV();

	bool transformTTToCSV();

	void getTableFromScreen();

	void clearHidenTable();
	
	Table getTable();			//���������table����

	string getAddress();
};
#endif // !OPERATETABLE_H_

