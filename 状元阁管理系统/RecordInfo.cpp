#include "RecordInfo.h"

RecordInfo::RecordInfo(string Name)
{

	string temp = ".dat";
	string FM = Name + temp;
	uniqueAddress = "Record\\";
	fileName = FM;
	completeFile = saveAddress + uniqueAddress + fileName;

}

RecordInfo::RecordInfo()
{
	uniqueAddress = "Record\\";
	fileName = "TotalRecord.dat";
	completeFile = saveAddress + uniqueAddress + fileName;
}


RecordInfo::~RecordInfo() 
{
	//�����������������
}

RecordInfo RecordInfo::operator = (const RecordInfo& obj) 
{
	BaseFile::operator=(obj);
	return *this;
}


