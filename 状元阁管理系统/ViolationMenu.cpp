#include "ViolationMenu.h"
#include <iostream>

using namespace std;



ViolationMenu::ViolationMenu(Manager &obj):operatorManager(obj)
{
	//�������������
}

ViolationMenu::ViolationMenu(const ViolationMenu& obj)
{
	this->operatorManager = obj.operatorManager;
}



ViolationMenu:: ~ViolationMenu() 
{
	//�����������������
}



void ViolationMenu::display()
{
	try
	{
		system("CLS");
		
		cout << "************************************************************" << endl << endl;
		cout << "������ʾ  ��ѧ�¹ʼ�¼ǰ���ȼ���ʦ������Ϣ�Ѿ�¼��ϵͳ" << endl;
		cout << "������ʾ  ��ѧ�¹ʼ�¼һ����¼�޷��޸Ļ�ɾ�������������" << endl;
		
		if (!checkToContinue())
		{
			operationCancled();
			return;
		}
		
		system("cls");
		
		string TeaName, remarks;
		Teacher tea;
		int first, second;
		Date occurTime;
		
		cout << "************************************************************" << endl << endl;
		cout << "\t\t��ѧ�¹ʼ�¼" << endl << endl;
		cout << "��������չʾ��ѧ�¹ʾ���ϸ�ڣ���˶Բ���¼�˴�Υ�����ڵļ���" << endl;
		system("pause");
		system("cls");

		display2();
		
		first = getFirst();
		second = getSecond(first);
		cout << "�������ʦ���� :  ";
		cin >> TeaName;
		tea = checkThisTEA(TeaName);
		cout << "�������¼��ע :  ";
		cin >> remarks;
		cout << "�������������¼�����ʱ��" << endl;
		occurTime = getOTD();

		cout << "������ʾ  ��ѧ�¹ʼ�¼�Ѿ���¼�޷��޸Ļ�ɾ�������������" << endl;
		if (!checkToContinue())
		{
			operationCancled();
			return;
		}

		ViolationRecord VM(operatorManager, tea, first, second, occurTime, remarks);
		if (saveThisRecord(VM))
		{
			cout << "�˴μ�¼����ɹ�!!"<<endl;
		}
		else
		{
			cout << "�˴μ�¼����ʧ��" << endl;
		}
		return;
	}
	catch(int)
	{
		cout << "��ʦ��Ϣ��ʧ��,�����ʦ��Ϣ�Ƿ���ڻ�������ƴд�Ƿ���ȷ" << endl;
		cout << "�粻���ڣ����ȴ�����ʦ��Ϣ!!!" << endl;
	}
	
}



void ViolationMenu ::display2() 
{
	cout << "\tһ����ѧ�¹�" << endl;
	cout << "\t\t1.δʹ�ñ�����ͳһ��ҳü�ĵ���ʽ����ӡ�ļ�" << endl;
	cout << "\t\t2.�޿��ڼ�����ϰ�һ�������ѧ�ص����ֻ�" << endl;
	cout << "\t\t3.�Ͽ�ʱ���ֻ�û�зŵ�ָ���ص�" << endl;
	cout << "\t\t4.�Ͽ��ڼ��ʦ֮�����Ļ���ѧ������" << endl;
	cout << "\t\t5.δ��ʱ��ҳ�����" << endl;
	cout << "\t\t6.�Ͽγٵ���δ����5����" << endl;
	cout << "\t\t7.����" << endl;
	cout << "\t\t8.����û�м�ʱ���н���" << endl;
	
	cout << "\t������ѧ�¹�" << endl;
	cout << "\t\t1.�Ͽ�ʱ��ʹ���ֻ�" << endl;
	cout << "\t\t2.�Ͽλ��Ѵ���ʱ����ѧ������" << endl;
	cout << "\t\t3.�Ͽγٵ�5��������" << endl;
	cout << "\t\t4.˽�Ե����α�δ��������Աͬ��" << endl;
	cout << "\t\t5.����ѧ��ѧϰ�ĵط�������һ¥������������" << endl;
		
	cout << "\t������ѧ�¹�" << endl;
	cout << "\t\t1.˽����ѧ���շѣ�˽�Խӿ�" << endl;
	cout << "\t\t2.�����ع�����Ա����ײ��������" << endl;
	cout << "\t\t3.ѧ��δ��ҵǰ����̸��������������˽���ɲ���Ӱ��" << endl;

	return;
}



