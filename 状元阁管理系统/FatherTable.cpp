#include "FatherTable.h"
#include <string>

using namespace std;


FatherTable::FatherTable(People* peo) 

{

	strcpy_s(this->ownerName, peo->getName());
	
	this->ownerID = peo->getID();

	string ss(peo->getName());
	selfName = ss+"��FatherTable";

}

FatherTable::FatherTable() 

{
	
	char name[20] = "ʵ��Ļ�����";
	People pe(name);
	strcpy_s(this->ownerName, pe.getName());
	string ss = "�����˵�";
	selfName = ss+"FatherTable";

}
void FatherTable::display() 
{
	cout << selfName<<endl;
}

string FatherTable::getSelfName()

//ע������һ���麯����������÷��������selfName
{	

	return selfName;
}
string FatherTable::getOwnerName()
{
	string name(this->ownerName);
	return name;
}

int FatherTable::getOwnerID() 
{
	return this->ownerID;
}