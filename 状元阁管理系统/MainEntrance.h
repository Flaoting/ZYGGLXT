/**************************************************************
				MainEntrance
		������� ��Main �����е��� 
		������û�����ݳ�Ա 
***************************************************************/
#ifndef  MAINENTRANCE_H_
#define  MAINENTRANCE_H_
#include "stdafx.h"
#include "PremaryMenu.h"
#include "LoginMenu.h"
#include "FeasibleCmd.h"
#include "MainMenu.h"
#include "Handler.h"
#include "OperateTable.h"
#include "InsideMenu.h"
#include "RegisterManagerMenu.h"
#include "SalaryTable.h"


class MainEntrance 
{

private:
	int commender;//�������Ĵ���
	Handler Hander;

public :
	
	MainEntrance();
	~MainEntrance();
	

	void ShowThe_First();				//չʾ�ȵ�����
	void ShowPre_Login();				//��¼����
	int  ShowMain_Menu();				//���˵�
	bool DealFirt_Comd(int Comd);		//�������˵�������
	int  ShowInde_Menu();				//��ʾ�ڲ��˵�
	bool DealSecn_Comd(int Comd);		//�����ڲ��˵�������
	int  ShowMang_Menu();				//����Ա���й��ܣ�����һ�廯

};

#endif // ! MAINENTRANCE_H_
