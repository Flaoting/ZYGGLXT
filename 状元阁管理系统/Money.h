#ifndef  MONEY_H_
#define MONEY_H_
#include <string>
using namespace std;
class Money

	//�����࣬��ֱ����int����ҪΪ�˱������Ķ�ȡ
	//Ҳ�������������������˵����׵���
{
protected:

	int sum;//�����ϵͳ��ֻ��Ҫ���ͼ���
	string currencyUnit;//���ҵ�λ

public:
	Money();
	~Money();
	Money(int a, string CU = "RMB");
	Money(const Money& obj);
	void setNum(int );
	int getNum();
	void setUnit(string);
	string getUnit();
	void display();
};
#endif // ! MONEY_H_
