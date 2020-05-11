#ifndef RUNNINGMENU_H_
#define RUNNINGMENU_H_
#include "stdafx.h"
#include "Menu.h"
#include "Manager.h"

class RunningMenu : public Menu
/****************************************************
		��ˮ�˲˵���
	���ռ���Ϣ������һ�� RunningRecord ,���������ʼ���				
	����޸�ʱ�� 2020/5/11
******************************************************/
{
protected:

	Manager operatorManager;
	bool display2();

public:
	
	RunningMenu(Manager&);
	~RunningMenu();
	RunningMenu(const RunningMenu&);

	RunningMenu operator= (const RunningMenu&);
	virtual void display();

};

#endif // !RUNNINGMENU_H_







