/************************************************************************
                
				AddTABMenu  
		��Ҫ�����Ǵ���Ļ�˴���һ���α�
		�߶ȷ�װ�����ⲿֻ�ṩdisplay �ӿںͷ���Table�Ľӿ�
		��Ҫ��OperateTableģ����е���
		��һ��Ҫע�������ɵ�Table�����Ƚ�������Ļ��ʾ�ٽ��б���
		��Ȼ���ô��������ķ�������


		����޸�ʱ�� 2020/5/15  ����  Flaoting

**************************************************************************/


#ifndef ADDTABMENU_H_
#define ADDTABMENU_H_
#include "Menu.h"
#include "Table.h"
#include "OperateSTD.h"
#include "stdafx.h"
class AddTABMenu :public Menu 
{

protected:

	Table table ;
	
	Date getDateFromScreen();
	int display2();
		
	Student checkThisStudent(string name);

public:

	AddTABMenu();
	~AddTABMenu();
	AddTABMenu(const AddTABMenu&);

	void display();

	Table getTable();

};

#endif

