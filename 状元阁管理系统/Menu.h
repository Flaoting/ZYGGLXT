#ifndef MENU_H_
#define MENU_H_
#include <iostream>
using namespace std;
class Menu 

//����һ���˵��ĳ�����

{
public:
	Menu() {};
	virtual void display()=0;
	virtual ~Menu() { cout << "������Menu����������" << endl; }
};

#endif 
