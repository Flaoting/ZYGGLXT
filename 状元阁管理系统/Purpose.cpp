#include "Purpose.h"
#include <string>

Purpose::Purpose(vector <string> a)

{
	int i = 0;
	
	try 
	{
		for (vector<string>::iterator it = a.begin(); it != a.end(); it++, i++)
		{
			if (i == 7) 
			{
				throw 936; 
			}
			list.push_back(*it);
			subject[i] = *it;
		}

	}
	catch (int goal) 
	{
		cout << "�������936 \t";
		cout << "Subject���鱬ջ����ʧ�˵��߸��Ժ�Ŀ�Ŀ��Ϣ" << endl;
	}
	
}

Purpose::Purpose() 

{
	//�������
}

string Purpose::getList() 
{
	
	static vector<string>::iterator it = list.begin();
	
	return *it;

}

Purpose Purpose::operator=(const Purpose& obj)
{
	list = obj.list;
	
	for (int i = 0; i < list.capacity(); i++)
	{
		subject[i] = obj.subject[i];
	}

	return *this;
}

void Purpose::display() 
{
	cout << "��Ŀ�� ";
	
	/*for (vector<string>::iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it<<" " ;
	}*/
	for (int i = 0; i < list.capacity(); i++) 
	{
		cout << subject[i]<<"  ";
	}
	cout << endl;
}