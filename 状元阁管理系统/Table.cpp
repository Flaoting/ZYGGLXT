#include "Table.h"
#include "People.h"
#include "Lesson.h"
#include <string>

using namespace std;


Table::Table(People* peo, Date startDate, Date endDate,int num):FatherTable(peo)

				//��ֹʱ�䣬�������,�ӿ�ʼ����������

{
	if (num > 5)
	{
		cout << "��ע�⣬�γ�ʱ�䳬��������Χ��" << endl;
	}

	selfName = "StudentTable";

	this -> number = endDate - startDate;

	
	for (Date i = startDate; i <= endDate; i++) 
	
		//�������ڽ���ѭ�����룬�ڲ�������ʱ�Ķ���

	{
			Lesson lesson(i, num);
			lessonTimeTable.push(lesson);	
	}

}

Table::Table(People* peo) :FatherTable(peo)

	//ֻ�����ˣ�Ȼ���������α��������

{
	
	selfName = "StudentTable";

	this->number = 0;
	
	int year = 2020, month, day, num=1;
	
	string expect1;
	try {

		cout << "�������һ�ڿε��·ݣ� ";
		cin >> month;
		cout << endl;
		
		if (month >12||month<=0) 
		{
			expect1 = "�·������쳣������";
			throw expect1;
		}
		
		cout << "�������һ�ڿ����ڣ� ";
		cin >> day;
		cout << endl;
		if (day > 31 || day <= 0)
		{
			expect1 = "���������쳣!!!";
			throw expect1;
		}
		
		cout << "�������ǵڼ��ڿΣ� ";
		cin >> num;
		cout << endl;
		if (num > 5 || num <= 0)
		{
			expect1 = "�γ����������쳣!!!";
			throw expect1;
		}
	}
	
	catch (char* esp)
	{
		printf("%s", esp);
	}

	/*Lesson lesson(year, month, day, num);
	lessonTimeTable.push(lesson);
	this->number++;*/
	
	cout << "������������ڣ�����  0  ʱ����" << endl;
	
	while (1) 
	{
		if (day == 0)
		
		{
			break;
		}
		
		if (day == 1)
		{
			month++;
		}
		
		Lesson lesson(year, month, day, num);
		lessonTimeTable.push(lesson);
		this->number++;

		cin >> day;
	}


}

Table::Table(People* peo, Date startDate, int x,int num) :FatherTable(peo)
	
	//��ʼʱ�䣬�γ̽���,x���м��ڿΣ�num�ǵڼ��ڿ�

{
	if (num > 5)
	{
		cout << "��ע�⣬�γ�ʱ�䳬��������Χ��" << endl;
	}

	selfName = "StudentTable";

	this->number = x;

	int cnt = 0;
	for (Date i=startDate;cnt<x ; i++) 
	{
		Lesson lesson(i, num);
		lessonTimeTable.push(lesson);
		cnt++;
	}

}

Table::Table() :FatherTable( )
{
	/* name[20] = "ʵ��Ļ�����";
	People pe(name);
	strcpy_s(this->name, pe.getName());
	this->ID = pe.getID();
	*/

	selfName = "StudentTable";
	
	this -> number = 0;


}


void Table::display() 

//չʾһ�¿α�

{
	FatherTable::display();

	cout << "�γ̽����� " << this->number << endl;

	while(!lessonTimeTable.empty())

	//ѭ���ó����ȶ����еĿγ�
	
	{

		Lesson lesson (lessonTimeTable.top());
		lesson.display();
		lessonTimeTable.pop();

	}

}
