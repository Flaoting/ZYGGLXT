#include <iostream>
#include <string>
#include <fstream>
#include "stdafx.h"
using namespace std;

string login_one();//������Կ
void register_one();//���Bigboss��Ȩ��
void register_two();//����ע��
void login_main();//��¼��������

string welcome()
//�׽��溯��,��ӭ����

{
	system("cls");
	cout << "--------------------------------------------------------" << "|"<<endl;
	cout << endl <<endl << endl<< endl << endl;
	cout << endl << endl << endl ;
	cout <<"\t"<< "��ӭʹ��״Ԫ����Ϣ����ϵͳ" << endl;
	cout << endl  << endl << endl<<endl<<endl; 
	cout <<"\t\t\t\t"<< "�����Ƚ��е�½��"<<endl<<endl;
	cout << endl << endl << endl << endl << endl;
	cout << "--------------------------------------------------------" << endl;
	
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
		welcome();
	}
	login_main();
	cout << "\t\t��л��ʹ�ñ�ϵͳ��" << endl;
	return s1;

}
string login_one() 
//��¼������ʵ�ֵĹ���������ע�ắ���ͽ���������ҳ��
{
	system("cls");
	cout << "--------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "�״ε�½������ָ��register��" << endl;
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t��������Կ��";
	string s;
	cin >> s;
	cout << endl << endl << endl << endl << endl;
	cout << "--------------------------------------------------------" << endl;
	system("pause");
	return s;
}
void register_one() {

		system("cls");
		cout << "--------------------------------------------------------" << endl;
		cout << endl << endl << endl << endl << endl;
		cout << "������BigBoss����Ȩ�룺";
		string s;
		cin >> s;
		bool tem = 0;
		
		cout << endl << endl << endl << endl << endl;
		cout << "--------------------------------------------------------" << endl;
		
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
void register_two() 
{
	system("cls");
	cout << "--------------------------------------------------------" << endl;
	cout << endl << endl << endl << endl << endl;
	cout << "������ע���û���: ";
	string name,password;
	cin >> name;
	cout << "������������Կ: ";
	cin >> password;
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

<<<<<<< HEAD


=======
>>>>>>> dev
void login_main()

//�׽��湦��ѡ����

{
	system("cls");
	cout << endl << endl;
	cout << "**************************************************************************************" << endl;
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t1.����ѧ��\t2.������ʦ\t3.ѧ���ɷ�\t4.��ȡ����" << endl;
	cout << endl << endl << endl << endl << endl;
	cout <<"**************************************************************************************" << endl;

	system("pause");

}