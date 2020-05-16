#ifndef CONCLASSPRICE_H_
#define CONCLASSPRICE_H_
#include "ClassPrice.h"
#include "ConfigInfo.h"
#include "stdafx.h"
#include <fstream>
#include <map>
/****************************************************************
			�Կγ̵��۽���������޸ĵ���
		�����ǳ�ʼ����ʱ����е��ã��޸��Ƕ�ȡ�������޸�
		��һ����ȡ�������м���
*****************************************************************/


class ConClassPrice 
{
protected:

	ClassPrice classPrice;
	void getInfo(int type);

public:

	ConClassPrice();
	~ConClassPrice();
	ConClassPrice(const ConClassPrice&);
	bool initClassPrice();
	bool setClassPrice();
	map<int ,ClassPrice> getMapFromCon();//����һ���γ����͵����۵�map

};


#endif // !CONCLASSPRICE_H_


