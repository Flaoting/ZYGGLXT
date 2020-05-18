#ifndef CLASSPRICE_H_
#define CLASSPRICE_H_
#include <string>
using namespace std;
/***************************************************************************
			����һ���򵥵�������
		�����¼�γ����͵����뵥�ۺͷ��ŵ���
		ע��ҲҪ��Ӧ�γ̵�����
****************************************************************************/
class ClassPrice 
{

private:

	int classTypeCode;				//�γ����͵Ĵ���
	int inPrice;					//��ѧ������ȡ
	int outPrice;					//���Ÿ���ʦ
	char Remarks[20];

public:
	
	ClassPrice(int classTC,int IP,int OP,string remark);
	~ClassPrice();
	
	void updateCP(int IP, int OP, string remark);				//��ȡ����������޸�
	void setClassPrice(int classTC, int IP, int OP, string remark);
	
	int getType();
	int getInPrice();
	int getOutPrice();

};
#endif