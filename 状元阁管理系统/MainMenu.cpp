#include "MainMenu.h"
#include <iostream>
using namespace std;

MainMenu::MainMenu() {}

void MainMenu::display() 

{
	
	system("cls");
	cout << "************************************************************" << endl<<endl<<endl;
	cout << "\t\t״Ԫ�����ϵͳ" << endl << endl << endl;
	cout << "\t1. ѧԱ����  2. ѧԱ����  3. ѧԱ�ɷ�  " << endl<<endl;
	cout << "\t4. ��ѯ�α�  5. �޸Ŀα�  6. ���ɿα�  " << endl << endl;
	cout << "\t7. ��ʦ���  8. �����¼  9. �ڲ�ͨ��  " << endl << endl;
	cout << endl;
	cout << "************************************************************" << endl<<endl;
	system("pause");

}

int MainMenu::getCommend()
{
	int commender=0;
	while (commender<0||commender>9)
	{
		cout << "��������Ҫʹ�ù��ܵı�� :  ";
		cin >> commender;
	}
	return commender;
}



