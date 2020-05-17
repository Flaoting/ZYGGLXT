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



