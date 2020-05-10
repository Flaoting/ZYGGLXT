#ifndef OPERATETABLE_H_
#define OPERATETABLE_H_
#include "OperateMode.h"
#include "Table.h"
#include "TableInfo.h"	//�����ļ��ĵ�ַ

class OperateTable : public OperateMode 
{
	//����ѧ���α����

protected :

	Table table;
	TableInfo saveAddress;

public:

	OperateTable( Table &tab);
	OperateTable();
	~OperateTable();

	//�Ը����麯��������д 

	virtual bool readPreFile();			//��ȡǰ���ļ��������ݶ�������ǰ��Table
	
	virtual bool saveThisFile();		//���浱ǰ�ļ����ѵ�ǰ��Table�����ļ�

	Table getTable();			//���������table����

};
#endif // !OPERATETABLE_H_

