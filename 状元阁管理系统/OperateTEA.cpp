#include "OperateTEA.h"


OperateTEA::OperateTEA(){}

OperateTEA::~OperateTEA(){}

OperateTEA::OperateTEA(const OperateTEA& obj) 
{
	this->teacher = obj.teacher;
}

void OperateTEA::getInfoFromScreen()

//�ѱ����������STD ������Ϣ
{

	AddTEAMenu  ATM;

	ATM.display();
	teacher = ATM.getTeacher();
	string name(teacher.getName());

	TEAInfo TI(name);
	
	saveAddress = TI;
}
bool OperateTEA::saveThisFile()

//�����ļ�
{
	ofstream file(saveAddress.getCompleteAddress(), ios::out | ios::binary);

	if (!file)

	{
		cout << "��ʦ��Ϣ�ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;
		return 0;
	}

	file.write((char*)&teacher, sizeof(teacher));
	file.close();

	return 1;

}
bool OperateTEA::readPreFile()

//���ļ��ж�ȡ�ļ���Ϣ

{
	string thisName = "test";
	cout << "\t������Ҫ��ѯ��ʦ������:  ";
	cin >> thisName;
	cout << endl;

	saveAddress.setName(thisName);
	
	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)

	{
		cout << "��ʦ��Ϣ�ļ���ʧ�ܣ�����·���������Ƿ���ȷ��" << endl;
		return 0;
	}

	file.read((char*)&teacher, sizeof(teacher));
	file.close();
	return 1;

}



Teacher OperateTEA::getTeacher() 

{

	return this->teacher;

}
