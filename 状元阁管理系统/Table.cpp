#include "Table.h"
#include "People.h"
#include "Lesson.h"
#include <string>

#include <iostream>
using namespace std;


Table::Table(People* peo, Date startDate, Date endDate,int num,char* name, int Type)
	:FatherTable(peo)

				//��ֹʱ�䣬�������,�ӿ�ʼ����������

{
	this->tableID = -1;
	this->classType = Type;
	strcpy_s(this->theOtherName, name);
	if (num > 5)
	{
		cout << "��ע�⣬�γ�ʱ�䳬��������Χ��" << endl;
	}
	string str = peo->getName();//��ñ��ӵ����
	selfName = "ѧ��: "+ str+" �Ŀα� ";

	this -> number = endDate - startDate;

	
	for (Date i = startDate; i <= endDate; i++) 
	
		//�������ڽ���ѭ�����룬�ڲ�������ʱ�Ķ���

	{
			Lesson lesson(i, num);
			lessonTimeTable.push(lesson);	
	}

}

Table::Table(People* peo, char* name, int Type):FatherTable(peo)

	//ֻ�����ˣ�Ȼ���������α��������

{
	this->tableID = -1;
	this->classType = Type;
	string str = peo->getName();//��ñ��ӵ����
	selfName = "ѧ��: " + str + " �Ŀα� ";

	strcpy_s(this->theOtherName, name);

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
		if (num > 6 || num <= 0)
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

Table::Table(People* peo, Date startDate, int x,int num, char* name, int Type)
	:FatherTable(peo)
	
	//��ʼʱ�䣬�γ̽���,x���м��ڿΣ�num�ǵڼ��ڿ�

{
	this->tableID = -1;
	this->classType = Type;

	string str = peo->getName();//��ñ��ӵ����

	selfName = "ѧ��: " + str + " �Ŀα� ";

	strcpy_s(this->theOtherName, name);

	if (num > 5)
	{
		cout << "��ע�⣬�γ�ʱ�䳬��������Χ��" << endl;
	}

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
	this->tableID = -1;
	this->classType = 1;
	strcpy_s(this->theOtherName, "test");

	selfName = "ѧ��: test �Ŀα� ";
	
	this -> number = 0;


}



Table::Table(const Table& obj):FatherTable(obj)
{
	this->tableID = obj.tableID;
	this->classType = obj.classType;
	this->endDate = obj.endDate;
	this->startDate = obj.startDate;
	this->lessonTimeTable = obj.lessonTimeTable;
	this->number = obj.number;
	strcpy_s(this->theOtherName, obj.theOtherName);
}



Table::Table(StoreTable& obj) 

{
	this->tableID = obj.tableID;
	strcpy_s(this->ownerName, obj.ownerName);
	this->ownerID = obj.ownerID;

	this->classType = obj.classType;

	this->selfName = obj.selfName;

	strcpy_s(this->theOtherName, obj.theOtherName);

	this->number = obj.num;

	for (int i = 0; i < obj.num; i++) 
	{
		this->lessonTimeTable.push(obj.lessonTable[i]);
	}

		//ע����������������ำֵ
		//��ʵ��������Ϣûʲô�ã��������ȶ�����

	startDate = obj.lessonTable[0];
		//endDate�ǲ���Ҫ����Ϣ��Ϊ�˱��⾯�潫���ʼ��
	endDate = obj.lessonTable[0];

}



void Table::translateFromStoreTable(StoreTable& obj) 

{
	this->tableID = obj.tableID;
	strcpy_s(this->ownerName, obj.ownerName);
	
	this->ownerID = obj.ownerID;

	this->classType = obj.classType;

	this->selfName = obj.selfName;

	strcpy_s(this->theOtherName, obj.theOtherName);
	
	this->number = obj.num;

	for (int i = 0; i < obj.num; i++)
	{
		this->lessonTimeTable.push(obj.lessonTable[i]);
	}
	
	startDate = obj.lessonTable[0];

	//endDate�ǲ���Ҫ����Ϣ��Ϊ�˱��⾯�潫���ʼ��
	endDate = obj.lessonTable[0];

}



Table Table::operator=(const Table& obj) 
{
	this->tableID = obj.tableID;
	this->classType = obj.classType;

	FatherTable ::operator=(obj);

	this->endDate = obj.endDate;
	this->startDate = obj.startDate;
	this->lessonTimeTable = obj.lessonTimeTable;
	this->number = obj.number;
	strcpy_s(this->theOtherName, obj.theOtherName);
	return *this;

}



void Table::displaySTD() 

//չʾһ�¿α�

{
	Table objTab(*this);

	cout << "ѧ��  " << this->ownerName << "  �Ŀα�" << endl;

	string TYPE = translateNumToClassType(this->classType);
	
	cout << "��ʦ��   :  " << this->theOtherName << endl;
	cout << "�γ����� :  " << TYPE << endl;
	cout << "�γ̽��� :  " << this->number << endl;

	while(!objTab.lessonTimeTable.empty())

	//ѭ���ó����ȶ����еĿγ�
	
	{

		Lesson lesson (objTab.lessonTimeTable.top());

		lesson.display();
		
		objTab.lessonTimeTable.pop();

	}

}

void Table::displayTEA()

//չʾһ�¿α�

{
	Table objTab(*this);

	cout << "��ʦ  " << this->ownerName << "  �Ŀα�" << endl;

	string TYPE = translateNumToClassType(this->classType);

	cout << "�ýڿ�ѧ���� :  " << this->theOtherName << endl;
	cout << "�γ����� :  " << TYPE << endl;
	cout << "�γ̽����� " << this->number << endl;

	while (!objTab.lessonTimeTable.empty())

		//ѭ���ó����ȶ����еĿγ�

	{

		Lesson lesson(objTab.lessonTimeTable.top());

		lesson.display();

		objTab.lessonTimeTable.pop();

	}

}




void Table::shortShowSTD()
{
	//���չʾѧ����ͷ��Ϣ
	cout << "ѧ��  " << this->ownerName << "  �Ŀα�" << endl;


	string TYPE = translateNumToClassType(this->classType);

	cout << "��ʦ��   :  " << this->theOtherName << endl;
	cout << "�γ����� :  " << TYPE << endl;
	cout << "�γ̽��� :  " << this->number << endl;
	
}

void Table:: shortShowTEA() 
{
	//���չʾ��ʦ��ͷ��Ϣ
	cout << "��ʦ  " << this->ownerName << "  �Ŀα�" << endl;


	string TYPE = translateNumToClassType(this->classType);

	cout << "�ýڿ�ѧ���� :  " << this->theOtherName << endl;
	cout << "�γ����� :  " << TYPE << endl;
	cout << "�γ̽����� " << this->number << endl;

}
void Table::shortShortShowTEA() 
{


	string TYPE = translateNumToClassType(this->classType);

	cout << setw(5) << this->theOtherName;
	cout << setw(10) << TYPE;
	cout << setw(5) << this->number << "��" << endl;

}



void Table::ReviseTeam() 

{
	string str = this->theOtherName;

	selfName = "��ʦ: " + str + " �Ŀα� ";
	
	char TempName[30];
	strcpy_s(TempName, this->ownerName);
	strcpy_s(this->ownerName, this->theOtherName);
	strcpy_s(this->theOtherName, TempName);

}

void Table::ReviseTeamToSTD()

{
	string str = this->theOtherName;

	selfName = "ѧ��: " + str + " �Ŀα� ";

	char TempName[30];

	strcpy_s(TempName, this->ownerName);
	strcpy_s(this->ownerName, this->theOtherName);
	strcpy_s(this->theOtherName, TempName);

}



void Table::clearThisTable() 
{
	//ѭ����ն�����Ŀγ�
	while (!lessonTimeTable.empty())
	{
		lessonTimeTable.pop();
	}
}

string Table::getSelfName()
{
	return this->selfName;
}



int Table::getClassType() 
{
	return this->classType;
}



string Table::getTheOtherName() 
{
	string str = this->theOtherName;
	return str;
}



int Table::getNum() 

{
	return this->number;
}



int Table::getTableID() 
{
	return this->tableID;
}
