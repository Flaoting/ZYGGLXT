#include "Table.h"
#include "People.h"
#include "Lesson.h"
#include <string>

using namespace std;


Table::Table(People* peo, Date startDate, Date endDate,int num,char* name):FatherTable(peo)

				//��ֹʱ�䣬�������,�ӿ�ʼ����������

{
	strcpy_s(this->theOtherName, name);
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

Table::Table(People* peo, char* name) :FatherTable(peo)

	//ֻ�����ˣ�Ȼ���������α��������

{
	strcpy_s(this->theOtherName, name);
	
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

Table::Table(People* peo, Date startDate, int x,int num, char* name) :FatherTable(peo)
	
	//��ʼʱ�䣬�γ̽���,x���м��ڿΣ�num�ǵڼ��ڿ�

{
	strcpy_s(this->theOtherName, name);

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
	strcpy_s(this->theOtherName, "test");

	selfName = "StudentTable";
	
	this -> number = 0;


}


void Table::displaySTD() 

//չʾһ�¿α�

{
	FatherTable::display();

	cout << "��ʦ�� :  " << this->theOtherName << endl;
	
	cout << "�γ̽����� " << this->number << endl;

	while(!lessonTimeTable.empty())

	//ѭ���ó����ȶ����еĿγ�
	
	{

		Lesson lesson (lessonTimeTable.top());

		lesson.display();
		
		lessonTimeTable.pop();

	}

}

void Table::displayTEA()

//չʾһ�¿α�

{
	FatherTable::display();

	cout << "�ýڿ�ѧ���� :  " << this->theOtherName << endl;

	cout << "�γ̽����� " << this->number << endl;

	while (!lessonTimeTable.empty())

		//ѭ���ó����ȶ����еĿγ�

	{

		Lesson lesson(lessonTimeTable.top());

		lesson.display();

		lessonTimeTable.pop();

	}

}

int Table::getNum() 

{
	return this->number;
}

Table::Table(StoreTable& obj) 

{
	strcpy_s(this->theOtherName, obj.theOtherName);

	this->number = obj.num;

	for (int i = 0; i < obj.num; i++) 
	{
		this->lessonTimeTable.push(obj.lessonTable[i]);
	}

	//ע����������������ำֵ
	//��ʵ��������Ϣûʲô�ã��������ȶ�����
	startDate = obj.lessonTable[0];
	//endDate = obj.lessonTable[obj.num - 1];
}

void Table::translateFromStoreTable(StoreTable& obj) 
{
	strcpy_s(this->theOtherName, obj.theOtherName);
	
	this->number = obj.num;

	for (int i = 0; i < obj.num; i++)
	{
		this->lessonTimeTable.push(obj.lessonTable[i]);
	}
	startDate = obj.lessonTable[0];
	//endDate = obj.lessonTable[obj.num - 1];

}


void Table::ReviseTeam() 

{

	char TempName[15];
	strcpy_s(TempName, this->ownerName);
	strcpy_s(this->ownerName, this->theOtherName);
	strcpy_s(this->theOtherName, TempName);

}
