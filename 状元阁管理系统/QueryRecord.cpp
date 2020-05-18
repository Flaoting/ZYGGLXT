#include "QueryRecord.h"

QueryRecord::QueryRecord() 
{
	//构造函数，无需操作
}


QueryRecord:: ~QueryRecord() 
{
	//析构函数，无需操作
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
		cout << "Warning 流水记录文件打开失败  " << endl;
		cout << "请检查是否存在路径" << ADD.getCompleteAddress() << endl;
		throw 4585;
	}
	file.seekg(t, ios::beg);

	file.read((char*)&Running, sizeof(Running));

	file.close();

	return Running;
}

ViolationRecord QueryRecord::getViolationRecord(int ruler)
{
	Manager temp;
	Teacher test;
	Date d;
	ViolationRecord Violation(temp,test,0,0,d,"test");

	RecordInfo ADD("ViolationRecord");
	ifstream file;

	file.open(ADD.getCompleteAddress(), ios::in | ios::binary);

	if (!file)
	{
		cout << "Warning 记录文件打开失败  " << endl;
		cout << "请检查是否存在路径" << ADD.getCompleteAddress() << endl;
		throw 4558;
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

	RecordInfo ADD("TransactionRecord");
	ofstream file;

	file.open(ADD.getCompleteAddress(), ios::out | ios::binary | ios::app);

	if (!file)
	{
		cout << "Warning 交易文件打开失败  " << endl;
		cout << "请检查是否存在路径" << ADD.getCompleteAddress() << endl;
		throw 4558;
	}

	file.write((char*)&Transaction, sizeof(Transaction));

	file.close();

	return Transaction;

}

TransactionRecord QueryRecord::getHidenTransactionRecord(int ruler)

{

	Manager temp;
	Student test;
	Date d;
	TransactionRecord Transaction(temp, test);

	RecordInfo SUM;
	ofstream file2;

	file2.open(SUM.getCompleteAddress(), ios::out | ios::binary | ios::app);

	if (!file2)
	{
		cout << "Warning 交易文件打开失败  " << endl;
		cout << "请检查是否存在路径" << SUM.getCompleteAddress() << endl;
		throw 4558;
	}

	file2.write((char*)&Transaction, sizeof(Transaction));

	file2.close();

	return Transaction;

}


