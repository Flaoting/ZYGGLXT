#include "People.h"
#include "Table.h"
#include "Student.h"
#include "Purpose.h"
#include <string>
#include <string.h>

using namespace std;

Student::Student(char* name, char sex, char* phone, char* QQ, Purpose subj, string requirement , int downpayment )
	:People(name,sex,phone)
{
	strcpy_s(this->QQ, QQ);
	this->sub = subj;
	this->requirement = requirement;
	this->downPayment = downpayment;
}

Student::Student(char* name, char sex, char* phone, Purpose subj,string requirement , int downpayment )
	:People(name,sex,phone) 
{
	this->sub = subj;
	this->requirement = requirement;
	this->downPayment = downpayment;
	this->downPayment = downpayment;
}

Student::Student(char* name, char* phone, Purpose subj, string requirement , int downpayment ) 
:People (name,phone)
{
	this->sub = subj;
	this->requirement = requirement;
	this->downPayment = downpayment;
	this->downPayment = downpayment;

}

Student::Student(char* name, Purpose subj, string requirement, int downpayment )
	:People(name) 
{
	this->sub = subj;
	this->requirement = requirement;
	this->downPayment = downpayment;
	this->downPayment = downpayment;

}

Student::Student(char* name, char sex, Purpose subj, string requirement , int downpayment)
	:People(name,sex)
{
	this->sub = subj;
	this->requirement = requirement;
	this->downPayment = downpayment;
	this->downPayment = downpayment;

}

Student::Student(const Student& obj) :People(obj)
{
	strcpy_s(this->QQ, obj.QQ);
	this->sub = obj.sub;
	this->requirement = obj.requirement;
	this->downPayment = obj.downPayment;
}

Student::Student() :People() 
{
	strcpy_s(QQ, "Test");
	requirement = "test";
	downPayment = 0;
}
/* char name[15];//����
    char gender;//�Ա�
    char phone[20];//�绰����
    const int ID;//״Ԫ��Ψһʶ���,���ɸ���
	char QQ[20];
	int downPayment;//Ԥ������
	Purpose sub;//��Ŀ
	string requirement;
	*/

	Student Student::operator = (const Student& obj)

	//���� =�����
{
	strcpy_s(name, obj.name);
	this->gender = obj.gender;
	strcpy_s(phone, obj.phone);
	this->ID = obj.ID;
	strcpy_s(this->QQ, obj.QQ);
	this->downPayment = obj.downPayment;
	this->sub = obj.sub;
	this->requirement = obj.requirement;

	return *this;
}

void Student::display() 
{
	People::display();
	
	cout <<"  QQ  "<<QQ<<"  ��������  "<< requirement << "  �ѽ�����  " << downPayment << endl;
	
	sub.display();
}



void Student::setQQ(char* QQ) 
{
	strcpy_s(this->QQ, QQ);
}

void Student::setDownPayment(int DP)
{
	this->downPayment = DP;
}

void Student::setRequirement(string s)
{
	this->requirement = s;
}

/*void Student::setTable() 
{	
	Table temp;
	this->table = temp;
}*/

void Student::changeTable() {
	//�д��о�
}