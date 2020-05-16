#include "ConClassPrice.h"
#include <iostream>
#include <fstream>
using namespace std;

ConClassPrice::ConClassPrice() :classPrice(1, 100, 60, "test")
{
	//���캯�����������
}

ConClassPrice::~ConClassPrice() 
{
	//�����������������
}

ConClassPrice::ConClassPrice(const ConClassPrice& obj):classPrice(obj.classPrice)
{
	//�������캯��	
}

void ConClassPrice::getInfo(int type) 
{
	int inPrice, outPrice;
	string remark;

	cout << "��������� " << type << " ��γ̵���Ϣ" << endl;
	cout << "�γ�������" << translateNumToClassType(type) << endl;
	cout << "�������շѱ�׼ :  ";
	cin >> inPrice;	
	cout << "�����빤�ʱ�׼ :  ";
	cin >> outPrice;
	cout << "�����뱸ע(û������) :  ";
	cin >> remark;
	this->classPrice.setClassPrice(type, inPrice, outPrice, remark);
	cout << endl;
}

bool ConClassPrice::initClassPrice() 
{

	ConfigInfo CF("ClassPrice");//�����ļ�����·��
	
	ofstream file;

	file.open(CF.getCompleteAddress(), ios::out | ios::binary);//�Ѿ�������ˢ���ļ�
	
	if (!file)
	{
		cout << "ClassPrice�ļ�����ʧ�ܣ�����·���Ƿ����" << endl;
		cout << "��ǰ·�� :  " << CF.getCompleteAddress();
	}
	
	system("CLS");
	
	cout << "************************************************************" << endl<<endl;
	cout << "������ʾ  �������пγ���֧�ĳ�ʼ��������׼���õ���" << endl;
	cout << "������ʾ  ��ע����Χ�����Ƿ�����Ұ�ȫ ��" << endl;

	if (!checkToContinue()) 
	{
		operationCancled();
		return false;
	}
	
	for (int i = 1; i <= 6; i++)
	{
		getInfo(i);
		file.write((char*)&this->classPrice, sizeof(this->classPrice));
	}
	
	file.close();
	
	cout << "Success �γ̷��ñ�׼�����ɹ�" << endl;
	return true;
}

bool ConClassPrice::setClassPrice() 
{
	ConfigInfo CF("ClassPrice");//�����ļ�����·��
	fstream file;
	
	file.open(CF.getCompleteAddress(),ios::out| ios::in | ios::binary);//�Ѿ�������ˢ���ļ�
	
	if (!file)
	{
		cout << "ClassPrice�ļ���ʧ�ܣ�����·���Ƿ����" << endl;
		cout << "��ǰ·�� :  " << CF.getCompleteAddress();
	}

	string type;

	for (int i = 1; i <= 6; i++)
	{
		type = translateNumToClassType(i);
		cout <<i<<". "<< type << endl;
	}
	
	cout << "��ѡ��Ҫ�޸Ŀγ����͵ı�� :  ";
	int j=0;
	
	while (j <= 0 || j > 6) 
	{
		cin >> j;
	}
	
	file.read((char*)&this->classPrice, sizeof(this->classPrice));
	
	while (j != this->classPrice.getType()&&!file.eof())
	{
		file.read((char*)&this->classPrice, sizeof(this->classPrice));

	}
	
	if (j != this->classPrice.getType()) 
	{
		cout << "���ź�  δ���ҵ���Ӧ�γ����͵�Price��Ϣ " << endl;
		file.close();
		return false;
	}
	
	else if (j == this->classPrice.getType()) 
	{
		getInfo(j);
	
		short t=(j-1)*sizeof(this->classPrice);
		
		file.seekp( t , ios::beg);
		file.write((char*)&this->classPrice, sizeof(this->classPrice));
		
		file.flush();
	}
	
	file.close();
	
	cout << "Success �γ̷��ñ�׼�޸ĳɹ�" << endl;
	return true;
}

map<int, ClassPrice> ConClassPrice::getMapFromCon() 

{

	ConfigInfo CF("ClassPrice");//�����ļ�����·��
	ifstream file;

	file.open(CF.getCompleteAddress(), ios::in | ios::binary);

	if (!file)
	{
		cout << "ClassPrice�ļ���ʧ�ܣ�����·���Ƿ����" << endl;
		cout << "��ǰ·�� :  " << CF.getCompleteAddress();
	}

	map<int, ClassPrice> MAP;    //���ɿγ̴����뵥�۵�map

	for (int i = 1; i <= 6; i++) 
	{
		file.read((char*)&this->classPrice, sizeof(this->classPrice));
		MAP.insert(pair<int, ClassPrice>(i, this->classPrice));
	}

	return MAP;

}

