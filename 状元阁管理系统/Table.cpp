#include "Table.h"
#include "People.h"
#include "Lesson.h"
#include <string>

using namespace std;


Table::Table(People* peo, Date startDate, Date endDate,int num)

				//��ֹʱ�䣬�������,�ӿ�ʼ����������

{
	strcpy_s(this->name, peo->getName());

	this->ID = peo->getID();

	this -> number = endDate - startDate;

	
	for (Date i = startDate; i <= endDate; i++) 
	
		//�������ڽ���ѭ�����룬�ڲ�������ʱ�Ķ���

	{
		Lesson lesson(i, num);
		lessonTimeTable.push(lesson);
	}

}



Table::Table(People*) {
	//ֻ�����ˣ�Ȼ���������α��������

}




Table::Table(People*, Date startDate, int x,int num) 
	
	//��ʼʱ�䣬�γ̽���

{
	

}




void Table::display() 

//չʾһ�¿α�

{
	cout << "�γ̽����� " << this->number << endl;

	while(!lessonTimeTable.empty())

	//ѭ���ó����ȶ����еĿγ�
	
	{

		Lesson lesson (lessonTimeTable.top());
		lesson.display();
		lessonTimeTable.pop();

	}

}
Table::Table() {

 }