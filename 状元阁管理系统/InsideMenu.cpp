#include "InsideMenu.h"
#include <iostream>
using namespace std;
InsideMenu::InsideMenu() 
{

}
InsideMenu::~InsideMenu() {

}
void InsideMenu::display()
{
	system("cls");
	cout << "*************************************************************************" << endl << endl << endl;
	cout << "\t\t״Ԫ�����ϵͳ�ڲ�����" << endl << endl << endl;
	cout << "\t1.  ע�����Ա    2. ��ѯ��ʦ��Ϣ    3. ��ѯѧ����Ϣ  " << endl << endl;
	cout << "\t4.  ����½�ʦ    5. �޸Ľ�ʦ��Ϣ    6. �޸�ѧ����Ϣ  " << endl << endl;
	cout << "\t7.  ��ѯ���ʱ�    8. ��¼��ѧ�¹�    9. ��ѯ�γ̵���  " << endl << endl;
	cout << "\t10. �����ˮ��    11.��ѯϵͳ��¼    12.�����ߵ�ͨ��  " << endl << endl;
	cout << endl;
	cout << "************************************************************************" << endl << endl;
}

int InsideMenu::getCommend()
{
	int commender = 0;
	do 
	{
		cout << "��������Ҫʹ�ù��ܵı�� :  ";
		cin >> commender;
	} while (commender < 0 || commender > 12);
	return commender;
}


