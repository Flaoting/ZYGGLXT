#include "TollMenu.h"
#include <iostream>
using namespace std;

TollMenu::TollMenu(Manager& obj ):operatorManager(obj)
{ 
	//���캯��
}

TollMenu::~TollMenu( )
{
	//����
}


void TollMenu::display() 
	//�����˵�
{
	try 
	{
		system("CLS");
		string STDname, PayWay, Remarks;
		Student thisStud;
		cout << "************************************************************" << endl << endl << endl;
		cout << "\t\t���ɿγ̷���" << endl << endl;
		cout << "������ѧ������ :  ";
		cin >> STDname;
		cout << endl;

		thisStud = checkSTDInfo(STDname);//

		cout << "��������:  \t��˶Խɷ�ѧ���ĸ�����Ϣ...  " << endl;
		if (!checkToContinue())
		{
			operationCancled();
			return;
		}
		float payment;
		cout << "�����������ɷ��ã�  ";
		cin >> payment;
		if (display2())

		{
			cout << "�������տʽ :  ";
			cin >> PayWay;
			cout << "����ӱ�ע :  ";
			cin >> Remarks;
		}


		TransactionRecord thisTR(this->operatorManager, thisStud, payment, PayWay, Remarks);

		if (!saveThisTranRecord(thisTR))
			//����ļ�����ʧ��	
		{
			cout << " �����ļ�����ʧ�ܣ������ڹ�����־�ϼ�¼�˴��տ���Ϣ��";
			cout << "����ʱ��ϵ������ԱFloating " << endl;
			return;
		}

		cout << "  �����ɹ��� ������ϸ��Ϣ���� : " << endl;
		cout << "��������Ա����  " << this->operatorManager.getName() << endl;
		cout << "ѧ������        " << thisStud.getName() << endl;
		cout << "�տ���        " << payment << endl;
		system("pause");
		return;


	}catch(int goal)
	{
		cout << "Warning  ѧ����Ϣ��ȡʧ�ܣ������Ƿ����" << endl;
		cout << "����ѧ������ƴд�Ƿ���ȷ�򴢴�·���Ƿ����" << endl;
		cout << "�������  " << goal << endl;
	}
	
}

bool TollMenu::display2()  
{
	cout << "Tips  �Ƿ�ı�Ĭ�ϵ��տʽ(�ֽ��տ�)������տע " << endl;
	if (checkToContinue()) 
	{
		return true;
	}
	return false;
}

Student TollMenu::checkSTDInfo(string STDname) 
{

	OperateSTD OS;
	Student stud;
	
	if (!OS.readPreFile(STDname))
	{
		throw 4511;
	}
	
	stud = OS.getStudent();
	stud.display( );
	return stud;

}

bool TollMenu::saveThisTranRecord(TransactionRecord thisTR ) 

{
	RecordInfo ADD("TransactionRecord");
	ofstream file;
	
	file.open(ADD.getCompleteAddress(), ios::out | ios::binary | ios::app);
	
	if (!file) 
	{
		cout << "Warning �����ļ���ʧ��  " << endl;
		cout << "�����Ƿ����·��" << ADD.getCompleteAddress() << endl;
		return false;
	}
	
	file.write((char*)&thisTR, sizeof(thisTR));
	
	file.close();


	RecordInfo SUM;
	ofstream file2;

	file2.open(SUM.getCompleteAddress(), ios::out | ios::binary | ios::app);
	
	if (!file2)
	{
		cout << "Warning �����ļ���ʧ��  " << endl;
		cout << "�����Ƿ����·��" << SUM.getCompleteAddress() << endl;
		return false;
	}

	file2.write((char*)&thisTR, sizeof(thisTR));
	
	file2.close();
	
	return true;

}

TollMenu::TollMenu(const TollMenu& obj)
{
	this->operatorManager = obj.operatorManager;
	//�������캯��
}



