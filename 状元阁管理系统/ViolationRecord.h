/********************************************************************
	
			��ʦΥ���¼����
	�̳���Record ����Unixʱ�����Manager
	��¼�˽�ѧ�¹ʵļ�¼
	����ʱ�䣬�¹ʵ�һ�ڶ�����
	��һ�����ǽ�ѧ�¹ʵĵȼ� 
	�ڶ������ǽ�ѧ�¹ʵľ����¼�
	���ڼ�¼�������Ӻ��ԣ�����������Date�࣬���з���ʱ��ļ�¼

*********************************************************************/
#ifndef VIOLATIONRECORD_H_
#define VIOLATIONRECORD_H_

#include "Date.h"
#include "Record.h"
#include "Teacher.h"

class ViolationRecord :public Record 
{
protected:
	
	Teacher VioTeacher;
	int FirstVioCode;
	int SecondCVioCode;
	Date OccurTime;
	char Remarks[100];//��ע����������ѧ�¹�

public : 
	
	ViolationRecord(Manager&,Teacher &,int first,int second,Date d,string remark );
	~ViolationRecord();
	ViolationRecord(const ViolationRecord&);
	ViolationRecord operator =(const ViolationRecord&);
	void display();
};

#endif







