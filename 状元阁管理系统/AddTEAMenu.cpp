#include "AddTEAMenu.h"
#include <string.h>


AddTEAMenu::AddTEAMenu(){}

AddTEAMenu::~AddTEAMenu(){}

AddTEAMenu::AddTEAMenu(const AddTEAMenu& obj) 
//��������
{
	this->teacher = obj.teacher;
}

void AddTEAMenu::display() 

//char* name, char sex, char* phone, char* QQ, int salary)
//People(name, sex, phone)

{

	system("CLS");
	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\t��ӽ�ʦ��Ϣ" << endl << endl;
	cout << "\t\t�밴�����·�ʽ���н�ʦ��Ϣ����" << endl << endl;
	cout << "  A.  1.���� 2.�Ա�F or M��3.�绰���� 4.QQ " << endl;
	catchAndAnylasis();
}

void AddTEAMenu::catchAndAnylasis() 

//�����Ҹ�������и�ֵ

{
	string name, sex, phone, QQ;
	int salary = 60;
	char cname[30], csex = 'F', cphone[20], cQQ[20];
	memset(cname, '\0', 30);

	memset(cphone, '\0', 20);
	memset(cQQ, '\0', 20);
	cin >> name >> sex >> phone >> QQ;
	cout << endl;
	if (display2()) 
	{
		cout << "��������ĺ�нˮ�� ";
		cin >> salary;
	}
	//ת�����ַ�����
	strcpy_s(cname, name.c_str());//strncpy(buf, str.c_str(), 10);
	strcpy_s(cQQ, QQ.c_str());
	strcpy_s(cphone, phone.c_str());

	if (sex[0] == 'M'||sex[0]=='m')
	{
		csex = 'M';
	}

	if (sex[0] == 'F'||sex[0]=='f')
	{
		csex = 'F';
	}
	Purpose sub;
	sub = catchPurpose();
	Teacher TEA(cname, csex, cphone, cQQ, sub,salary);
	
	teacher = TEA;
}

bool AddTEAMenu:: display2() 

	//ѯ���Ƿ���нˮ

{
	cout << "�Ƿ���Ĭ��нˮ��Y or N :  " ;
	string ans;
	cin >> ans;
	if (ans[0] == 'Y' || ans[0] == 'y') 
	{
		return 1;
	}
	return 0;
}

Teacher AddTEAMenu::getTeacher() 

{
	return this->teacher;
}

Purpose AddTEAMenu::catchPurpose()

{
	vector<string> list;
	int a = 1;
	cout << "�������ѧ��Ŀ���� :  " ;
	cin >> a;
	cout << endl;
	string ttt;
	cout << "������ֱ�����γ����ƣ��м��ÿո���� (��:���� ��ѧ)" << endl;

	for (int i = 1; i <= a; i++)
	{
		cout << "������� " << i << " ����Ŀ :  ";
		cin >> ttt;
		list.push_back(ttt);
	}
	if (a == 0)
	{
		ttt = "�޿�Ŀ";
		list.push_back(ttt);

	}
	Purpose pur(list);
	return pur;

}