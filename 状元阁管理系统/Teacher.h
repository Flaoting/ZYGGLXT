#ifndef TEACHER_H_ 
#define TEACHER_H_
#include "Purpose.h"
#include "Table.h"
#include <vector>
<<<<<<< HEAD
class Teacher :public People {
	//��ʦ�࣬��People ��������,�Ѿ��еĵĳ�Ա�У�name,ID,gender,phone ��phone ����ʦ��
	//��Ҫ��¼��ʦ��QQ�ţ���Ŀ�����ʱ�׼
private:
	char QQ[20];
	vector <Purpose> table;
	int salary;
public:
	//���캯�� �� �����ʦֻ��һ�����캯����нˮΪ60
	//���� �Ա� phone QQ salary
=======

class Teacher :public People {
	
	//��ʦ�࣬��People ��������,
	//�Ѿ��еĵĳ�Ա�У�name,ID,gender,phone ��phone ����ʦ��
	//��Ҫ��¼��ʦ��QQ�ţ���Ŀ�����ʱ�׼

private:
	
	char QQ[20];
	vector <Purpose> table;//��Ŀ
	int salary;//���ʱ�׼

public:
	
	//���캯�� �� �����ʦֻ��һ�����캯����нˮΪ60
	//���� �Ա� phone QQ salary
	
>>>>>>> dev
	Teacher(char*, char, char*, char*, int salary=60);
	void setQQ(char*);
	void setSalary(int);
	void display();
};
#endif