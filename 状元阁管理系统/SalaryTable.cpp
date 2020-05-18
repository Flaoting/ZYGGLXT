#include "SalaryTable.h"




SalaryTable::SalaryTable(Teacher& obj):teacher(obj)
{
	this->totalSalary = 0;
	caculateSalary();//����һ���ܹ���
}

SalaryTable::SalaryTable(const SalaryTable& obj) 
{
	this->teacher = obj.teacher;
	this->totalSalary = obj.totalSalary;
}

SalaryTable::~SalaryTable() 
{
	//�����������������
}

SalaryTable SalaryTable::operator =(const SalaryTable& obj) 
{

	this->teacher = obj.teacher;
	this->totalSalary = obj.totalSalary;
	return *this;
}

/*��ʼ��ʱ���������ܹ���*/
void SalaryTable::caculateSalary() 
{
	string name = this->teacher.getName();
	OperateTable OT;
	Table T;
	int i = 1;
	int summery = 0;

	if (!OT.readPreFile(name, i))
	{
		cout << "�����ܹ���ʱ�ļ���ȡʧ��" << endl;
		return ;
	}

	do
	{
		T = OT.getTable();
		int price = getClassTypeOutPrice(T.getClassType());
		int sum = T.getNum() * 2 * price;
		summery += sum;
		i++;
		OT.clearHidenTable();
	} while (OT.readPreFile(name, i));

	this->totalSalary=summery;

}

void SalaryTable::showAllTable()
{
//չʾ��λ��ʦ�����пα�
	cout << "��ʦ " << this->teacher.getName() << " ���ܹ���Ϊ"
		<< setw(8) << this->totalSalary << "   Ԫ " << endl;
	cout << "���潫չʾ�˴�λ��ʦ�����пγ̹���С��...." << endl;
	cout << endl;
	int total = 0;
	total= HowMuchInDisplay();
	cout << "�����ϸ����, ";
	cout << "��ʦ " << this->teacher.getName() << " ���ܹ���Ϊ"
		<< setw(8) << this->totalSalary << "   Ԫ " << endl;

}

void SalaryTable::briefShow() 
{
//���м�̵�չʾ
	int summery = 0;
	
	cout << "��ʦ " << this->teacher.getName() << " ���ܹ���Ϊ"
		<< setw(8) << this->totalSalary << "   Ԫ " << endl;
	summery = HowMuchInShort();
	
	cout << "�����ϸ����, ";
	cout << "��ʦ " << this->teacher.getName() << " ���ܹ���Ϊ"
		<< setw(8) << this->totalSalary << "   Ԫ " << endl;

}

int SalaryTable::getClassTypeOutPrice(int key)
{
	ConClassPrice CCP;
	map<int, ClassPrice> Price = CCP.getMapFromCon();

	auto it = Price.find(key);

	ClassPrice CP(-1, -1, -1, "test");

	if (it != Price.end())
	{
		CP = (*it).second;
		return CP.getOutPrice();
	}
	return -1;
}


int SalaryTable::HowMuchInDisplay()
{
	string name = this->teacher.getName();
	OperateTable OT;
	Table T;
	int i = 1;
	int summery = 0;

	if (!OT.readPreFile(name, i))
	{
		cout << "�����ܹ���ʱ�ļ���ȡʧ��" << endl;
		return 0;
	}

	do
	{
		T = OT.getTable();
		T.shortShowTEA();		//���������bug
		cout << endl;
		int price = getClassTypeOutPrice(T.getClassType());
		int sum = T.getNum() * 2 * price;
		
		cout << "�γ̵��� " << setw(5) << price << setw(5) << "Ԫ/��/Сʱ" << endl;
		cout << "�˽ڿ�С�� " << setw(5) << sum << setw(5) << " Ԫ " << endl;
		
		summery += sum;
		i++;
		
		OT.clearHidenTable();
		system("pause");
	} while (OT.readPreFile(name, i));

	return summery;

}

int SalaryTable::HowMuchInShort()
{
	string name = this->teacher.getName();
	OperateTable OT;
	Table T;
	int i = 1;
	int summery = 0;

	if (!OT.readPreFile(name, i))
	{
		cout << "�����ܹ���ʱ�ļ���ȡʧ��" << endl;
		return 0;
	}

	do
	{
		
		T = OT.getTable();
		T.shortShortShowTEA();	//���������bug
		cout << endl;
		int price = getClassTypeOutPrice(T.getClassType());
		int sum = T.getNum() * 2 * price;
	
		cout << "�˽ڿ�С�� " << setw(5) << sum << setw(5) << " Ԫ " << endl;
		summery += sum;
		
		i++;
		
		OT.clearHidenTable();
		system("pause");
	
	} while (OT.readPreFile(name, i));

	return summery;
}


