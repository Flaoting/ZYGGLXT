#ifndef RUNNINGRECORD_H_
#define RUNNINGRECORD_H_
#include "Record.h"
#include <string>
using namespace std;

/**************************************************************
	����˵��
	������ˮ���࣬��Ҫ��¼�����ճ����������繺��ˮ�Աʣ�Ͱװˮ��
	��Ҫ��¼��Ϣ ������Ա��Manager ���� Teacher �� 
***************************************************************/

class RunningRecord :public Record 

{
protected:

	float payment;			// �˴η���
	char collectWay[20];	// ֧����ʽ
	char remarks[100];		//��;��ע
	char payer[30];			//֧����˵�����Ƿ��ǹ���Ա����

public:

	RunningRecord(Manager&, float pay, string Remarks
		, string payer = "����Ա����", string collect = "΢��֧��");

	~RunningRecord();
	

	RunningRecord(const RunningRecord&);

	RunningRecord operator= (const RunningRecord&);
	
	//����һ����ֵ��

};
#endif // !RUNNINGRECORD_H_
