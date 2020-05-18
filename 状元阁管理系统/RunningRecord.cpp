#include "RunningRecord.h"
#include <iostream>
#include <iomanip>
using namespace std;


RunningRecord::RunningRecord(Manager& man, float pay, 
	string Remarks, string payer , string collect )
	:Record(man)
{
	this->payment = pay;
	strcpy_s(this->remarks, Remarks.c_str());
	strcpy_s(this->payer, payer.c_str());
	strcpy_s(this->collectWay, collect.c_str());
}

RunningRecord::~RunningRecord(){}


RunningRecord::RunningRecord(const RunningRecord& obj) :Record(obj)
{
	this->payment = obj.payment;
	strcpy_s(this->remarks, obj.remarks);
	strcpy_s(this->payer, obj.payer);
	strcpy_s(this->collectWay, obj.collectWay);
}

RunningRecord RunningRecord:: operator= (const RunningRecord& obj) 

{
	Record::operator=(obj);
	this->payment = obj.payment;
	strcpy_s(this->remarks, obj.remarks);
	strcpy_s(this->payer, obj.payer);
	strcpy_s(this->collectWay, obj.collectWay);
	return *this;

}


void RunningRecord::display()
{
	string When = TimeStampToStandard(this->timeStamp);
	cout << "��¼ʱ�� :  " << When;
	cout << "��֧���� :  " << this->payment << endl;
	cout << "��֧��; :  " << this->remarks << endl;
	cout << "��¼��   :  " << this->payer << endl;
	cout << "�Ƿ�鿴�˴μ�¼�Ĺ���Ա��Ϣ��֧����ʽ��" << endl;
	if (checkToContinue()) 
	{
		cout << "֧����ʽ :  " << this->collectWay << endl;
		cout << "��¼����Ա��Ϣ����ϸ��Ϣ :  " << endl;
		this->operatorManager.display();
	}

}


void RunningRecord::shortShow()
{
	string When = TimeStampToStandard(this->timeStamp);

	cout << setw(5)  << this->payment
		 << setw(15) << this->remarks
		 << setw(20) << When
		 << endl;
}