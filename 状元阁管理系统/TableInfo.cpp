#include "TableInfo.h"

TableInfo::TableInfo()
{
	//�޲�����������ļ���
	uniqueAddress = "TABInfo\\";
	fileName = "testStudent.txt";
	completeFile = saveAddress + uniqueAddress + fileName;
}

TableInfo::TableInfo(string Name)
{
	//���в��������ļ���
	string temp = ".dat";

	string FM = Name + temp;
	uniqueAddress = "TABInfo\\";
	fileName = FM;
	completeFile = saveAddress + uniqueAddress + fileName;

}

TableInfo TableInfo::operator=(const TableInfo& obj)
{
	//��ֵ������

	uniqueAddress = obj.saveAddress;	//�����ļ���
	fileName = obj.fileName;	//�ļ�����
	completeFile = obj.completeFile;	//�����ļ�·��
	
	return *this;

}


TableInfo::~TableInfo() 
{
	//��������������Ҫʲô����
}

void TableInfo::setName(string name)
{
	string temp = ".dat";
	string FM = name + temp;
	//ֻ�޸����ļ���
	fileName = FM;
	completeFile = saveAddress + uniqueAddress + fileName;
}