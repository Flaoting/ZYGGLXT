#ifndef OPERATEMODE_H_
#define OPERATEMODE_H_
#include "BaseFile.h"



class OperateMode 

	//OperateMode ��������
	//�տ�ʼ����Ѳ�ѯģ�������ģ��ֿ���
	// ���ھ���������һ��ͦ��
{

public:
	
	virtual bool readPreFile() = 0;//��ȡǰ���ļ�
	virtual bool saveThisFile() = 0;//���浱ǰ�ļ�
	
	OperateMode(){}
	virtual ~OperateMode(){}
	
};
#endif // !OperateMode_H_


