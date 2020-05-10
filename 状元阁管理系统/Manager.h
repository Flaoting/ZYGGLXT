#ifndef  MANAGER_H_
#define MANAGER_H_
#include "People.h"

class Manager :public People

{

protected :

	char SSH[30];		//密钥，一些关于账目的管理需要密钥验证身份
						//需要使用时转成string进行比较
public :

	Manager(char* name, char sex, char* phone, char*);
	Manager();
	~Manager();
	Manager(const Manager&);
	//重载一下赋值号
	
	Manager operator =(const Manager& obj);
	
	//更改个人管理密钥

	bool setSSH();
	void display();
};

#endif // ! MANAGER_H_

