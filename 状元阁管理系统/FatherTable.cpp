#include "FatherTable.h"
#include <string>

using namespace std;


FatherTable::FatherTable(People* peo) 

{

	strcpy_s(this->name, peo->getName());
	this->ID = peo->getID();
	selfName = "FatherTable";

}

FatherTable::FatherTable() 

{
	
	char name[20] = "ʵ��Ļ�����";
	People pe(name);
	strcpy_s(this->name, pe.getName());

	selfName = "FatherTable";

}
void FatherTable::display() 
{
	cout << this->name << "��"<<this->getSelfName()<<endl;
}

string FatherTable::getSelfName()

//ע������һ���麯����������÷��������selfName
{	

	return selfName;
}
