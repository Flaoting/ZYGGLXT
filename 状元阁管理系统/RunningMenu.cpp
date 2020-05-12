#include "RunningMenu.h"
#include <iostream>
using namespace std;

RunningMenu::RunningMenu(Manager& obj):operatorManager(obj)
{
	//ʣ�µ��������
}

RunningMenu::~RunningMenu() 
{
	//��򵥵�����������

}

RunningMenu::RunningMenu(const RunningMenu& obj) 
{
	this->operatorManager = obj.operatorManager;
}

RunningMenu RunningMenu::operator= (const RunningMenu& obj)
{

	this->operatorManager = obj.operatorManager;
	return *this;
}


//Ψһ�ⲿ�ӿڵ�display����
void RunningMenu::display() 
// float pay, string Remarks string payer = "����Ա����", string collect = "΢��֧��");
{
	system("CLS");

	string PayMan, Remarks,collect;
	float payment;
	
	cout << "************************************************************" << endl << endl;
	cout << "\t\t������ˮ�˼�¼" << endl << endl;
	cout << "�������������(���б�ע��һ����д):   ";
	cin >> Remarks;
	cout << "��������:       ";
	cin >> payment;
	bool temp = display2();
	
	try 
	{
		if (temp)
		{
			cout << "�����뵱ǰ������ :   ";
			cin >> PayMan;
			cout << "�����븶�ʽ   :   ";
			cin >> collect;
			RunningRecord RR(this->operatorManager, payment, Remarks, PayMan, collect);
			if (!saveRunRecord(RR))
			{
				throw 936;
			}
		}
		else
		{
			RunningRecord RPP(this->operatorManager, payment, Remarks);
			if (!saveRunRecord(RPP)) 
			{
				throw 936;
			}
		}
		cout << endl;
		cout << "Success  ��ˮ��¼����ɹ� ��";
		cout << "�˴ν��׾�����Ϣ���� :   " << endl;
		cout << "����Ա   "<<this->operatorManager.getName()<<endl;
		if (temp) 
		{
			cout << "������   " << PayMan << endl;
		}
		else 
		{
			cout << "������   " << this->operatorManager.getName() << endl;
		}
		cout << "���     " << payment<<endl;
		cout << "���ױ�ע " << Remarks<<endl;
		if (temp)
		{
			cout << "�տʽ " << collect << endl;
		}
		else
		{
			cout << "�տʽ " << "΢��֧��" << endl;
		}

	}catch (int goal) 
	{
		cout << "Warning   ��ˮ�˼�¼����ʧ��";
		cout << "�������:  " << goal << endl;
	}
	
}

bool RunningMenu::display2() 
{
	cout << "��ǰ����ˮ��¼����:  ";
	cout << this->operatorManager.getName()<<endl;
	cout << "�Ƿ�����޸ģ��������Ĭ���տʽҲ��ѡ�����...";
	cout << endl;
	if (checkToContinue())
	{
		return true;
	}
	return false;
}

bool RunningMenu::saveRunRecord(RunningRecord ThRR) 

{
	RecordInfo ADD("RunningRecord");
	ofstream file;

	file.open(ADD.getCompleteAddress(), ios::out | ios::binary | ios::app);

	if (!file)
	{
		cout << "Warning ��ˮ��¼�ļ���ʧ��  " << endl;
		cout << "�����Ƿ����·��" << ADD.getCompleteAddress() << endl;
		return false;
	}
	file.write((char*)&ThRR, sizeof(ThRR));

	file.close();
	return true;

}


