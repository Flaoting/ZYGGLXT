#ifndef ADDSTD_H_
#define ADDSTD_H_
#include "AddMode.h"
#include "Student.h"
#include "PeoNum.h"
#include "STDInfo.h"

class AddSTD :public AddMode 

	//�տ�ʼ����Ѳ�ѯģ�������ģ��ֿ���
	// ���ھ���������һ��ͦ�õ�
	//Ϊ�˱������ظ����֣������Ͳ�����

{
private:
	//void setStdsID(); //���ú�����������student����Ԫ����
protected:
	
	Student student;//ѧ������
	STDInfo saveAddress;//�ļ���ַ����
	
public:
	
	AddSTD();
	~AddSTD();

	void getInfo();//�ѱ����������STD ������Ϣ

	bool saveThisFile();//�����ļ�

	bool readInfo(string);

	void diaplay();
};
#endif // !ADDSTD_H_
