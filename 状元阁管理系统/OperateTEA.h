#ifndef  OPERATETEA_H_
#define OPERATETEA_H_

#include "AddTEAMenu.h"
#include "TEAInfo.h"
#include "OperateMode.h"

class OperateTEA : public OperateMode 
{

private :
	//�޸�ID
	void setTeasID(People&);

protected:
	
	Teacher teacher;
	TEAInfo saveAddress;

public:

	OperateTEA();
	
	~OperateTEA();

	OperateTEA(const OperateTEA&);

	void getInfoFromScreen();//�ѱ����������TEA ������Ϣ

	bool saveThisFile();//�����ļ�

	bool readPreFile();//���ļ��ж�ȡ�ļ���Ϣ

	bool readPreFile(string name);

	Teacher getTeacher();

};
#endif // ! OPERATETEA_H_
