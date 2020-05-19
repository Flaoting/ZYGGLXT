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
	bool getStatus();

	void addSTD();
	void addTEA();
	void addTAB();
	void addToll();
	void setTable();
	void changeMAGSSH();
	void addVio();
	void addRun();

	void showOneRun(int ruler,int small );
	void showOneToll_S(int ruler, int small);
	void showOneVio(int ruler);
	void showOneToll(int ruler, int small);

	bool checkSSH();

	void showAllTEA();
	void shouwAllSTD();

	float checkSummery(int show);


};
#endif // !HANDLER_H_

