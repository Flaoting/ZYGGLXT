#include "RegisterManagerMenu.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

RegisterManagerMenu::RegisterManagerMenu():Man()

{
	//���캯�����������
}

RegisterManagerMenu:: ~RegisterManagerMenu() 

{
	//�����������������
}

void RegisterManagerMenu::display() 
{

	system("cls");

	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\t����Ա��Ϣע��" << endl;
	cout << "��ע�� : ��ǰע����Ϣ����Ϊ��ʹ�ñ�ϵͳ��Ψһʶ����" << endl;
	cout << "��ע�� : ������ϸ��д��������ܻ�����޷�Ԥ�ϵĺ��" << endl;
	//cout << "лл�������ͶԱ�����ϵͳ��֧�֣�ף��������죬�Ҹ�������" << endl;

	if (!checkToContinue()) 
	{//ѯ���Ƿ����
		operationCancled();
		return;
	}
	
	if(!checkQuality())
	{//�����Ȩ��
		operationCancled();
		return;
	}
	
	char name[30], phone[20], gender, ssh[30];
	cout << "������ʾ : ������й���Ա��Ϣ��д����ע����Χ����!!!" << endl;
	cout << "��������������   :  ";
	cin >> name;
	cout << "�����������Ա�   :  ";
	gender = checkGender();
	cout << "��������ϵ�绰   :  ";
	cin >> phone;
	cout << "������Ҫ�����������˽�˹�����Կ,��ʹ���ڲ�����ʱ��������" << endl;
	cout << "������ʾ : ������ϸ��д!!!" << endl;
	strcpy_s(ssh, getSSHFromScreen().c_str());
	Manager manager(name, gender, phone, ssh);
	this->Man = manager;
	string tem = name;
	if (!saveThisMan(tem)) 
	{
		cout << "���ź� ����Ա��Ϣ����ʧ�ܣ������ļ�����·��" << endl;
		cout << "�޷��������ϵ������ԱFloating ����" << endl;
		return;
	}
	cout << "��������Ա��Ϣ�ɹ��������μ���������!!! " << endl;
	return;
}

bool RegisterManagerMenu::checkQuality() 
//������ԱȨ��
{
	int cnt=0;
	string BBP;
	try 
	{
		while (1)
		{
			if (cnt >= 3)
			{
				cout << "У��BigBoss��Ȩ������������ޣ�����ȡ��" << endl;
				return 0;
			}
			
			cout << "������BigBoss��Ȩ�� :  ";
			
			BBP = getStringWithoutShow();//����Ļ��ȡ����

			if (checkBigPassword(BBP)) 
			{
				return 1;
			}
			cnt++;
		}
	
	}
	catch (int) 
	{
		cout << "Warning  BigBoss��Ȩ���쳣 �������ļ�·���Ƿ���� ��" << endl;
		return 0;
	}
	return 0;
}

string RegisterManagerMenu::getSSHFromScreen()
{
	string newpass1, newpass2;
	cout << "������������Կ:   ";
	newpass1 = getStringWithoutShow();
	while (newpass1.size() <= 6)
	{
		cout << "Warning:  ��Կ���Ȳ��㣬���������ó���Ϊ��λ���ַ�����Կ" << endl << endl;
		cout << "������������Կ:   ";
		newpass1 = getStringWithoutShow();
	}
	cout << "��ȷ��������Կ:   ";
	newpass2 = getStringWithoutShow();
	int	i = 0;
	while (newpass1 != newpass2)

	{
		if (i >= 5)
		{
			cout << "Warning:  ���������������ޣ��Ѿ�����Ĭ����Կ" << endl ;
			cout << "�����޸����ȵ�¼��Ȼ������޸�" << endl;
			return "dongge666";
		}

		cout << "����������Կ��һ�£�����������" << endl;
		i++;
		cout << "������������Կ:   ";
		newpass1 = getStringWithoutShow();
		while (newpass1.size() <= 6)
		{
			cout << "Warning:  ��Կ���Ȳ��㣬���������ó���Ϊ��λ���ַ�����Կ" << endl << endl;
			cout << "������������Կ:   ";
			newpass1 = getStringWithoutShow();
		}
		cout << "��ȷ��������Կ:   ";
		newpass2 = getStringWithoutShow();

	}
	return newpass1;
}

bool RegisterManagerMenu::saveThisMan(string name) 
{
	PerInfo PIT("TotalManager");
	string addName = "MagInfo//" + name;
	
	PerInfo PIP(addName);
	ofstream TotFile, PrFile;
	
	TotFile.open(PIT.getCompleteAddress(), ios::out | ios::app | ios::binary);
	PrFile.open(PIP.getCompleteAddress(),ios::out|ios::binary);
	
	if (!TotFile) 
	{
		cout << " TotalManager ��Ϣ���ʧ�ܣ�" << endl;
		cout << "����·��" << PIT.getCompleteAddress() << "�Ƿ���ڣ�";
		return 0;
	}
	if (!PrFile)
	{
		cout << " Manager ��Ϣ����ʧ�ܣ�" << endl;
		cout << "����·��" << PIP.getCompleteAddress() << "�Ƿ���ڣ�";
		return 0;
	}
	
	TotFile.write((char*)&this->Man, sizeof(this->Man));
	PrFile.write((char*)&this->Man, sizeof(this->Man));
	
	TotFile.close();
	PrFile.close();
	return 1;
}


Manager RegisterManagerMenu::getManager() 
{
	return this->Man;
}
