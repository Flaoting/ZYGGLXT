#include "PerInfo.h"

PerInfo::PerInfo(string name)
{

	uniqueAddress = "PerInfo\\";
	string temp = ".dat";
	fileName = name + temp;
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
	string temp = ".dat";
	fileName = name+temp;
	completeFile = saveAddress + uniqueAddress + fileName;
}

PerInfo::PerInfo(const PerInfo& obj)

{
	uniqueAddress = obj.saveAddress;//�����ļ���
	fileName = obj.fileName;//�ļ�����
	completeFile = obj.completeFile;//�����ļ�·��
}



