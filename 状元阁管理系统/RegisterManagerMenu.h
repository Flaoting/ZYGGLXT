/**********************************************************************
			RegisterManager ��
		ע�����Ա���࣬��ͬ����������ӻ��߲����˵�
		���������Ҫͨ���ڲ��������룬���Boss��Ȩ����ע��
		���manager��Ϣ�ǳ���Ҫ�����Ժ�����Ȩ�ޣ���ӿγ̵�Ȩ�޵ı�Ҫƾ֤


***********************************************************************/
#ifndef REGISTERMANAGERMENU_H_
#define REGISTERMANAGERMENU_H_
#include "Menu.h"
#include "Manager.h"
#include "PerInfo.h"
#include "stdafx.h"
class RegisterManagerMenu:public Menu 
{
protected:
	
	Manager Man;
	bool checkQuality();
	string getSSHFromScreen();
	bool saveThisMan(string name);

public:
	
	RegisterManagerMenu();
	~RegisterManagerMenu();
	virtual void display();  //�����Ա������

	Manager getManager();

};


#endif // !REGISTERMANAGER_H_

