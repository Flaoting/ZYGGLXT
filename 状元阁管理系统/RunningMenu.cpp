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
}



//Ψһ�ⲿ�ӿڵ�display����
void RunningMenu::display() 
// float pay, string Remarks string payer = "����Ա����", string collect = "΢��֧��");
{
	system("CLS");
	string PayMan, Remarks;
	float payment;
	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\t������ˮ�˼�¼" << endl << endl;
	cout << "�������������(���б�ע��һ����д):   "<<endl<<"\t";
	cin >> Remarks;
	cout << "��������:       ";
	cin >> payment;
	if (display2())
	{
		cout << "�����뵱ǰ������" << endl;
	}


}

bool RunningMenu::display2() 
{
	cout << "��ǰ����ˮ��¼����:  ";
	cout << this->operatorManager.getName()<<endl;
	cout << "�Ƿ�����޸ģ�";
	if (checkToContinue())
	{
		return true;
	}
	return false;
}