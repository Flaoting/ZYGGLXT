#ifndef RECORDINFO_H_
#define RECORDINFO_H_
#include "STDInfo.h"
class RecordInfo : public  STDInfo
/*************************************************************
	
	�������ļ��Ĵ����ַ����Ϊ�漰�����ף�������Ϣ�Ƚ���Ҫ
	ʵ�ִ��������Ĺ���
	����޸�ʱ�� 2020/5/11
**************************************************************/

{
public :

	RecordInfo(string Name);

	RecordInfo();

	virtual ~RecordInfo();

	RecordInfo operator = (const RecordInfo&);

};


#endif // !RECORDINFO_H_

