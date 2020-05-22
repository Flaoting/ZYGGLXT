#include <iostream>
#include <string>
#include <fstream>
#include "stdafx.h"
#include "LoginMenu.h"
using namespace std;


void LoginMenu:: display()
//�׽��溯��,��ӭ����

{
	system("cls");
	cout << "********************************************************" << "" << endl;
	cout << endl << endl << endl ;
	cout <<"\t"<< "��ӭʹ��״Ԫ����Ϣ����ϵͳ" << endl;
	cout << endl;
	cout <<"\t"<< "�� �� �� �� �� �� ½ ��"<<endl<<endl;
	cout << endl << endl << endl << endl << endl;
	cout << "********************************************************" << endl;
	system("pause");

	string s1= login_one();
	
	if (s1 == "register") 
	{
		register_one();
		exit(0);
	}
	
	//������ص���Կ��register�������ע��
	try 
	{
		checkPassword(s1);
	}
	catch (int ) 
	{
		cout <<"\t\t�޴��û���Ϣ�������������룡"<<endl;
		system("pause");
		display();
	}
	return;

}



bool LoginMenu::checkInDisplay()
{

	system("cls");
	cout << "********************************************************" << "" << endl;
	cout << endl << endl << endl;
	cout << "\t" << "��ӭʹ��״Ԫ����Ϣ����ϵͳ" << endl;
	cout << endl;
	cout << "\t" << "�� �� �� �� �� �� ½ ��" << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << "********************************************************" << endl;
	system("pause");

	string s1 = login_one();

	if (s1 == "register") //������ص���Կ��register�������ע��
	{
		register_one();
		exit(0);
	}
	
	try
	{
		if (checkPassword(s1)) 
		{
			return 1;				//���ҳɹ�������1
		}
	}
	catch (int)
	{
		/*cout << "Warning �޴��û���Ϣ�������������룡" << endl;
		system("pause");
		display();*/
		return false;
	}
	return false;

}



string LoginMenu::login_one()
//��¼������ʵ�ֵĹ���������ע�ắ���ͽ���������ҳ��
{
	system("cls");
	cout << "*********************************************************" << endl;

	cout << endl;
	cout << "\t����������״ε�¼,������ָ��register��" << endl<<endl;
	cout << "\t���������ĸ��˵�¼�� :  ";
	string s;
	do 
	{
	s = getStringWithoutShow();
	} while (s == ""||s==" "|| s=="\n");
	cout << endl << endl << endl << endl << endl;
	cout << "********************************************************" << endl;
	return s;
}



void LoginMenu::register_one() {

		system("cls");
		cout << "*****************************************************************" << endl;
		cout << endl ;
		cout << "\t���������ø��˵�¼����,���ú�����Ҫ���½��뱾ϵͳ " << endl<<endl;
		cout << "������BigBoss����Ȩ�� :  ";
		string s;
		s = getStringWithoutShow();
		bool tem = 0;
		cout << endl << endl << endl << endl << endl;
		cout << "*****************************************************************" << endl;
		
		if (checkBigPassword(s))

		{
			register_two();
		}
		else
		{
			cout << "Sorry����Ȩ��Ƿ���������BigBoss��ϵ��" << endl;
		}
		return;
}



void LoginMenu::register_two()
{
	system("cls");
	cout << "*****************************************************************" << endl;
	cout << endl;
	cout << "\t������ע���û��� :  ";
	string name,password;
	cin >> name;
	cout << "������������Կ:   ";
	password = getStringWithoutShow();
	try {
		if (saveAccount(name, password)) 
		{
			system("cls");
			cout << "�����˻��ɹ��������µ�¼��" << endl;
		}
		else 
		{
			throw 1;
		}
	}
	catch (int) {
		system("cls");
		cout << "�����˻�ʧ��,�����쳣�����뿪������ϵ��" << endl;
		system("pause");
	}
	
}



bool LoginMenu::saveAccount(string name, string password)

//�����˻�˵����ǰ����β�ǻس�
//������ǰ���˻����ں��м� ��#�� ����
//����л��з�

{
	string  fileAddress = "E:\\VisualStudio\\Data\\";
	string fileName = "password.txt";
	string file = fileAddress + fileName;

	char na[20], pa[30];

	strcpy_s(na, name.c_str());
	strcpy_s(pa, password.c_str());

	ofstream f(file, ios::out | ios::app);

	if (!f)
	{
		cout << file << " can't be opened !" << endl;
		system("pause");
		return 0;
	}

	f << pa;

	f.put('#');
	f << na;

	f.put(10);

	f.close();

	return 1;
}



bool LoginMenu::checkPassword(string input)

//�������ļ�����ȡ���ݣ����������ݽ��к���

{
	string  fileAddress = "E:\\VisualStudio\\Data\\";
	string fileName = "password.txt";
	string file = fileAddress + fileName;

	ifstream password;
	password.open(file, ios::in);
	char pa[30];
	string str;

	//�ж϶�ȡ����,��֤����·�����з���ֵ��
	//���쳣������ǿ��׳��

	bool temp = 0;
	while (!password.eof())
	{
		password.getline(pa, 49, '#');
		str = pa;

		if (input == str)
		{
			temp = 1;
			password.close();
			return 1;
		}

		char cc = password.get();
		while (!password.eof() && cc != 10)
		{
			cc = password.get();
		}

	}
	//���û�в��ҵ����׳�0
	if (!temp) {
		password.close();
		throw 0;
		return 0;
	}
	return 0;
}



bool LoginMenu::checkBigPassword(string s)

//��һ����BigBoss��Ȩ��
//#�Ž�β������endl
{

	ifstream password;

	string  fileAddress = "E:\\VisualStudio\\Data\\";
	string fileName = "password.txt";
	string file = fileAddress + fileName;

	password.open(file, ios::in);

	if (!password)
	{
		cout << "password.txt can't be opened!" << endl;
		exit(0);
	}

	char  pass[20];
	string a;

	password.getline(pass, 20, '#');

	password.close();

	a = pass;

	if (s == a) {
		return 1;
	}
	return 0;
}

