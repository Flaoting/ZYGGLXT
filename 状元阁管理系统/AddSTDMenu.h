#ifndef ADDSTDMENU_H_
#define ADDSTDMENU_H_
#include "Menu.h"
#include <iostream>
#include "Student.h"
using namespace std;

class AddSTDMenu :public Menu 

{
protected:
	
	Student student;

	bool display2();//�Ƿ�Ҫ�����Ҫ��
	Purpose catchPurpose();//��ÿ�Ŀ

	void  catchAndAnylasis(int);//�ռ�������Ϣ,����һ��ѧ������¼�ڳ�Ա������

public :
	
	//�ṩ�����ⲿ�ӿ�
	//ѡ�����뷽ʽ���������ѧ���Ķ���
	
	AddSTDMenu(){}
	~AddSTDMenu() {}
	
	void display();//չʾǰ������Ϣ,�ڲ�������Ҫ����
	
	Student getStudent();
};
#endif // !ADDSTDMENU_H_
