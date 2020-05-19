#include "QueryRecord.h"

QueryRecord::QueryRecord() 
{
	//���캯�����������
}


QueryRecord:: ~QueryRecord() 
{
	//�����������������
}



RunningRecord QueryRecord::getRunningRecord(int ruler)
{

	Manager temp;
	RunningRecord Running(temp,0,"test");

	int t = (ruler - 1) * sizeof(Running);

	RecordInfo ADD("RunningRecord");

	ifstream file;

	file.open(ADD.getCompleteAddress(), ios::binary | ios::in);

	if (!file)
	{
		cout << "Warning ��ˮ��¼�ļ���ʧ��  " << endl;
		cout << "�����Ƿ����·��" << ADD.getCompleteAddress() << endl;
		throw 4585;
	}
	file.seekg(t, ios::beg);

	if (file.eof())
	{
		file.close();
		throw 3131;
	}
	file.read((char*)&Running, sizeof(Running));
	
	file.close();
}

ViolationRecord QueryRecord::getViolationRecord(int ruler)
{
	Manager temp;
	Teacher test;
	Date d;
	ViolationRecord Violation(temp,test,0,0,d,"test");

	int t = (ruler - 1) * sizeof(Violation);

	RecordInfo ADD("ViolationRecord");
	ifstream file;

	file.open(ADD.getCompleteAddress(), ios::in | ios::binary);

	if (!file)
	{
		cout << "Warning ��¼�ļ���ʧ��  " << endl;
		cout << "�����Ƿ����·��" << ADD.getCompleteAddress() << endl;
		throw 4558;
	}

	file.seekg(t, ios::beg);
	if (file.eof())
	{
		file.close();
		throw 3131;
	}
	file.read((char*)&Violation, sizeof(Violation));

	file.close();

	return Violation;
}



TransactionRecord QueryRecord::getTransactionRecord(int ruler)
{

	Manager temp;
	Student test;
	Date d;
	TransactionRecord Transaction(temp,test);

	int t = (ruler - 1) * sizeof(Transaction);

	RecordInfo ADD("TransactionRecord");
	ifstream file;

	file.open(ADD.getCompleteAddress(), ios::in | ios::binary );

	if (!file)
	{
		cout << "Warning �����ļ���ʧ��  " << endl;
		cout << "�����Ƿ����·��" << ADD.getCompleteAddress() << endl;
		throw 4558;
	}

	file.seekg(t, ios::beg);
	if (file.eof())
	{
		file.close();
		throw 3131;
	}
	file.read((char*)&Transaction, sizeof(Transaction));

	file.close();

	return Transaction;

}

TransactionRecord QueryRecord::getHidenTransactionRecord(int ruler)

{

	Manager temp;
	Student test;
	Date d;
	TransactionRecord Transaction(temp, test);
	
	int t = (ruler - 1) * sizeof(Transaction);

	RecordInfo SUM;
	ifstream file2;

	file2.open(SUM.getCompleteAddress(), ios::in | ios::binary);

	if (!file2)
	{
		cout << "Warning �����ļ���ʧ��  " << endl;
		cout << "�����Ƿ����·��" << SUM.getCompleteAddress() << endl;
		throw 4558;
	}

	file2.seekg(t, ios::beg);
	if (file2.eof())
	{
		file2.close();
		throw 3131;
	}
	file2.read((char*)&Transaction, sizeof(Transaction));

	file2.close();

	return Transaction;

}


