#include "AddSTD.h"
#include "Student.h"
#include "STDInfo.h"
#include "AddSTDMenu.h"
AddSTD::AddSTD() {}

AddSTD::~AddSTD(){}

void AddSTD::getInfo() 

//�ѱ����������STD ������Ϣ

{
	AddSTDMenu  ASM;
	ASM.display();
	student =  ASM.getStudent();
	string name(student.getName());

	STDInfo SI(name);
	saveAddress = SI;
}
//�������û�����
bool saveThisFile() 
{

}