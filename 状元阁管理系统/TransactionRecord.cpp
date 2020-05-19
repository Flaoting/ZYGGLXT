#include "TransactionRecord.h"

TransactionRecord::TransactionRecord
	(Manager& man, Student& stu, float pay , string CW , string R )
	:Record(man),stud(stu)

{
	this->payment = pay;
	strcpy_s(this->collectWay, CW.c_str());
	strcpy_s(this->remarks, R.c_str());
}

TransactionRecord::~TransactionRecord(){}

TransactionRecord::TransactionRecord(const TransactionRecord& obj):Record(obj),stud(obj.stud)

{
	this->payment = obj.payment;
	strcpy_s(this->collectWay, obj.collectWay);
	strcpy_s(this->remarks, obj.remarks);
}

TransactionRecord TransactionRecord::operator=(const TransactionRecord& obj)

{
	Record::operator=(obj);
	this->stud = obj.stud;
	this->payment = obj.payment;
	strcpy_s(this->collectWay, obj.collectWay);
	strcpy_s(this->remarks, obj.remarks);
	return *this;
}

void TransactionRecord::display()
{
	string When = TimeStampToStandard(this->timeStamp);
	cout << "����ʱ�� :  " << When << endl;
	cout << "ѧ��     :  " << stud.getName() << endl;
	cout << "���׽�� :  " << this->payment << endl;
	cout << "�տʽ :  " << this->collectWay << endl;
	cout << "�տע :  " << this->remarks << endl;
	cout << "�Ƿ���ʾ�˴ν����˵���ϸ��Ϣ?" << endl;

	if (checkToContinue()) 
	{
		cout << "�˴ν���ѧ������ϸ��Ϣ����:  " << endl;
		this->stud.display();
		cout << "�˴ν��׵Ĺ���Ա����Ϣ����:  " << endl;
		this->operatorManager.display();
		cout << endl;
	}
	return;
}

void TransactionRecord::shortShow()
//���һ��
{
	string When = TimeStampToStandard(this->timeStamp);
	cout << setw(5)  << stud.getName()
		 << setw(6)  << this->payment
		 << setw(20) << When
		 << endl;
}




float TransactionRecord::getPayment()
{
	return this->payment;
}
