#ifndef CONFIGINFO_H_
#define CONFIGINFO_H_
#include "STDInfo.h"
/***************************************************************
		�����ļ��Ĵ���λ��
	��Ҫ�������ļ������¼���
	ClassPrice
****************************************************************/

class ConfigInfo : public STDInfo

{

public:
	ConfigInfo(string Name);

	ConfigInfo();

	virtual ~ConfigInfo();

	ConfigInfo operator = (const ConfigInfo&);


};
#endif
