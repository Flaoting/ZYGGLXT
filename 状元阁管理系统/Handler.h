#ifndef HANDLER_H_
#define HANDLER_H_
#include <iostream>
#include "Manager.h"
#include "PerInfo.h"
#include "OperateSTD.h"
#include "OperateTEA.h"
#include "OperateTable.h"
#include "TollMenu.h"
#include "ViolationMenu.h"
#include "RunningMenu.h"
#include "QueryRecord.h"
using namespace std;
class Handler 

	//����̨�࣬����Ȩ���ͷ�

{
private :
	
	Manager operatorManager;
	bool LOGIN;

public:
	
	Handler();
	~Handler();

	bool LoginManager(string name,string SSH );			//������������Կ���е�¼
	bool getStatus();									//��õ�¼״̬

	void addSTD();										//����ѧ������ʦ���α�
	void addTEA();											
	void addTAB();
	void addToll();										//���ӽ��׼�¼����ˮ��Υ���¼
	void addVio();
	void addRun();
	void setTable();									//�޸Ŀα�
	void changeMAGSSH();								//�޸ĵ�ǰ����Ա����Կ

	void showOneRun(int ruler,int small );				//��������λ�ò���չʾ���ּ�¼
	void showOneToll_S(int ruler, int small);
	void showOneVio(int ruler);
	void showOneToll(int ruler, int small);

	void showAllRun(int  );								//չʾ���е����ּ�¼
	void showAllVio(  );
	void showAllToll( int );
	
	bool checkSSH();									//ĳЩ������������֤

	void showAllTEA();									//չʾ�ܱ��еĽ�ʦ��ѧ����Ϣ
	void shouwAllSTD();								

	float checkSummery(int show);						//һ������


};
#endif // !HANDLER_H_

