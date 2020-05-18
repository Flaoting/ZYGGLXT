#ifndef QUERYRECORD_H_
#define QUERYRECORD_H_
#include "RunningRecord.h"
#include "ViolationRecord.h"
#include "TransactionRecord.h"
#include "RecordInfo.h"


/*****************************************************


	���ǲ�ѯ�α�Ĳ���̨��ֻ�ܱ�handler������

	�ܹ���ѯ������¼��������ˮ�ˣ���ʦΥ���¼
	��Ҫ����Ĳ����ǵڼ�����¼
	����������͵�record
	ע��������¼��������ѯ·�ߣ��ڶ�������

	��Ϊ���׼�¼���͵���û��Ĭ�Ϲ��캯����������Ҫ����һ����ʱ�Ķ���
	�����вι��죬��Ȼ�����¼���������
	
	Ϊ�˺����ļ���ԣ����ļ�ʧ�ܻ��׳��쳣,Ҫ�ǵô���

******************************************************/

class QueryRecord 

{
protected:

	friend class Handler;			//ֻ��ͨ����Ԫ����÷���

	
	RunningRecord getRunningRecord(int ruler=1);
	ViolationRecord getViolationRecord(int ruler=1);
	TransactionRecord getTransactionRecord(int ruler=1);
	TransactionRecord getHidenTransactionRecord(int ruler = 1);

public :
	
	QueryRecord();
	~QueryRecord();

};

#endif // !QUERYRECORD_H_


