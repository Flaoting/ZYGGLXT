#ifndef AddSTDMenu_H_
#define AddSTDMenu_H_
#include "Menu.h"
#include <iostream>
#include "Student.h"
using namespace std;

class AddSTDMenu :public Menu 

{
protected:
	
	Student student;

	Purpose catchPurpose();//��ÿ�Ŀ

	void  catchAndAnylasis(int);//�ռ�������Ϣ,����һ��ѧ������¼�ڳ�Ա������

	bool display2();//�Ƿ�Ҫ�����Ҫ��

public :
	
	//�ṩ�����ⲿ�ӿ�
	//ѡ�����뷽ʽ���������ѧ���Ķ���
	
	AddSTDMenu(){}
	
	~AddSTDMenu() {}
	
	void display();//չʾǰ������Ϣ,�ڲ�������Ҫ����
	
	Student getStudent();

};
#endif // !AddSTDMenu_H_
