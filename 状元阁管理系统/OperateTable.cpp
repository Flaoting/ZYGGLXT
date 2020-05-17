#include "OperateTable.h"
#include "Table.h"
#include "StoreTable.h"
#include <fstream>

using namespace std;



OperateTable::~OperateTable()
{
	//�����������������
}



OperateTable::OperateTable() :table(),saveAddress()

{
	//�޲ι��죬�������
}

OperateTable::OperateTable ( Table &tab ) : table( tab )

{
	//��������ߵ��������Դ����ַ���г�ʼ����

	string str=tab.getOwnerName();
	

	this->saveAddress.setName(str);

}



Table OperateTable::getTable()
{
	return this->table;
}



bool OperateTable::saveThisFile() 

{
	Table objTab(this->table);

	fstream file;
	StoreTable ST1,ST2;

	ST1.buildStoreTable(this->table);

	try {
		file.open(saveAddress.getCompleteAddress(), ios::out | ios::binary|ios::app);
		if (!file)
		{
			//���ļ�ʧ�ܣ��׳��쳣

			throw 978;
		}
		file.write((char*)&ST1, sizeof(ST1));
		file.flush();
	}
	catch (int goal) 
	{
		cout << "������룺 " << goal<<"  ";
		cout << "ѧ���α��ļ�����ʧ�ܣ�����·���Ƿ�Ƿ���" << endl;
		cout << "��ǰ·��:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}
	
	file.close();

	objTab.ReviseTeam();

	ST2.setOtherName(objTab.getOwnerName());

	ST2.buildStoreTable(objTab);
	
	string str = objTab.getOwnerName();
	
	this->saveAddress.setName(str);
	this->saveAddress.GiveTeacherALife();

	try {
		file.open(saveAddress.getCompleteAddress(), ios::out | ios::binary);
		if (!file)
		{
			//���ļ�ʧ�ܣ��׳��쳣

			throw 978;
		}
		file.write((char*)&ST2, sizeof(ST2));
		file.flush();
	}
	catch (int goal)
	{
		cout << "������룺 " << goal << "  ";
		cout << "��ʦ�α��ļ�����ʧ�ܣ�����·���Ƿ�Ƿ���" << endl;
		cout << "��ǰ·��:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}
	file.close();

	return 1;

}

bool OperateTable::saveThisFile(int ruler) //����������ǽ�ʦ�Ŀα���ʦ������ǰ

{
	Table objTab(this->table);

	fstream file;

	StoreTable ST1, ST2;

	ST1.buildStoreTable(this->table);

	try {
		file.open(saveAddress.getCompleteAddress(), ios::out | ios::binary | ios::in);
		if (!file)
		{
			//���ļ�ʧ�ܣ��׳��쳣

			throw 978;
		}
		short t = (ruler - 1) * sizeof(ST1);
		file.seekp(t, ios::beg);
		file.write((char*)&ST1, sizeof(ST1));
		file.flush();
	}
	catch (int goal)
	{
		cout << "������룺 " << goal << "  ";
		cout << "��ʦ�α��ļ����ʧ�ܣ�����·���Ƿ�Ƿ���" << endl;
		cout << "��ǰ·��:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}

	file.close();

	int howLong;
	howLong = checkHowLongBelonging(objTab);		//��������ǽ�ʦ�α�
	short tt = (howLong - 1) * sizeof(ST1);			

	objTab.ReviseTeam();

	ST2.setOtherName(objTab.getOwnerName());

	ST2.buildStoreTable(objTab);

	string str = objTab.getOwnerName();

	this->saveAddress.setName(str);
	
	this->saveAddress.GiveTeacherALife();

	try {
		file.open(saveAddress.getCompleteAddress(), ios::out | ios::binary|ios::in);
		
		if (!file)
		{
			//���ļ�ʧ�ܣ��׳��쳣

			throw 978;
		}
		file.seekp(tt, ios::beg);
		file.write((char*)&ST2, sizeof(ST2));
		file.flush();

	}
	catch (int goal)
	{
		cout << "������룺 " << goal << "  ";
		cout << "��ʦ�α��ļ�����ʧ�ܣ�����·���Ƿ�Ƿ���" << endl;
		cout << "��ǰ·��:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}
	file.close();

	return 1;
}

bool OperateTable::readPreFile() 

	//���������ļ����������Ķ�����и�ֵ

{
	string thisName = "test";
	cout << "\t������Ҫ��ѯѧ��������:  ";
	cin >> thisName;
	cout << endl;
	saveAddress.setName(thisName);

	StoreTable ST;
	fstream file;
	
	try {
		file.open(saveAddress.getCompleteAddress(), ios::in | ios::binary);
		if (!file)
		{
			//���ļ�ʧ�ܣ��׳��쳣

			throw 987;
		}

		file.read((char*)&ST, sizeof(ST));

		file.flush();

		file.close();

		this->table.translateFromStoreTable(ST);
	}
	catch (int goal)
	{
		cout << "������룺 " << goal << "  ";
		cout << "�α��ļ���ʧ�ܣ�����·���Ƿ�Ƿ���" << endl;
		cout << "��ǰ·��:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}

	
	
	return 1;

}

bool OperateTable::readPreFile(string name)

//���������ļ����������Ķ�����и�ֵ

{
	string thisName = name;
	saveAddress.setName(thisName);

	StoreTable ST;
	fstream file;

	try {

		file.open(saveAddress.getCompleteAddress(), ios::in | ios::binary);
		if (!file)
		{
			//���ļ�ʧ�ܣ��׳��쳣

			throw 987;
		}
		
		file.read((char*)&ST, sizeof(ST));
		
		file.flush();

		file.close();

		this->table.translateFromStoreTable(ST);
	}
	catch (int goal)
	{
		cout << "������룺 " << goal << "  ";
		cout << "�α��ļ���ʧ�ܣ�����·���Ƿ�Ƿ���" << endl;
		cout << "��ǰ·��:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}


	return 1;

}

bool OperateTable::readPreFile(string name, int oridinal) 
//oridinal ����ڼ�������
{
	string thisName = name;
	saveAddress.setName(thisName);

	StoreTable ST;
	fstream file;

	try {

		file.open(saveAddress.getCompleteAddress(), ios::in | ios::binary);
		if (!file)
		{
			//���ļ�ʧ�ܣ��׳��쳣

			throw 987;
		}
		short t = (oridinal-1) * sizeof(this->table);
		
		file.seekg(t, ios::beg);
		/*************************************************************
			����Ҫ�㣬������ȡָ��
		**************************************************************/

		file.read((char*)&ST, sizeof(ST));
		if (file.eof())
		{
			return false;
		}
		file.close();

		this->table.translateFromStoreTable(ST);
	}
	catch (int goal)
	{
		cout << "������룺 " << goal << "  ";
		cout << "�α��ļ���ʧ�ܣ�����·���Ƿ�Ƿ���" << endl;
		cout << "��ǰ·��:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}
	return true;
}


/**************************************************************************
//��Tableת��Ϊ.csv �ļ���ֻ���ڵ�ǰ����
	��һ����ת��ѧ���α��ڶ���ת����ʦ�α�����·����ͬ
***************************************************************************/


bool OperateTable::transformSTToCSV() 

{

	saveAddress.ForStudentCSV(this->table.getOwnerName());
	
	ofstream file;
	try {
		file.open(this->saveAddress.getCompleteAddress(), ios::out | ios::app);

		if (!file)
		{
			throw 987;
		}
		file  <<this->table.getSelfName()<<endl;
		file << translateNumToClassType(table.getClassType()) << endl;

		while (!table.lessonTimeTable.empty())

			//ѭ���ó����ȶ����еĿγ�

		{

			Lesson lesson(table.lessonTimeTable.top());

			file<<lesson.getMonth();
			file << ".";
			file << lesson.getDay();
			file << ",";
			table.lessonTimeTable.pop();

		}
		file << "\n";
		for (int i = 1; i <= table.getNum(); i++) 
		{
			file << table.getTheOtherName() << ",";
		}
		file << "\n\n";
		file.close();
	}
	catch (int goal) 
	{
		cout << "������룺 " << goal << "  ";
		cout << "�α��ļ���ʧ�ܣ�����·���Ƿ�Ƿ���" << endl;
		cout << "��ǰ·��:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}
	return 1;

}

bool OperateTable::transformTTToCSV()

{

	saveAddress.ForTeacherCSV(this->table.getOwnerName());

	ofstream file;
	try {
		file.open(this->saveAddress.getCompleteAddress(), ios::out | ios::app);

		if (!file)
		{
			throw 987;
		}
		file << this->table.getSelfName() << endl;
		file << translateNumToClassType(table.getClassType()) << endl;

		while (!table.lessonTimeTable.empty())

			//ѭ���ó����ȶ����еĿγ�

		{

			Lesson lesson(table.lessonTimeTable.top());

			file << lesson.getMonth();
			file << ".";
			file << lesson.getDay();
			file << ",";
			table.lessonTimeTable.pop();

		}
		file << "\n";
		for (int i = 1; i <= table.getNum(); i++)
		{
			file << table.getTheOtherName() << ",";
		}
		file << "\n\n";
		file.close();
	}
	catch (int goal)
	{
		cout << "������룺 " << goal << "  ";
		cout << "�α��ļ���ʧ�ܣ�����·���Ƿ�Ƿ���" << endl;
		cout << "��ǰ·��:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}

	return 1;
}



bool OperateTable::updateThisTable()
{
	system("cls");
	string TEAName;
	int cnt = 1;
	cout << "*************************************************************" << endl;
	cout << "\t��\t��\t��\t��" << endl<<endl;
	cout << "�������ʦ���� :  ";
	cin >> TEAName;
	bool flag;
	while (readPreFile(TEAName,cnt))
	{
		
		this->table.shortShowSTD();
		if (!checkIsThisTable()) 
		{
			
			cout << endl;
			continue;
		}
		if (changeThisTable())			//�α���
		{
			flag = 1;
			
			saveThisFile(cnt);					//������
			
			cout << "�Ƿ��޸Ĵ�λ��ʦ�������α�" << endl;
			if (!checkToContinue())
			{
				operationCancled();
				return true;
			}
		}
		cnt++;
	}
	if (!flag) 
	{
		return false;
	}
	return true;
}


bool OperateTable::checkIsThisTable()
{
	this->table.shortShowTEA();
	int temp=0,temp2=0;
	
	while (temp <= 0 || temp > 3) 
	{
		cout << "1. �޸Ĵ˿α�  2. չʾ�˿α���ϸ��Ϣ  3. չʾ��һ���α� " << endl;
		cout << "��ѡ��Ҫʹ�õĹ��� :  ";
		cin >> temp;
	}
	switch (temp) 
	{
		case 1: 
		{
			return true;
			break;
		}
		case 2: 
		{
			Table show(this->table);
			show.displayTEA();
			
			while (temp2 <= 0 || temp2 > 2)
			{
				cout << "1. �޸Ĵ˿α�  2. չʾ��һ���α� " << endl;
				cout << "��ѡ��Ҫʹ�õĹ��� :  ";
				cin >> temp2;
			}
			if (temp2 == 1)
			{
				return true;
			}
			else if (temp2 == 2)
			{
				return false;
			}
			else 
			{
				return false;
			}
			break;
		}
		case 3:
		{
			return false;
			break;
		}
		default: 
		{
			return false;
			break;
		}
	}
}



bool OperateTable::changeThisTable()
{
	system("cls");
	
	Table show(this->table);
	show.displayTEA();
	cout << endl << endl;
	
	int temp = 0;
	
	while (temp <= 0 || temp > 3)
	{
		cout << "1. ���ӿγ� 2. ɾ���γ� 3. �����γ�ʱ�� 4. �����γ�����"<<endl;
		cout << "��ѡ��Ҫʹ�õĹ��� :  ";
		cin >> temp;
	}
	cout << "��ѡ����� " << temp << " ����" << endl;
	if (!checkToContinue())
	{
		operationCancled();
		return false;
	}
	switch (temp) 
	{
		case 1:
		{
			
			do 
			{
				if (addLesson())
				{
					cout << "Success ��ӳɹ�" << endl;
				}
				else 
				{
					cout << "�γ����ʧ�� !" << endl;
				}
			} while (checkToContinue());

			break;

		}
		case 2:
		{
			
			do 
			{
				if (!deleteLesson())
				{
					cout << "ɾ���γ�ʧ�ܣ����������������������Ϣ�Ϳγ���������Ӧ���µ�" << endl;
					cout << "���������ٽ����޸�" << endl;
				}
				else 
				{
					cout << endl;
				}
			} while (checkToContinue());

			break;
		}
		case 3:
		{
			do
			{
				cout << "��������ǰ�Ŀγ���Ϣ  " << endl;
				if (!deleteLesson()) 
				{
					cout << "ɾ���γ�ʧ�ܣ����������������������Ϣ�Ϳγ���������Ӧ���µ�" << endl;
					cout << "���������ٽ����޸�" << endl;
				}
				cout << "����������Ŀγ���Ϣ  " << endl;

				if (!addLesson())
				{
					cout << "�γ���Ϣ����ɹ� !" << endl;
				}
			
			} while (checkToContinue());

			break;
		}
		case 4: 
		{
			int type=0;
			cout << "��ǰ�Ŀγ������� " << translateNumToClassType(this->table.classType) << endl;
			if (!checkToContinue())
			{
				operationCancled();
				return false;
			}
			do
			{
				for (int i = 1; i <= 6; i++)
				{
					cout << i << ". " << translateNumToClassType(i) << endl;
				}

				cout << "�������µĿγ����͵Ķ�Ӧ���(1-6)  " << endl;

			} while (type <= 0 || type > 6);

			this->table.classType = type;
			break;
		}
		default: 
		{
			cout << "Warning ѡ������쳣������" << endl;
		}
	}
	return true;
}

bool OperateTable::addLesson()
{
	int month = 1, day = 1, num = 1;
	cout << "�������·�	     :  ";
	cin >> month;
	cout << "����������      :  ";
	cin >> day;
	cout << "������ڼ��ڿ�  :  ";
	Lesson lesson(month, day, num);
	this->table.lessonTimeTable.push(lesson);
	this->table.number++;
	return true;
}


bool OperateTable::deleteLesson()
{
	
	
	int month = 1, day = 1, num = 1;
	cout << "�������·�	     :  ";
	cin >> month;
	cout << "����������      :  ";
	cin >> day;
	cout << "������ڼ��ڿ�  :  ";

	Lesson lesson(month, day, num), tem;

	int j = this->table.getNum();

	while (j && this->table.lessonTimeTable.top() != lesson && !this->table.lessonTimeTable.empty())
	{

		tem = this->table.lessonTimeTable.top();
		this->table.lessonTimeTable.pop();
		this->table.lessonTimeTable.push(tem);
		j--;

	}
	
	if (!j)
	{
		return false;
	}
	else
	{
		cout << "�γ�ɾ���ɹ�! ɾ���Ŀγ���Ϣ���� : " << endl;
		lesson.display();
		return true;
	}

}


int OperateTable::checkHowLongBelonging(Table TEATab) 
{
	string STDName;
	STDName=TEATab.getTheOtherName();
	TableInfo testAddress;
	testAddress.setName(STDName);
	int cnt = 1;
	bool flag = 0;
	while (readPreFile(STDName, cnt))

	{
		string filename1, filename2;
		filename1 = this->table.getTheOtherName() + ",dat";
		filename2 = this->saveAddress.getfileName();
		if (filename1==filename2)
		{
			flag = 1;
			return cnt;
		}
		cnt++;
	}
	if (!flag) 
	{
		return -1;//û���ҵ��򷵻�-1
	}
}

