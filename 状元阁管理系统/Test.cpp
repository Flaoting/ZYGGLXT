#pragma warning(disable : 4996)
#include <iostream>
#include "Date.h"
#include "RelationMap.h"
#include "stdafx.h"
#include <time.h>
#include "Student.h"
#include <fstream>
#include "OperateTable.h"
#include "RegisterManagerMenu.h"
#include "FeasibleCmd.h"
#include "AddTABMenu.h"
#include "OperateSTD.h"
#include "ViolationMenu.h"
#include "ConClassPrice.h"
using namespace std;

int main() 

{
	/*RegisterManagerMenu RMM;
	RMM.display();
	Manager ma = RMM.getManager();
	ViolationMenu VM(ma);
	VM.display();*/
	OperateSTD OS;
	Student s;
	//OS.getInfoFromScreen();
	//OS.saveThisFile();
	OS.readPreFile("������");
	s = OS.getStudent();
	s.display();
	OS.updateStudentInfo(s.getName());
	s = OS.getStudent();
	s.display();
	return 0;
}
