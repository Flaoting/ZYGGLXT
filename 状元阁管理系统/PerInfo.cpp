#include "PerInfo.h"

PerInfo::PerInfo()
{
	string temp = "AllPerson.dat";
	string FM = temp;
	uniqueAddress = "PerInfo\\";
	fileName = FM;
	completeFile = saveAddress + uniqueAddress + fileName;

}

PerInfo PerInfo::operator=(const PerInfo& obj)
{
	uniqueAddress = obj.saveAddress;//�����ļ���
	fileName = obj.fileName;//�ļ�����
	completeFile = obj.completeFile;//�����ļ�·��
	return *this;
}
PerInfo::~PerInfo() { }

void PerInfo::setName(string name)
{
	string temp = "AllPerson.dat";
	fileName = temp;
	completeFile = saveAddress + uniqueAddress + fileName;
}

PerInfo::PerInfo(const PerInfo& obj)

{
	uniqueAddress = obj.saveAddress;//�����ļ���
	fileName = obj.fileName;//�ļ�����
	completeFile = obj.completeFile;//�����ļ�·��
}