#pragma warning (disable:4996)
#include <time.h>
#include "stdafx.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


bool checkBigPassword(string s) 

//��һ����BigBoss��Ȩ��
//#�Ž�β������endl
{
	
	ifstream password;
	
	string  fileAddress = "E:\\VisualStudio\\Data\\";
	string fileName = "password.txt";
	string file = fileAddress + fileName;
	
	password.open(file, ios::in);
	
	if (!password) 
	{
		cout << "password.txt can't be opened!" << endl;
		throw 2514;
	}
	
	char  pass[20];
	string a;
	
	password.getline(pass, 20,'#');
	
	password.close();
	
	a = pass;
	
	if (s == a) {
		return 1;
	}
	return 0;

}

bool saveAccount(string name, string password) 

//�����˻�˵����ǰ����β�ǻس�
//������ǰ���˻����ں��м� ��#�� ����
//����л��з�

{
	string  fileAddress = "E:\\VisualStudio\\Data\\";
	string fileName = "password.txt";
	string file = fileAddress + fileName;
	
	char na[20], pa[30];
	
	strcpy_s(na, name.c_str());
	strcpy_s(pa, password.c_str());
	
	ofstream f(file, ios::out|ios::app);
	
	if(!f)
	{
		cout << file << " can't be opened !" << endl;
		system("pause");
		return 0;
	}
	
	f << pa;
	
	f.put('#');
	f << na;

	f.put(10);
	
	f.close();
	
	return 1;
}

bool checkPassword(string input) 

//�������ļ�����ȡ���ݣ����������ݽ��к���

{
	string  fileAddress = "E:\\VisualStudio\\Data\\";
	string fileName = "password.txt";
	string file = fileAddress + fileName;
	
	ifstream password;
	password.open(file, ios::in);
	if (!password)
	{
		cout << "password.txt can't be opened!" << endl;
		throw 2514;
	}
	char pa[30];
	string str;

	//�ж϶�ȡ����,��֤����·�����з���ֵ��
	//���쳣������ǿ��׳��
	
		bool temp = 0;
		while (!password.eof()) 
		{
			password.getline(pa, 49, '#');
			str = pa;
			
			if (input == str) 
			{
				temp = 1;
				password.close();
				return 1;
			}

			char cc = password.get();
			while (!password.eof()&&cc != 10) 
			{
				cc = password.get();
			}

		}
		//���û�в��ҵ����׳�0
		if (!temp) {
			password.close();
			throw 0;
			return 0;
		}
		return 0;
}

bool checkSaveAddress(string saveAddress) 

//���ܺ���˵����
//���Ǽ������ļ�����·���Ƿ�Ϸ��ĺ���
//�Ϸ�����1 ���򷵻���
//�ᴴ��һ������ɾ���Ĳ����ļ�
{

	if (saveAddress[0] != 'E' && saveAddress[0] != 'C' && saveAddress[0] != 'D') 
	{
		return 0;
	}
	if (saveAddress[1] != ':') 
	{
		return 0;
	}
	if (saveAddress[2] != '\\')
	{
		return 0;
	}
	//���ϵļ��ܲ����ƣ��������ܱ�����Ϊ��ʽ����ȷ������������·���½���
	//ͬ���ļ�������
	ofstream checkin;
	
	string  fileAddress = saveAddress;
	
	string fileName = "���·��.txt";
	
	string file = fileAddress + fileName;
	
	checkin.open(file, ios::out);

	if (!checkin) 
	
	{
		return 0; 
	}
	checkin << "·�����ɹ���������" << endl;
	checkin << "(���ļ������Ƴ�)" << endl;
	return 1;

	checkin.close();

}

string getStringWithoutShow()

{
	int i = 0;
	char ch,password[30];
	while ((ch = _getch()) != '\r')
	{
		if (ch == '\b' && i > 0)
		{
			printf("\b \b");
			i--;
		}
		else
		{
			password[i++] = ch;
			cout << '*';
		}
	}
	password[i] = '\0';

	string pass(password);
	cout << endl;
	return pass;
}

string TimeStampToStandard(int a ) 

{
	//time_t now;
	//int unixTime = (int)time(&now);
	int unixTime = a;
	time_t tick = (time_t)unixTime;

	struct tm tm;
	char s[100];
	tm = *localtime(&tick);

	strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", &tm);
	
	string Standard(s);

	return Standard;

}\

bool checkToContinue( )
{
	string temp="N";
	cout << "�Ƿ�ִ�л����������� (Y or N)" << endl;
	cin >> temp;
	if (temp[0] != 'Y' && temp[0] != 'y') 
	{
		return false;
	}
	return true;
}

