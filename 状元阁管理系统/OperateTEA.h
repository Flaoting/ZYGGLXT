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
	
	void getChangeInfo();
	bool catchElection();
	bool doChangeInfo(int election);
	Purpose catchPurpose();

public:

	OperateTEA();
	
	~OperateTEA();

	OperateTEA(const OperateTEA&);

	void getInfoFromScreen();//�ѱ����������TEA ������Ϣ

	bool saveThisFile();//�����ļ�

	bool readPreFile();//��˽���ļ��ж�ȡ�ļ���Ϣ

	bool readPreFile(string name);

	bool readPreFile(int oridinal);//�ӽ�ʦ�ܱ��л�ȡ�ڼ�����ʦ����Ϣ
	
	Teacher getTeacher();

	bool updateTeacherInfo(string STDname);


};
#endif // ! OPERATETEA_H_



