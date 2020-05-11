#include "STDInfo.h"
#include <string>

STDInfo::STDInfo() 
{
	uniqueAddress = "STDInfo\\";
	fileName = "testStudent.txt";
	completeFile = saveAddress + uniqueAddress + fileName;
}

STDInfo::STDInfo(string Name) 
{
	string temp = ".dat";
	string FM = Name + temp;
	uniqueAddress = "STDInfo\\";
	fileName = FM;
	completeFile = saveAddress + uniqueAddress + fileName;

}

STDInfo STDInfo::operator=(const STDInfo& obj) 
{
	uniqueAddress=obj.saveAddress;//�����ļ���
	fileName=obj.fileName;//�ļ�����
	completeFile=obj.completeFile;//�����ļ�·��
	return *this;
}

STDInfo::~STDInfo(){ }

void STDInfo::setName(string name)
{
	//ֻ�ı��ļ��������ұ䴢��λ��

	string temp = ".dat";
	string FM = name + temp;
	fileName = FM;
	completeFile = saveAddress + uniqueAddress + fileName;
}

STDInfo::STDInfo(const STDInfo& obj) 

{
	uniqueAddress = obj.saveAddress;//�����ļ���
	fileName = obj.fileName;//�ļ�����
	completeFile = obj.completeFile;//�����ļ�·��
}