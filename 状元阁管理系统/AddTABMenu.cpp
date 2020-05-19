#include "AddTABMenu.h"

AddTABMenu:: AddTABMenu():table()
{	
	//�޲ι���
}

AddTABMenu::~AddTABMenu()
{
	//��������
}

AddTABMenu::AddTABMenu(const AddTABMenu& obj)
{
	this->table = obj.table;
}


void AddTABMenu::display() 
//Date startDate, Date endDate,int num,int Type 
{
	string TeacherName, StudentName;
	int whenClass, classType;
	char TEAname[30];
	Student thisSTD;
	
	system("cls");

	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\tѧ��ȷ���γ���Ϣ" << endl ;
	cout << "��ע�� : ȷ���γ���Ϣǰ�������ѧ���ĸ�����Ϣ " << endl;
	cout << "��ע�� : ��δ��ӣ��뷵���ϲ�˵����ѧ����Ϣ " << endl;
	if (!checkToContinue())
	{
		operationCancled();
		return;
	}
	
	
	try 
	{
		cout << "������ѧ������ :  ";
		cin >> StudentName;
		thisSTD = checkThisStudent(StudentName) ;
	
		cout << "�������ʦ���� :  ";
		cin >> TeacherName;
	
		strcpy_s(TEAname, TeacherName.c_str());
		classType = display2();
	
	
	
		cout << "\t��ѡ��α�����뷽ʽ" << endl;
		cout << "  A.  ���뿪ʼ���ںͽ�������" << endl;
		cout << "  B.  ���뿪ʼ���ںͿγ̽���" << endl;
		cout << "  C.  �ֶ����пγ����ڵ�ѡ��" << endl;
		cout << "  ��������ѡ��ʽ���� :  ";
		string tem;
		cin >> tem;
		switch(tem[0]) 
		{
			case 'A': 
			{

				cout << "������γ��ǵڼ��ڿ�(1-5) :  ";
				cin >> whenClass;
				Date d1, d2;
				cout << "�����뿪ʼ����" << endl;
				d1 = getDateFromScreen();
				cout << "�������������" << endl;
				d2 = getDateFromScreen();
				Table tab(&thisSTD, d1, d2, whenClass, TEAname, classType);
				this->table = tab;
				cout << "Success �α��¼�ɹ�!" << endl;
				return;
				break;
			}

			case 'B':
			{

				cout << "������γ��ǵڼ��ڿ�(1-5) :  ";
				cin >> whenClass;
				Date d1;
				int num = 0;
				cout << "�����뿪ʼ����" << endl;
				d1 = getDateFromScreen();
				cout << "������γ̽��� :  ";
				cin >> num;
				Table tab(&thisSTD, d1, num,whenClass, TEAname, classType);
				this->table = tab;
				cout << "Success �α��¼�ɹ�!" << endl;
			
				return;
				break;
			}

			case 'C':
			{
				Table tab(&thisSTD, TEAname, classType);
				this->table = tab;
				cout << "Success �α��¼�ɹ�!" << endl;
				return;
				break;
			}
		}

		return;
	}
	
	catch (int goal) 
	{	
		cout << "Warning  ������� " << goal << endl;
		cout << "1. ����ѧ����Ϣ�Ƿ��Ѿ�����������" << endl;
		cout << "2. ����ѧ������ƴд�Ƿ���ȷ" << endl;
		cout << "3. ���ⰴ��������һ��˵�" << endl;
	}

}


Student AddTABMenu::checkThisStudent(string name) 
{
	OperateSTD OS;

	if(!OS.readPreFile(name))
	{
		throw 2046;
	}
	Student stud(OS.getStudent());
	return stud;
}

int AddTABMenu::display2() 

{
	int num=0,i=0;
	while (i<4&&num != 1 && num != 2 && num != 3 && num != 4 && num != 5 && num != 6) 
	{
		if (i == 4)
		{
			throw 2048;
		}
		if (i > 0) 
		{
			cout << "���ϴ����������  " << num
				<< " �ǷǷ����ݣ����������룡��" << endl;
		}
		cout << "�γ��������� :  " << endl;
		cout << "1, һ��һ�γ� " << endl;
		cout << "2. һ�Զ��γ� " << endl;
		cout << "3, һ�����γ� " << endl;
		cout << "4, һ���Ŀγ� " << endl;
		cout << "5. С��ογ� " << endl;
		cout << "6. ������γ� " << endl;
		cout << "��ѡ��γ����ͱ��(������2����һ�Զ��γ�)" << endl;
		cout << "��������ѡ��� :  ";
		cin >> num;
	}
	return num;
}

Date AddTABMenu::getDateFromScreen() 

{
	
	int year = 2020, month = 1, day = 1;
	cout << "��ѡ���Ƿ�������� ? ";
	if (checkToContinue()) 
	{
		cout << "�����ʽ(�� �� ��)(�м��ÿո���� �� 2020 5 1 ) " << endl;
		cout << "������ :  ";
		cin >> year >> month >> day;
		Date ans(year, month, day);
		return ans;
	}

	else
	{
		cout << "�����ʽ(�� ��)(�м��ÿո���� �� 5 1 ) " << endl;
		cout << "������ :  ";
		cin >> month >> day;
		Date ans( month, day);
		return ans;
	}
}

Table AddTABMenu::getTable()
{
	return this->table;
}


