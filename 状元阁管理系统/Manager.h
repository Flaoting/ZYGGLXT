#ifndef  MANAGER_H_
#define MANAGER_H_
#include "People.h"
#include "stdafx.h"
class Manager :public People

{

protected :

	char SSH[30];		//��Կ��һЩ������Ŀ�Ĺ�����Ҫ��Կ��֤���
						//��Ҫʹ��ʱת��string���бȽ�
public :


	Manager(char* name, char sex, char* phone, char*);
	Manager();
	~Manager();
	Manager(const Manager&);
	//����һ�¸�ֵ��
	
	Manager operator =(const Manager& obj);
	
	//���ĸ��˹�����Կ
	void display();

	bool setSSH();

	string getSSH();	//������Կ,ֻ��ͨ����ԪHandler����

	bool checkSSH(string ssh);

};

#endif // ! MANAGER_H_

