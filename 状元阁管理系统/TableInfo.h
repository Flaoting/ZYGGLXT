#ifndef TABLEINFO_H_
#define TABLEINFO_H_
#include "BaseFile.h"
#include "STDInfo.h"
class TableInfo : public STDInfo

	//Ϊ�˱��⴫�ݺܶ���������ж��Info��Ĵ���

{
public:

	TableInfo(string Name);

	TableInfo();

	virtual ~TableInfo();

	TableInfo operator = (const TableInfo&);

	void setName(string Name);
	void GiveTeacherALife( );

	void ForTeacherCSV(string name);
	void ForStudentCSV(string name);
};

#endif // !TABLEINFO_H_
