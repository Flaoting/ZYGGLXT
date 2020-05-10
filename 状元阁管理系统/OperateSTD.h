#ifndef OPERATESTD_H_
#define OPERATESTD_H_

#include "OperateMode.h"
#include "PeoNum.h"
#include "STDInfo.h"
#include "Student.h"


class OperateSTD :public OperateMode 

	//�տ�ʼ����Ѳ�ѯģ�������ģ��ֿ���
	// ���ھ���������һ��ͦ�õ�
	//Ϊ�˱������ظ����֣������Ͳ�����

{
private:

	void setStdsID( Student &);			//���ú�����������Student����Ԫ����
								//�޸��Լ����ݵ�ID���������ݱ���
protected:
	
	Student student;//ѧ������
	STDInfo saveAddress;//�ļ���ַ����
	
public:
	
	OperateSTD();
	~OperateSTD();

	void getInfoFromScreen();//�ѱ����������STD ������Ϣ

	bool saveThisFile();//�����ļ�

	bool readPreFile( );//���ļ��ж�ȡ�ļ���Ϣ
		
	Student getStudent();
	
};
#endif // !OperateSTD_H_
