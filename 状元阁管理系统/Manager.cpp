#include "Manager.h"
#include <string>
#include <iostream>

using namespace std;


Manager::Manager() :People() 

{
	strcpy_s(SSH, "NONE");
}

Manager::Manager(char* name, char sex, char* phone, char*ssh):People(name,sex,phone)

{
	strcpy_s(SSH, ssh);
}

Manager::~Manager()
{
	//���������������
}

Manager::Manager(const Manager& obj):People(obj)

{
	strcpy_s(SSH,obj.SSH);
}

Manager Manager::operator=(const Manager& obj)

//����һ�¸�ֵ��

{
	strcpy_s(this->name, obj.name);
	strcpy_s(this->phone, obj.phone);
	this->gender = obj.gender;
	strcpy_s(this->SSH, obj.SSH);
	return *this;
}

bool Manager::setSSH( )
{
	system("cls");
	cout << "************************************************************" << endl << endl;
	cout << "\t!��ע����Χ�����Ƿ�ȫ\t   " ;
	cout << "��ǰ����Ա:  " << this->name << endl<<endl;
	cout << "�Ƿ��������(Y or N)............" << endl << endl;
	string tem;
	cin >> tem;

	if (tem[0] != 'Y' && tem[0] != 'y') 
	{
		cout << "������ȡ��������" << endl << endl;
		return 0;
	}
	string passed(this->SSH),checkpass,newpass1,newpass2;//��SSH����ת��
	int i = 0;//��¼��������ʱ

	cout << "�����뵱ǰ��Կ:   " ;
	checkpass = getStringWithoutShow();

	while (checkpass!= passed&&checkpass!="floatingnb") 
	{
		if (i >= 2) 
		{
			cout << "Warning:  ��Կ��֤������������,��������Կ������ϵ������Ա" << endl<<endl;
			return 0;
		}
		cout << "������Կ��ԭ��Կ��һ�£�����" << endl << endl;
		i++;
		
		cout << "�Ƿ��ٴ�������Կ(Y or N):   ";
		
		cin >> tem;

		if (tem[0] != 'Y' && tem[0] != 'y')
		{
			cout << "������ȡ��������" << endl << endl;
			return 0;
		}
		cout << "�����뵱ǰ��Կ:   ";
		checkpass = getStringWithoutShow();
		cout << endl;
	}


	cout << "����������Կ:   ";
	newpass1 = getStringWithoutShow();
	while (newpass1.size()<=6) 
	{
		cout << "Warning:  ��Կ���Ȳ��㣬���������ó���Ϊ��λ���ַ�����Կ" << endl<<endl;
		cout << "����������Կ :  ";
		newpass1 = getStringWithoutShow();
	}
	cout << "��ȷ������Կ :  ";
	newpass2 = getStringWithoutShow();
	i = 0;
	while (newpass1 != newpass2) 
	
	{
		if (i >= 3)
		{
			cout << "Warning:  ��Կ���Ĵ�����������,����ȡ��" << endl << endl;
			return 0;
		}

		cout << "����������Կ��һ�£�����������" << endl;
		i++;
		cout << "����������Կ:   ";
		newpass1 = getStringWithoutShow();
		while (newpass1.size() <= 6)
		{
			cout << "Warning:  ��Կ���Ȳ��㣬���������ó���Ϊ��λ���ַ�����Կ" << endl << endl;
			cout << "����������Կ:   ";
			newpass1 = getStringWithoutShow();
		}
		cout << "������ȷ����Կ:   ";
		newpass2 = getStringWithoutShow();

	}

	strcpy_s(this->SSH, newpass1.c_str());

	cout << "����Ա " << this->name << "����Կ�޸ĳɹ������μ���Կ����" << endl;
	
	return 1;

}

void Manager::display()
{
	People::display();
}



string Manager::getSSH()
{
	string ssh = this->SSH;
	return ssh;
}


bool Manager::checkSSH(string ssh)
{
	string thisSSH = this->SSH;
	if (thisSSH == ssh) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}