#ifndef  ADDTEAMENU_H_
#define ADDTEAMENU_H_
#include "Menu.h"
#include "AddSTDMenu.h"
#include "Teacher.h"


class AddTEAMenu : public Menu 

	//���ӽ�ʦ�˵��࣬�����ʦ��Ϣ
	
{
protected:

	Teacher teacher;

	void catchAndAnylasis();
	bool display2();
	Purpose catchPurpose();

public:
	
	AddTEAMenu();
	~AddTEAMenu();

	AddTEAMenu(const AddTEAMenu&);

	void display();//����Menu���display
	
	Teacher getTeacher();

};

#endif // ! ADDTEAMENU_H_

