#ifndef  TOLLMENU_H_
#define TOLLMENU_H_
#include "Menu.h"
#include "TransactionRecord.h"
#include "STDInfo.h"

/******************************************************************
	�����˵�

	ͨ��ѧ������������ѧ��������,�Ĵ���ѧ���Ķ�����
	��ȡ�����ߵĶ�����Ϣ
	��ȡ�����ķ���
	���� TransactionRecord ����

*******************************************************************/


class TollMenu :public Menu 

{
protected:

	//����һ�����׼�¼����

	void catchAndAnylasis();

public:

	TollMenu();
	
	~TollMenu();
	
	void display();


	//����һ����¼
	TransactionRecord getTransactionRecord();

};


#endif // ! TOLLMENU_H_
