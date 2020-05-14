#include "TableInfo.h"

TableInfo::TableInfo()
{
	//�޲�����������ļ���
	uniqueAddress = "TABInfo\\DataTable\\";
	fileName = "testStudent.txt";
	completeFile = saveAddress + uniqueAddress + fileName;
}

TableInfo::TableInfo(string Name)
{
	//���в��������ļ���
	string temp = ".dat";

	string FM = Name + temp;
	uniqueAddress = "TABInfo\\DataTable\\";
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



void TableInfo::GiveTeacherALife()
	//Ϊ��ʦ�α������µ�·��
{ 
	uniqueAddress = "TABInfo\\DataTable\\";
	completeFile = saveAddress + uniqueAddress + fileName;
}

void TableInfo::ForTeacherCSV(string name) 
{
	fileName = name + ".csv";
	uniqueAddress = "TABInfo\\VisionTable\\TEATable\\";
	completeFile = saveAddress + uniqueAddress + fileName;
}

void TableInfo::ForStudentCSV(string name) 
{
	fileName = name + ".csv";
	uniqueAddress = "TABInfo\\VisionTable\\STDTable\\";
	completeFile = saveAddress + uniqueAddress + fileName;
}
