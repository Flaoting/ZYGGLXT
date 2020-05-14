#pragma warning(disable : 4996)
#include <iostream>
#include "Date.h"
#include "RelationMap.h"
#include "stdafx.h"
#include <time.h>
#include "Student.h"
#include <fstream>
#include "OperateTable.h"
#include "FeasibleCmd.h"
using namespace std;

int main() 

{
	FeasibleCmd FC;

	char name[20] = "������";
	char phone[30] = "15832513211";
	char ssh[20] = "123456";
	Purpose P;
	Student ma(name, P);
	char na[15] = "�˼ѻ�";
	Date d1(2020, 1, 5), d2(2020, 1, 15);
	Table T1(&ma, d1, d2, 3, na, 1), T2, T3;
	OperateTable OT1(T1), OT2, OT3;
	
	OT1.saveThisFile();

	OT2.readPreFile("������");
	OT2.transformSTToCSV();

	OT3.readPreFile("�˼ѻ�");
	OT3.transformTTToCSV();
	
	return 0;
}

	