#ifndef MAINMENU_H_
#define MAINMENU_H_
#include "Menu.h"

class MainMenu :public Menu

	//�������˵��࣬�ǽ���Ĺ���ѡ��

{

public:

	MainMenu();
	void display();
	~MainMenu() {  };
	int getCommend();


};

#endif // !MAINMENU_H_

