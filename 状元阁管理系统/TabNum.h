#ifndef TABNUM_H_
#define TABNUM_H_
#include "BaseFile.h"

class TabNum :private BaseFile

{

protected:

	int NowNum;//��ǰ����

	bool setFile(int a = 1);//���ô��ļ�

	bool getNum();//ȡ���ļ�����

	void setNowNum(int);//���µ�ǰ��NowNum

	void update(int);//������ID��

public:

	//TabNum( string UA = "PersonInfo\\", string FA = "TabNum.txt");

	TabNum();
	~TabNum();
	int returnNum();

};

#endif