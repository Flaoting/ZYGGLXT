#ifndef RUNNINGMENU_H_
#define RUNNINGMENU_H_
#include "stdafx.h"
#include "Menu.h"
#include "Manager.h"
#include "RunningRecord.h"
#include "RecordInfo.h"

/****************************************************
		��ˮ�˲˵���
	���ռ���Ϣ������һ�� RunningRecord ,��������RunningRecord�ļ���
	���class��װ�Էǳ��ߣ����ⲿֻ�ṩΨһ�ӿ� display
	û���޲ι��죬���봫�����Manager

	����޸�ʱ�� 2020/5/11
******************************************************/


class RunningMenu : public Menu
{
protected:

	Manager operatorManager;
	bool display2();

	bool saveRunRecord(RunningRecord );

public:
	
	RunningMenu(Manager&);
	~RunningMenu();
	RunningMenu(const RunningMenu&);

	RunningMenu operator= (const RunningMenu&);
	virtual void display();

};

#endif // !RUNNINGMENU_H_