int ViolationMenu::getFirst()
{
	system("pause");
	system("cls");
	int f=0;

	while (f <= 0 || f > 4)
	{
		if (f != 0)
		{
			
			cout << "��������������ٴ����룡��" << endl;
		}
		cout << "1. һ����ѧ�¹�" << endl;
		cout << "2. ������ѧ�¹�" << endl;
		cout << "3. ������ѧ�¹�" << endl;
		cout << "4. ������ѧ�¹�" << endl;
		cout << "�������ѧ�¹ʵȼ�(1-4) :   ";
		cin >> f;
	}
	return f;
}



int ViolationMenu::getSecond(int first)

{
	system("cls");
	switch (first) 
	{
		case 1: 
		{
			cout << "һ����ѧ�¹�" << endl;
			cout << "\t1.δʹ�ñ�����ͳһ��ҳü�ĵ���ʽ����ӡ�ļ�" << endl;
			cout << "\t2.�޿��ڼ�����ϰ�һ�������ѧ�ص����ֻ�" << endl;
			cout << "\t3.�Ͽ�ʱ���ֻ�û�зŵ�ָ���ص�" << endl;
			cout << "\t4.�Ͽ��ڼ��ʦ֮�����Ļ���ѧ������" << endl;
			cout << "\t5.δ��ʱ��ҳ�����" << endl;
			cout << "\t6.�Ͽγٵ���δ����5����" << endl;
			cout << "\t7.����" << endl;
			cout << "\t8.����û�м�ʱ���н���" << endl;
			break;
		}
		case 2:
		{
			cout << "������ѧ�¹�" << endl;
			cout << "\t1.�Ͽ�ʱ��ʹ���ֻ�" << endl;
			cout << "\t2.�Ͽλ��Ѵ���ʱ����ѧ������" << endl;
			cout << "\tt3.�Ͽγٵ�5��������" << endl;
			cout << "\t4.˽�Ե����α�δ��������Աͬ��" << endl;
			cout << "\t5.����ѧ��ѧϰ�ĵط�������һ¥������������" << endl;
			break;
		}
		case 3:
		{
			cout << "������ѧ�¹�" << endl;
			cout << "\t1.˽����ѧ���շѣ�˽�Խӿ�" << endl;
			cout << "\t2.�����ع�����Ա����ײ��������" << endl;
			cout << "\t3.ѧ��δ��ҵǰ����̸��������������˽���ɲ���Ӱ��" << endl;
			break;
		}

		case 4:
		{
			cout << "�������ͽ�ѧ�¹�" << endl;
			cout << "1. ���������1������ϸ��ӱ�ע" << endl;
			break;
		}
	}
	cout << endl;
	cout << "������˴��¼����� :  ";

	int t;
	cin >> t;
	return t;
}



Teacher ViolationMenu::checkThisTEA(string name) 

{
	OperateTEA OT;
	Teacher tea;
	if (!OT.readPreFile(name))
	{
		throw 4511;
	}
	tea = OT.getTeacher();
	return tea;
}



Date ViolationMenu::getOTD() 
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
		Date ans(month, day);
		return ans;
	}
}



bool ViolationMenu::saveThisRecord(ViolationRecord& VR) 


{
	RecordInfo ADD("ViolationRecord");
	ofstream file;

	file.open(ADD.getCompleteAddress(), ios::out | ios::binary | ios::app);

	if (!file)
	{
		cout << "Warning ��¼�ļ���ʧ��  " << endl;
		cout << "�����Ƿ����·��" << ADD.getCompleteAddress() << endl;
		return false;
	} 

	file.write((char*)&VR, sizeof(VR));

	file.close();

	return true;

}


