#ifndef BASEFILE_H_
#define BASEFILE_H_
#include <string>
#include <fstream>
using namespace std;

class BaseFile 

	//���������ļ��࣬�������ļ���Ļ���
	//�ļ�����·��= saveAddress+uniqueAddress+fileName
	//�����ļ��У������ļ���������з���

{

private:

	static string REGISTERADDRESS;//����ľ���·����ֻ������ڲ����б���
	static void RESETADDRESS(string);//�޸ľ���·��

protected :
	
	const string saveAddress;//����λ��,����·������λ���ļ���,һ�㲻�����޸�
	string uniqueAddress;//�����ļ���
	string fileName;//�ļ�������
	string completeFile;//��ǰ�������ϵ�һ������Ϊ�˷������

public :
	
	BaseFile();

	BaseFile(string UA, string FA);	//��һ�������ǹ�������uniqueAddress���ڶ����������ļ�����filename

	BaseFile(const BaseFile&);
	
	BaseFile operator=(const BaseFile&);

	string getCompleteAddress();

	string getSaveAddress();

	string getfileName();

	void setFileName(string FA);//������filename

	void changeSaveAddress();//�ı䴢���λ�ã���Ҫ��֤����

	void display();

	virtual ~BaseFile(){}

	//virtual bool saveThisFile();
};

#endif // !BASEFILE_H_

