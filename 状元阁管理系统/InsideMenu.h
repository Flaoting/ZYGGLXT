#ifndef  INSIDEMENU_H_
#define INSIDEMENU_H_
#include "Menu.h"
/**********************************************************************************************
		�����ڲ����ܲ˵��������ڲ����������ѡ��
***********************************************************************************************/
class InsideMenu :public Menu 


{
public:
	InsideMenu();
	~InsideMenu();
	void display();
	int getCommend();
};

#endif // ! INSIDEMENU_H_