void operationCancled() 

{
	cout << "��������������ϵͳ�������·���:   ������ȡ�� �� " << endl;
}


string translateNumToClassType(int key) 
{
	map<int, string > classType;
	classType.insert(pair<int, string>(1, "һ��һ�γ�"));
	classType.insert(pair<int, string>(2, "һ�Զ��γ�"));
	classType.insert(pair<int, string>(3, "һ�����γ�"));
	classType.insert(pair<int, string>(4, "һ���Ŀγ�"));
	classType.insert(pair<int, string>(5, "С��ογ�"));
	classType.insert(pair<int, string>(6, "������γ�"));
	
	string Type = "δ���ҵ����ֿγ����� ";
	
	auto it = classType.find(key);

	if (it != classType.end())
	{
		Type = (*it).second;
	}
	return Type;

}

char checkGender() 
{
	string temp;
	cin >> temp;
	if (temp[0] == 'F' || temp[0] == 'f'||temp=="Ů")
	{
		return 'F';
	}
	if (temp[0] == 'M' || temp[0] == 'm'||temp=="��") 
	{
		return 'M';
	}

}

string trnaslateVioCode(int first, int second)

{
	switch (first) 
	{
		case 1:
		{
			map<int, string > VioType;
			
			VioType.insert(pair<int, string>(1, "δʹ�ñ�����ͳһ��ҳü�ĵ���ʽ����ӡ�ļ�"));
			VioType.insert(pair<int, string>(2, "�޿��ڼ�����ϰ�һ�������ѧ�ص����ֻ�"));
			VioType.insert(pair<int, string>(3, "�Ͽ�ʱ���ֻ�û�зŵ�ָ���ص�"));
			VioType.insert(pair<int, string>(4, "�Ͽ��ڼ��ʦ֮�����Ļ���ѧ������"));
			VioType.insert(pair<int, string>(5, "δ��ʱ��ҳ�����"));
			VioType.insert(pair<int, string>(6, "�Ͽγٵ���δ����5����"));
			VioType.insert(pair<int, string>(7, "����"));
			VioType.insert(pair<int, string>(8, "����û�м�ʱ���н���"));
		
			string Type = "�ļ���δ���ҵ��������͵Ľ�ѧ�¹�";
			string FT = "һ����ѧ�¹� : ";
			string Ans;
			
			auto it = VioType.find(second);

			if (it != VioType.end())
			{
				Type = (*it).second;
			}
			Ans = FT + Type;
			
			return Ans;
			
			break;
		
		}
		case 2: 
		{
			map<int, string > VioType;
			
			VioType.insert(pair<int, string>(1, "�Ͽ�ʱ��ʹ���ֻ�"));
			VioType.insert(pair<int, string>(2, "�Ͽλ��Ѵ���ʱ����ѧ������"));
			VioType.insert(pair<int, string>(3, "�Ͽγٵ�5��������"));
			VioType.insert(pair<int, string>(4, "˽�Ե����α�δ��������Աͬ��"));
			VioType.insert(pair<int, string>(5, "����ѧ��ѧϰ�ĵط�������һ¥������������"));
			
			string Type = "�ļ���δ���ҵ��������͵Ľ�ѧ�¹�";
			string FT = "������ѧ�¹� : ";
			string Ans;
			
			auto it = VioType.find(second);

			if (it != VioType.end())
			{
				Type = (*it).second;
			}
			Ans = FT + Type;
			
			return Ans;
			
			break;

		}
		case 3: 
		{
			map<int, string > VioType;
		
			VioType.insert(pair<int, string>(1, "˽����ѧ���շѣ�˽�Խӿ�"));
			VioType.insert(pair<int, string>(2, "�����ع�����Ա����ײ��������"));
			VioType.insert(pair<int, string>(3, "ѧ��δ��ҵǰ����̸��������������˽���ɲ���Ӱ��"));

			string Type = "�ļ���δ���ҵ��������͵Ľ�ѧ�¹�";
			string FT = "������ѧ�¹� : ";
			string Ans;
			
			auto it = VioType.find(second);

			if (it != VioType.end())
			{
				Type = (*it).second;
			}
			
			Ans = FT + Type;
			
			return Ans;
			
			break;

		}
		default:
		{
			string Type;
			Type = "δ���ҵ��˴������Ľ�ѧ�¹ʣ�����ϸ�Ķ��˴ν�ѧ�¹ʵı�ע!";
			return Type;
		}

	}
	
}







