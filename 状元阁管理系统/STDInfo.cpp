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
	completeFile=obj.completeFile;
}
STDInfo::~STDInfo(){ }