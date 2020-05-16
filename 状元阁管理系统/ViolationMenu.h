
/********************************************************************
			�Ǽǽ�ʦ��ѧ�¹ʵĲ˵�
		Ҫ��¼˭�ǵ�ǰ������,��Handler��ߴ���
*********************************************************************/

#ifndef VIOLATIONMENU_H_
#define VIOLATIONMENU_H_
#include "Menu.h"
#include "ViolationRecord.h"
#include "stdafx.h"
#include "OperateTEA.h"
#include "RecordInfo.h"

class ViolationMenu:public Menu 

{
protected:

	Manager operatorManager;
	void display2();
	int getFirst();
	int getSecond(int );
	Date getOTD();
	Teacher checkThisTEA(string);
	bool saveThisRecord(ViolationRecord&);

public:
	
	ViolationMenu(Manager &);
	~ViolationMenu();
	ViolationMenu(const ViolationMenu&);
	void display();

};

#endif // !VIOLATIONMENU_H_



