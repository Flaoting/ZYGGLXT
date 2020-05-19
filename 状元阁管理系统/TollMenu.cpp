#include "TollMenu.h"
#include <iostream>
#include <iomanip>
using namespace std;

TollMenu::TollMenu(Manager& obj ):operatorManager(obj)
{ 
	//���캯��
}

TollMenu::TollMenu(const TollMenu& obj)
{
	this->operatorManager = obj.operatorManager;
	//�������캯��
}

TollMenu::~TollMenu( )
{
	//����
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
	
	file.open(ADD.getCompleteAddress(), ios::binary | ios::app);
	
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


int TollMenu::HowMuchToPay(Student &std) 
{
	string name = std.getName();
	OperateTable OT;
	Table T;
	int i = 1;
	int summery=0;
	if (!OT.readPreFile(name, i))
	{
		cout << "�α��ļ���ȡʧ��" << endl;
		return 0;
	}
	
	do 
	{
		T = OT.getTable();
		T.shortShowSTD();		//���������bug
		int price = getClassTypeInPrice(T.getClassType());
		int sum = T.getNum() * 2 * price;
		cout << "�γ̵��� " <<setw(5)<<price << setw(5) << "Ԫ/Сʱ"<<endl;
		cout << "�˽ڿ�С�� " << setw(5) << sum << setw(5) << " Ԫ " << endl;
		summery += sum;
		i++;
		system("pause");
	} while (OT.readPreFile(name, i));

	return summery;
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
		int how = HowMuchToPay(thisStud);
		int sorry = thisStud.getDownPayment();
		cout << "�γ̷��ù��� " << setw(5) << how << setw(5) <<"Ԫ "<< endl;
		cout << "�ѽ��ɶ���   " << setw(5) << sorry<< setw(5) << "Ԫ" << endl;
		cout << "����������� " << setw(5) << how - sorry << setw(5) << "Ԫ" << endl<<endl;
		
		float payment;
		
		cout << "�����������ɷ��ã�  ";
		cin >> payment;
		if (display2())

		{
			cout << "�������տʽ :  ";
			cin >> PayWay;
			cout << "����ӱ�ע     :  ";
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

		cout << "�����ɹ��� ������ϸ��Ϣ���� : " << endl;
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




int TollMenu::getClassTypeInPrice(int key)
{
	ConClassPrice CCP;
	map<int, ClassPrice> Price = CCP.getMapFromCon();
	
	auto it = Price.find(key);
	
	ClassPrice CP(-1,-1,-1,"test");

	if (it != Price.end())
	{
		 CP= (*it).second;
		 return CP.getInPrice();
	}
	return -1;
}





