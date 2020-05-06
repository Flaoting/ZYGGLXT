#include "AddSTD.h"
#include "Student.h"
#include "STDInfo.h"
#include <fstream>

using namespace std;


#include "AddSTDMenu.h"
AddSTD::AddSTD() {}

AddSTD::~AddSTD(){}

void AddSTD::getInfo() 

//�ѱ����������STD ������Ϣ

{
	AddSTDMenu  ASM;
	ASM.display();
	student =  ASM.getStudent();
	string name(student.getName());

	STDInfo SI(name);
	saveAddress = SI;
}
//���û�����

bool AddSTD::saveThisFile() 
{
	ofstream file(saveAddress.getCompleteAddress(), ios::out | ios::binary);
	
	if (!file) 
	
	{
		cout << "ѧ����Ϣ�ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;
		return 0;
	}
	
	file.write((char*)&student, sizeof(student));
	file.close();
	
	return 1;
}