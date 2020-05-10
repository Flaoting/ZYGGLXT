#include "OperateSTD.h"
#include "STDInfo.h"
#include "PerInfo.h"
#include "PeoNum.h"
#include <fstream>
#include "AddSTDMenu.h"

using namespace std;


OperateSTD::OperateSTD() {}

OperateSTD::~OperateSTD(){}

void OperateSTD::getInfoFromScreen()

//�ѱ����������STD ������Ϣ

{
	AddSTDMenu  ASM;

	ASM.display();
	student =  ASM.getStudent();
	string name(student.getName());

	STDInfo SI(name);
	saveAddress = SI;
}

bool OperateSTD::saveThisFile() 
{
	ofstream file(saveAddress.getCompleteAddress(), ios::out | ios::binary);
	
	if (!file) 
	
	{
		cout << "ѧ����Ϣ�ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;
		return 0;
	}
	
	file.write((char*)&student, sizeof(student));
	file.close();
	
	PerInfo PI;//��������Ϣ�����ַ
	
	ofstream perFile;
	perFile.open(PI.getCompleteAddress(), ios::binary |ios::app);
	
	if (!perFile) 
	{
		cout << "��Ϣ���ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;
		
		return 0;

	}
	setStdsID(this->student);
	perFile.write((char*)&student, sizeof(student));
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

	file.read((char*)&student, sizeof(student));
	file.close();
	//student.display();
	return 1;

}

Student OperateSTD::getStudent() 

{
	return this->student;
}
void OperateSTD::setStdsID(Student& obj) 

{
	PeoNum PN;
	obj.ID = PN.returnNum();
}