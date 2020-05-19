#include "AddSTDMenu.h"
#include <iostream>
#include <string>
#include "Purpose.h"
using namespace std;

bool AddSTDMenu::display2()

{
	cout << "�Ƿ��н��ɶ������������ Y or N ��" << endl;
	string tem;
	cin >> tem;

	if (tem[0] == 'Y')
	{
		return 1;
	}

	return 0;
}



void AddSTDMenu::display() 
{
	//���� �Ա� �绰 QQ ��Ŀ Ҫ�� ����
	//���� �Ա� �绰 ��Ŀ Ҫ�� ����
	//���� �绰 ��Ŀ Ҫ�� ����
	//���� ��Ŀ Ҫ�� ����
	//���� �Ա� ��Ŀ Ҫ�� ����
	
	system("cls");
	
	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\t���ѧ����Ϣ" << endl << endl;
	cout << "\t��ѡ�����뷽ʽ" << endl;
	cout << "  A.  1.���� 2.�Ա�F or M��3.�绰���� 4.QQ " << endl;
	cout << "  B.  1.���� 2.�Ա�F or M��3.�绰���� " << endl;
	cout << "  C.  1.���� 2.�Ա�F or M�� " << endl;
	cout << "  D.  1.���� 2.�绰����  " << endl;
	cout << "  E.  1.����  " << endl<<endl;
	cout << "************************************************************" << endl << endl << endl;
	


	cout << "��ѡ��Ҫ�����ѧ����Ϣ:  ";
	string goal;
	cin >> goal;
	
	system("CLS"); 
	cout << "\t\t�밴�����·�ʽ����ѧ����Ϣ����" << endl << endl;

	switch (goal[0])
	{
		case 'A': 
		{
			cout << "  A.  1.���� 2.�Ա�F or M��3.�绰���� 4.QQ " << endl;
			catchAndAnylasis(4);
			break;
		}

		case 'B':
		{
			cout << "  B.  1.���� 2.�Ա�F or M��3.�绰���� " << endl;
			catchAndAnylasis(3);
			break;
		}
		
		case 'C':
		{
			cout << "  C.  1.���� 2.�Ա�F or M��" << endl;
			catchAndAnylasis(2);
			break;
		}

		case 'D':
		{
			cout << "  D.  1.���� 2.�绰���� " << endl;
			catchAndAnylasis(2);
			break;
		}

		case 'E':
		{
			cout << "  E.  1.���� " << endl << endl;
			catchAndAnylasis(1);
			break;
		}

		default: 
		{
			cout << "ѡ�����뷽ʽ����������ѡ��" << endl;
		
			system("pause");

			system("CLS");
		
			display();

			break; 
		}

	}

	system("pause");
}

//char* name, char sex, char* phone, char* QQ,
//Purpose subj, string requirement , int downpayment

void AddSTDMenu:: catchAndAnylasis(int a) 

{
	string name, sex, phone, QQ, requirement;
	int downpayment = 0;
	char cname[30], csex='F', cphone[20], cQQ[20];
	Purpose purpose;

	switch (a)
	{
	
		case 4: 
		{
			cin >> name >> sex >> phone >> QQ;
			
			purpose = catchPurpose();
			
			if (display2()) 
			{
				cout << "\t\t��������" << endl;
				cin >> requirement;
				cout << "\t\t����û����0���� " << endl;
				cin >> downpayment;
			}

			strcpy_s(cname, name.c_str());//strncpy(buf, str.c_str(), 10);
			strcpy_s(cQQ, QQ.c_str());
			strcpy_s(cphone, phone.c_str());
			
			if (sex[0] == 'M')
			{
				csex = 'M';
			}

			if (sex[0] == 'F') 
			{
				csex = 'F';
			}

			Student std(cname,csex,cphone,cQQ,purpose,requirement,downpayment);
			
			student = std;
			
			break;
		}
		case 3: 
		{
			cin >> name >> sex >> phone;
			purpose = catchPurpose();

			if (display2())
			{
				cout << "\t\t��������" << endl;
				cin >> requirement;
				cout << "\t\t����û����0���� " << endl;
				cin >> downpayment;
			}

			strcpy_s(cname, name.c_str());//strncpy(buf, str.c_str(), 10);
			strcpy_s(cphone, phone.c_str());

			if (sex[0] == 'M')
			{
				csex = 'M';
			}

			if (sex[0] == 'F')
			{
				csex = 'F';
			}

			Student std(cname, csex, cphone,purpose, requirement, downpayment);

			student = std;

			break;
		}
		case 2: 
		{
			cin >> name >> phone;
			
			purpose = catchPurpose();

			if (display2())
			{
				cout << "\t\t��������" << endl;
				cin >> requirement;
				cout << "\t\t����û����0���� " << endl;
				cin >> downpayment;
			}

			strcpy_s(cname, name.c_str());//strncpy(buf, str.c_str(), 10);

			if (phone[0] == 'M' || phone[0] == 'F') 
			{
				if (phone[0] == 'M')
				{
					csex = 'M';
				}

				else if (phone[0] == 'F')
				{
					csex = 'F';
				}
				else 
				{
					csex = '?'; 
				}

				Student std1(cname, csex, purpose, requirement, downpayment);
				student = std1;
				break;
			}
			
			strcpy_s(cphone, phone.c_str());
			
			Student std2(cname, cphone, purpose, requirement, downpayment);

			student = std2;
			
			break;
		}
		case 1: 
		{
			cin >> name;
			purpose = catchPurpose();

			if (display2())
			{
				cout << "\t\t��������" << endl;
				cin >> requirement;
				cout << "\t\t����û����0���� " << endl;
				cin >> downpayment;
			}

			strcpy_s(cname, name.c_str());//strncpy(buf, str.c_str(), 10);

			Student std(cname,purpose, requirement, downpayment);

			student = std;

			break;
		}
		default: 
		{
			cout << "�޴�ƥ������������룡";
			display();
			break;
		}
	
	}
	return;
}

Purpose AddSTDMenu::catchPurpose() 

{
	vector<string> list;
	int a = 1;
	cout << "�������ѧ��Ŀ���� :  ";
	cin >> a;
	cout << endl;
	string ttt;
	cout << "������ֱ�����γ�����" << endl;

	for (int i = 1; i <= a; i++)
	{
		cout << "������� " << i << " ����Ŀ :  ";
		cin >> ttt;
		list.push_back(ttt);
		cout << endl;
	}
	if (a == 0)
	{
		ttt = "�޿�Ŀ";
		list.push_back(ttt);

	}
	Purpose pur(list);
	return pur;
}

Student AddSTDMenu::getStudent() 
{
	return this->student;
}

