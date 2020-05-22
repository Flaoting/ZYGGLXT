#ifndef  LOGINMENU_H_
#define LOGINMENU_H_
#include "Menu.h"
#include <string>
using namespace std;
class LoginMenu:public Menu 
{

protected:

	bool checkBigPassword(string s);				//��⾭Ӫ��������

	bool checkPassword(string input);				//�����˵�¼����
	
	bool saveAccount(string name, string password); //���浱ǰע���˻�

	string login_one();								//������Կ

	void register_one();							//����ע��ĵ�һ����

	void register_two();							//����ע��ĵڶ�����

public :

	void display();									//�ⲿչʾ�Խӿ�
	bool checkInDisplay();							//��ߵ�¼Ȩ���Խӿ�
};

#endif // ! LOGIN_H_
