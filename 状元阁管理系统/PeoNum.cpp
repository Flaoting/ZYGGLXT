#include "PeoNum.h"
#include "BaseFile.h"
#include <fstream>
#include <iostream>
using namespace std;



/*PeoNum::PeoNum(string UA, string FA) :BaseFile(UA, FA) 

{
	NowNum = -1;
}*/

PeoNum::PeoNum() 
{
	uniqueAddress = "PerInfo\\";
	fileName = "PeoNum.txt";
	completeFile = saveAddress + uniqueAddress + fileName;
	NowNum = -1;
}

PeoNum::~PeoNum()
{
	//�����������������
}

bool PeoNum::setFile(int a) 
{
	
	a++;
	
	fstream file(completeFile, ios::out);
	
	if (!file) 
	{
		return 0;
	}
	file << a << endl;
	
	file.close();
	
	return 1;

}

bool PeoNum::getNum() 
{
	int goal=-1;
	try
	{
		fstream file(completeFile, ios::in);
		if (!file)
		{
			throw 958;
		}
		while (!file.eof()) 
		{
			file >> goal;
		}
		
		file.close();
		setNowNum(goal);
		update(goal);
		return 1;
	}
	catch (int goal) 
	{
		if (goal == 958)
		{
			cout << "PeoNum�ļ����쳣��" << endl;
			cout << "�Ƿ�������ã�Y or N ��" << endl;
			string catcher;
			cin >> catcher;
			if (catcher[0] == 'Y') 
			{
				cout << "�����뵱ǰ���ID" << endl;
				try 
				{
					register int a,b=1;
					cin >> a;
					b=setFile(a);
					if (!b) 
					{
						throw 955;
					}
				}
				catch (int goal) 
				{
					cout << "�����쳣�����������" << goal << endl;
				}
				
			}
			
		}
	}
	return 0;
}

void PeoNum::update(int a) 
{
	a++;
	fstream file(completeFile, ios::app);
	file << a << endl;
	file.close();
}

void PeoNum::setNowNum(int a) 
{
	NowNum = a;
}


int PeoNum::returnNum() 
{

	if (getNum()) 
	{
		return NowNum;
	}

	else
	{
		cout << "��ȡNowNumʧ��!" << endl;
	}
	return -1;
}


