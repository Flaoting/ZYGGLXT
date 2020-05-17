#include "Purpose.h"
#include <string>
#include <string.h>

using namespace std;



Purpose::Purpose(vector <string> a)

//���ι����� �ô���һ��vector������г�ʼ��

{
	
	memset(subject, '\0', sizeof(subject));

	sum = a.capacity();
	int i = 0;
	string s;
	try 
	{
		for (vector<string>::iterator it = a.begin(); it != a.end(); it++, i++)
		{
			if (i > 9) 
			{
				throw 936; 
			}
			s = *it;
			strcpy_s(subject[i], s.c_str());
		}

	}
	catch (int goal) 
	{
		cout << "�������\t" <<goal;
		cout << "Subject���鱬ջ����ʧ�˵��߸��Ժ�Ŀ�Ŀ��Ϣ" << endl;
	}
	
}

Purpose::Purpose(const Purpose& obj)

{

	memset(subject, '\0', sizeof(subject));

	this->sum = obj.sum;

	for (int i = 0; i < obj.sum; i++)
	{
		strcpy_s(subject[i], obj.subject[i]);
	}

}

Purpose::Purpose() 

{

	memset(subject, '\0', sizeof(subject));
	sum = 0;
	//�������
}



Purpose::~Purpose() { }



Purpose Purpose::operator=(const Purpose& obj)
{
	try {

		if (obj.sum > 9) 
		{
			throw 555;
		}
		sum = obj.sum;
		for (int i = 0; i < obj.sum; i++)
		{
			strcpy_s(subject[i], obj.subject[i]);
	
		}

		return *this;
	}
	catch (int goal) {

		cout << "����Խ�磬�������"<<goal << endl;
	}
	return *this;
}



void Purpose::display() 
{
	cout << "��Ŀ:     ";
	
	for (int i = 0; i < sum; i++) 
	{
		cout << subject[i]<<"  ";
	}

	cout << endl;
}



