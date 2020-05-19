#ifndef  TRANSACTIONRECORD_H_
#define  TRANSACTIONRECORD_H_
#include "Record.h"
#include "Student.h"
#include "stdafx.h"
class TransactionRecord :public Record

	//���׼�¼��

{
protected:
	
	Student stud;    //ѧ��������Ϣ
	float payment;	// ���ɷ���
	char collectWay[20]; // �տʽ
	char remarks[100]; //�տע

public:
	
	//�������޲ι��캯��

	TransactionRecord(Manager&, Student&, float pay=0,string CW="�ֽ��տ�",string R="��");
	
	virtual ~TransactionRecord();
	
	TransactionRecord(const TransactionRecord&);
	
	virtual TransactionRecord operator =(const TransactionRecord&);

	void display();

	void shortShow();

	float getPayment();
};

#endif // ! TRANSACTIONRECORD_H_




