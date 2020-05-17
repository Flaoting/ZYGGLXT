#ifndef TEACHER_H_ 
#define TEACHER_H_
#include "Purpose.h"
#include "Table.h"
#include <vector>

class Teacher :public People {
	
	//��ʦ�࣬��People ��������,
	//�Ѿ��еĵĳ�Ա�У�name,ID,gender,phone ��phone ����ʦ��
	//��Ҫ��¼��ʦ��QQ�ţ���Ŀ�����ʱ�׼

private:
	
	char QQ[20];
	Purpose sub;//��Ŀ
	int salary;//���ʱ�׼

public:
	
	//���캯�� �� �����ʦֻ��һ�����캯����нˮΪ60
	//���� �Ա� phone QQ salary
	
	Teacher(char* name, char sex, char* phone, char* QQ, Purpose subj, int salary=60);
	Teacher(const Teacher& obj);
	Teacher();

	~Teacher();

	void setQQ(char*);
	
	void setSalary(int);
	
	void display();

	Teacher operator=(const Teacher& obj);

	friend class OperateTEA;


};
#endif

