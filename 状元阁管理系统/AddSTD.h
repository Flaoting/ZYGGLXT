#ifndef ADDSTD_H_
#define ADDSTD_H_
#include "AddMode.h"
#include "Student.h"
#include "PeoNum.h"
#include "STDInfo.h"
class AddSTD :public AddMode 

{

protected:
	
	Student student;
	STDInfo saveAddress;

public:
	
	AddSTD();
	~AddSTD();

	void getInfo();//�ѱ����������STD ������Ϣ

	bool saveThisFile();//�����ļ�

};
#endif // !ADDSTD_H_
