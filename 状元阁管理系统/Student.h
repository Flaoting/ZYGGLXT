#ifndef STUDENT_H_
#define STUDENT_H_
#include "People.h"
#include "Purpose.h"
#include "Date.h"
#include <string>

class Student : public People {

	//ѧ���࣬��People ��������,�Ѿ��еĵĳ�Ա�У�name,ID,gender,phone ��phone �Ǽҳ����ֻ���

	//��Ҫ��¼ѧ����QQ�ţ���Ŀ�����÷�������ѧ��������Ҫ���Ƿ�����˶���


private:

	char QQ[20];
	int downPayment;//Ԥ������
	Purpose sub;//��Ŀ
	char requirement[100];//ѧ����Ҫ��

public:

	//�ĸ����캯�����ֱ���Ҫ
	//���� �Ա� �绰 QQ ��Ŀ Ҫ�� ����
	//���� �Ա� �绰 ��Ŀ Ҫ�� ����
	//���� �绰 ��Ŀ Ҫ�� ����
	//���� ��Ŀ Ҫ�� ����
	//���� �Ա� ��Ŀ Ҫ�� ����
	//��������ȱʡ����

	Student(char*, char, char*, char*, Purpose, string requirement = "��", int downpayment = 0);

	Student(char*, char, char*, Purpose, string requirement = "��", int downpayment = 0);

	Student(char*, char*, Purpose, string requirement = "��", int downpayment = 0);

	Student(char*, Purpose, string requirement = "��", int downpayment = 0);

	Student(char*, char, Purpose, string requirement = "��", int downPayment = 0);

	Student();

	Student(const Student& obj);//�������캯��

	Student operator = (const Student obj);

	void display();

	void setQQ(char*);

	void setDownPayment(int);

	void setRequirement(string);

	friend class OperateSTD;

	int getDownPayment();
};
#endif;