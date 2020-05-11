#include "OperateSTD.h"
#include "PeoNum.h"
#include "AddSTDMenu.h"
#include "PerInfo.h"

#include <fstream>

OperateSTD::OperateSTD() {}

OperateSTD::~OperateSTD(){}

void OperateSTD::getInfoFromScreen()

//�ѱ����������STD ������Ϣ

{
	AddSTDMenu  ASM;

	ASM.display();
	stud =  ASM.getStudent();
	string name(stud.getName());

	STDInfo SI(name);
	saveAddress = SI;
}

bool OperateSTD::saveThisFile() 
{
	setStdsID(this->stud);
	ofstream file(saveAddress.getCompleteAddress(), ios::out | ios::binary);

	if (!file) 
	
	{
		cout << "ѧ��������Ϣ�ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;
		return 0;
	}
	
	file.write((char*)&stud, sizeof(stud));
	file.close();
	PerInfo PI;//��������Ϣ�����ַ
	
	ofstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary |ios::app);
	
	if (!perFile) 
	{
		cout << "��Ա��Ϣ���ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;
		
		return 0;

	}
	perFile.write((char*)&stud, sizeof(stud));
	perFile.close();
	
	return 1;
}

bool OperateSTD::readPreFile( ) 
	
	//������Ϣ��������˽������

{
	string thisName="test";
	cout << "\t������Ҫ��ѯѧ��������:  ";
	cin >> thisName;
	cout << endl;
	saveAddress.setName(thisName);

	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)

	{
		cout << "ѧ����Ϣ�ļ���ʧ�ܣ�����·���������Ƿ���ȷ��" << endl;
		return 0;
	}

	file.read((char*)&stud, sizeof(stud));
	file.close();
	//student.display();
	return 1;

}

Student OperateSTD::getStudent() 

{
	return this->stud;
}

void OperateSTD::setStdsID(People& obj) 

{
	//����ID
	PeoNum PN;

	obj.ID = PN.returnNum();

}

bool OperateSTD::readPreFile(string STDname)
{
	saveAddress.setName(STDname);

	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)
	{
		cout << "ѧ����Ϣ�ļ���ʧ�ܣ�����·���������Ƿ���ȷ��" << endl;
		return 0;
	}
	file.read((char*)&stud, sizeof(stud));
	
	file.close();
	return 1;
}