#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Student.h"
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
		exit(0);
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
		
}


bool saveStudentData(Student obj) 
{
	return 1;
}