#ifndef PEONUM_H_
#define PEONUM_H_

#include "BaseFile.h"

class PeoNum :public BaseFile 

{

protected:
	
	int NowNum;//��ǰ����

	bool setFile(int a=1);//���ô��ļ�
	
	bool getNum();//ȡ���ļ�����

	void setNowNum(int);//���µ�ǰ��NowNum

	void update(int);//������ID��

public:
	
	//PeoNum( string UA = "PersonInfo\\", string FA = "PeoNum.txt");

	PeoNum();
	~PeoNum();
	int returnNum();

};
#endif // !PEONUM_H_

