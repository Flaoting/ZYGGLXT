#ifndef  LOGINMENU_H_
#define LOGINMENU_H_
#include "Menu.h"
#include <string>
using namespace std;
class LoginMenu:public Menu 
{

protected:

	bool checkBigPassword(string s);

	bool checkPassword(string input);
	
	bool saveAccount(string name, string password);

	string login_one();//������Կ

	void register_one();//���Bigboss��Ȩ��

	void register_two();//����ע��

public :

	void display();

};

#endif // ! LOGIN_H_
