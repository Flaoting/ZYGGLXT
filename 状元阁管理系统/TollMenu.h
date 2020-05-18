#ifndef  TOLLMENU_H_
#define TOLLMENU_H_
#include "Menu.h"
#include "TransactionRecord.h"
#include "STDInfo.h"
#include "stdafx.h"
#include "OperateSTD.h"
#include "RecordInfo.h"
#include "OperateTable.h"
#include "ConClassPrice.h"

/******************************************************************
	˵���������÷�װ�Էǳ�ǿ��ֻ���ⲿ�ṩһ���ӿ�display
		  ���ҹ��캯������ȱʡ
	�����˵�

	ͨ��ѧ������������ѧ��������,�Ĵ���ѧ���Ķ�����
	��ȡ�����ߵĶ�����Ϣ
	��ȡ�����ķ���
	���� TransactionRecord ����,�������ļ���
	����޸�ʱ�� 2020/5/11
*******************************************************************/


class TollMenu :public Menu 

{
protected:


	Manager operatorManager;

	bool display2();  //������Ŀѯ��

	bool saveThisTranRecord(TransactionRecord );  
		//����������׼�¼��ֻ���ڲ�����
	
	Student checkSTDInfo(string STDname); 
		//ͨ��ѧ��������ѯѧ����Ϣ��������һ��ѧ�����󷵻ػ��� 
	int HowMuchToPay(Student &);

	int getClassTypeInPrice(int );

public:

	//���ɽ��ײ˵����봫�뵱ǰ�Ĳ�����
	//�����������������

	TollMenu(Manager &);
	TollMenu(const TollMenu&);
	~TollMenu();
	
	void display();
	

};
#endif // ! TOLLMENU_H_
