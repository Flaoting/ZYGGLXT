#ifndef OPERATESTD_H_
#define OPERATESTD_H_

#include "OperateMode.h"
#include "STDInfo.h"
#include "Student.h"


class OperateSTD :public OperateMode

	//�տ�ʼ����Ѳ�ѯģ�������ģ��ֿ���
	// ���ھ���������һ��ͦ�õ�
	//Ϊ�˱������ظ����֣������Ͳ�����

{
private:

	//���ú�����������Student����Ԫ����
	//�޸��Լ����ݵ�ID���������ݱ���
	void setStdsID(People&);
			
protected:
	

	Student stud;//ѧ������
	STDInfo saveAddress;//�ļ���ַ����

public:

	OperateSTD( );
	~OperateSTD( );

	void getInfoFromScreen( );//�ѱ����������STD ������Ϣ

	bool saveThisFile( );//�����ļ�

	bool readPreFile( );//�޲� ���ļ��ж�ȡ�ļ���Ϣ
	
	bool readPreFile( string );//����ѧ������������ȡѧ����Ϣ
	
	Student getStudent();

};
#endif // !OperateSTD_H_
