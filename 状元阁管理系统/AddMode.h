#ifndef ADDMODE_H_
#define ADDMODE_H_
#include "BaseFile.h"
class AddMode 

	//����Mode ��������
	//�տ�ʼ����Ѳ�ѯģ�������ģ��ֿ���
	// ���ھ���������һ��ͦ�õ�
	//Ϊ�˱������ظ����֣������Ͳ�����

{
private:
	
	//BaseFile *Bf;
	
	//�����ļ���ָ�룬����ָ������������
	//ָ��ǰ�����ļ��Ļ������ļ�

public:
	
	AddMode();
	virtual ~AddMode();
	
	virtual void readPreFile();//��ȡǰ���ļ�
	virtual bool saveThisFile();//���浱ǰ�ļ�

};
#endif // !ADDMODE_H_

