#include "BaseFile.h"
#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>


using namespace std;
string BaseFile :: REGISTERADDRESS= "E:\\VisualStudio\\Data\\";

void BaseFile::RESETADDRESS(string RERE) 

{
	REGISTERADDRESS = RERE; 
}


BaseFile::BaseFile() :saveAddress(REGISTERADDRESS)

{
	uniqueAddress = "Test\\";
	fileName = "test.txt";
	completeFile = saveAddress + uniqueAddress + fileName;
}

BaseFile::BaseFile(const BaseFile& obj) 
{
	uniqueAddress = obj.saveAddress;//�����ļ���
	fileName = obj.fileName;//�ļ�����
	completeFile = obj.completeFile;//�����ļ�·��
}

BaseFile BaseFile::operator=(const BaseFile& obj) 
{
	uniqueAddress = obj.saveAddress;//�����ļ���
	fileName = obj.fileName;//�ļ�����
	completeFile = obj.completeFile;//�����ļ�·��
	return *this;
}

BaseFile::BaseFile(string UA, string FA):saveAddress(REGISTERADDRESS)

//��һ�������ǹ����������ڶ����������ļ�����

{
	uniqueAddress = UA;
	fileName = FA;
	completeFile = saveAddress + uniqueAddress + fileName;
}


string BaseFile::getCompleteAddress()

{
	return completeFile;
}

string BaseFile::getSaveAddress()

{
	return saveAddress;
}

string BaseFile::getfileName() 

{
	return fileName; 
}


void BaseFile::setFileName(string FA) 
{
	fileName = FA; 
	completeFile = saveAddress + uniqueAddress + fileName;
}


void BaseFile::changeSaveAddress() 
{

	cout << "������BigBoss��Ȩ�룡" << endl;
	string pass;
	pass = getStringWithoutShow();
	
	try 
	{

		try
		{
			if (!checkBigPassword(pass))
			{
				throw pass;
			}
		}
		catch (string goal)
		{
			cout << "���ո�������� " << goal << endl;
			cout << "��Ȩ���������ϵBigBoss����Floating��" << endl;
			throw goal;
		}

		string newSavaAddress;
		
		try
		{
			cout << "��ǰ�Ĵ���·���� " << this->getSaveAddress() << endl;
			
			cout << "��������ĺ��·��(������·����ͬ�ĸ�ʽ���ļ���֮����\\����) ";
			
			cout<< endl << "$ ";

			cin >> newSavaAddress;

			bool temp;

			temp = checkSaveAddress(newSavaAddress);

			if (!temp)
			
			{
				throw newSavaAddress;
			}

			cout << "�µĴ���·����  " << newSavaAddress << endl;
			
			cout << "�Ƿ���� Y or N ��" << endl;
			
			cin.ignore();
			char  cc=getchar() ;
			
			if (toupper(cc) == 'Y')

			{
				RESETADDRESS(newSavaAddress);
				cout << "����·���޸ĳɹ���" << endl;
			}

			else
			
			{
				throw -1;
			}
		}

		catch (string goal)
		{
			cout << "���ո�������� " << goal << endl;
			cout << "����Ĵ���·���Ƿ��������¼��·����" << endl;
		}

		catch (int N)
		{

			cout << "��������-1��  ����ȡ����" << endl;
		}
		
	}

	catch (string ggg) 
	{
		cout << "����ȡ��!!!��" << endl;
	}
	
}

void BaseFile::display() 
{
	cout << completeFile << endl;
}

