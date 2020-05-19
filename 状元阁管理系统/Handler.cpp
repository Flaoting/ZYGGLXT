#include "Handler.h"

Handler::Handler():operatorManager()
{
	//���캯�����������
	this->LOGIN = false;
}

Handler:: ~Handler()
{
	//��������
}


bool Handler::LoginManager(string name, string SS) 
{
	string addName = "MagInfo//" + name;

	PerInfo PIP(addName);
	ifstream PrtFile;

	PrtFile.open(PIP.getCompleteAddress(), ios::out | ios::binary);

	if (!PrtFile)
	{
		cout << " Manager ��ȡ����ʧ�ܣ�" << endl;
		cout << "����·��" << PIP.getCompleteAddress() << "�Ƿ���ڣ�";
		return 0;
	}

	PrtFile.read((char*)&this->operatorManager, sizeof(this->operatorManager));


	PrtFile.close();

	if (operatorManager.getSSH() == SS)
	{
		this->LOGIN = true;
		cout <<"����Ա " <<operatorManager.getName()<<" ��¼�ɹ�" << endl;
		return 1;
	}

	else
	{
		cout << "����Ա������Կ����,����м��";
		return 0;
	}

}

bool Handler::getStatus() 
{
	return this->LOGIN;						//��ѯLogin״̬
}


void Handler::addSTD()

{
	OperateSTD operateSTD;
	operateSTD.getInfoFromScreen();
	operateSTD.saveThisFile();
}

void Handler::addTEA()
{
	OperateTEA operateTEA;
	operateTEA.getInfoFromScreen();
	operateTEA.saveThisFile();
}

void Handler::addTAB() 
{
	OperateTable operateTab;
	operateTab.getTableFromScreen();
	operateTab.saveThisFile();
}

void Handler:: addToll() 
{
	TollMenu toll(this->operatorManager);
	toll.display();
}

void Handler:: setTable() 
{
	OperateTable operateTab;
	operateTab.updateThisTable();

}

void Handler:: changeMAGSSH() 
{
	this->operatorManager.setSSH();
	cout << "�� �� �� �� Ա " << this->operatorManager.getName();
	cout << " �� �� Կ �� �� !!! " << endl;
}

void Handler::addVio() 
{
	ViolationMenu Vio(this->operatorManager);
	Vio.display();
}

void Handler::addRun() 
{
	RunningMenu running(this->operatorManager);
	running.display();
}

void Handler::showOneRun(int ruler, int small)
{
	QueryRecord QR;
	RunningRecord RUN(QR.getRunningRecord(ruler));
	if (small == 1) 
	{
		RUN.shortShow();
	}
	else 
	{
		RUN.display();
	}
}

void Handler::showOneToll_S(int ruler, int small) 
{
	QueryRecord QR;
	TransactionRecord Toll(QR.getHidenTransactionRecord(ruler));
	if (small == 1)
	{
		Toll.shortShow();
	}
	else
	{
		Toll.display();
	}
}

void Handler::showOneToll(int ruler, int small) 
{


	QueryRecord QR;
	TransactionRecord Toll(QR.getHidenTransactionRecord(ruler));
	if (small == 1)
	{
		Toll.shortShow();
	}
	else
	{
		Toll.display();
	}
}

void Handler::showOneVio(int ruler) 
{
	QueryRecord QR;
	ViolationRecord Vio(QR.getViolationRecord(ruler));

	Vio.display();
}

bool Handler::checkSSH() 

{
	string ssh;
	cout << "��ǰ����Ա�� " << this->operatorManager.getName() << endl;
	cout << "������������Կ :  ";
	ssh = getStringWithoutShow();
	return this->operatorManager.checkSSH(ssh);


}

void Handler::showAllTEA()
{

	PerInfo PI("TotalTeacher");//��������Ϣ�����ַ

	ifstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary | ios::in);

	if (!perFile)
	{
		cout << "��ʦ��Ϣ���ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;

		cout << "��ǰ·��" << PI.getCompleteAddress() << endl;

	}
	Teacher teacher;
	int i = 1;
	while (!perFile.eof()) 
	{
		perFile.read((char*)&teacher, sizeof(teacher));
		teacher.display();
		
		if (i % 2 == 0) 
		{
			cout << "���ⰴ����������������" << endl;
			system("pause");
			system("cls");
		}
		i++;
	}
	perFile.close();
	return ;
}


void Handler::shouwAllSTD() 

{
	PerInfo PI("TotalStudent");//��������Ϣ�����ַ

	ifstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary | ios::in);

	if (!perFile)
	{
		cout << "ѧ����Ϣ���ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;

		cout << "��ǰ·��" << PI.getCompleteAddress() << endl;

	}
	Student student;
	int i = 1;
	while (!perFile.eof())
	{
		perFile.read((char*)&student, sizeof(student));
		student.display();
		if (i % 2 == 0)
		{
			cout << "���ⰴ����������������" << endl;
			system("pause");
			system("cls");
		}
		i++;
	}
	perFile.close();
	return;
}


float  Handler::checkSummery( int show) 
{
	Manager temp;
	Student test;
	Date d;
	TransactionRecord Transaction(temp, test);
	float summery = 0;
	

	RecordInfo ADD("TransactionRecord");
	ifstream file;

	file.open(ADD.getCompleteAddress(), ios::in | ios::binary);

	if (!file)
	{
		cout << "Warning �����ļ���ʧ��  " << endl;
		cout << "�����Ƿ����·��" << ADD.getCompleteAddress() << endl;
		throw 4558;
	}
	int ruler = 1;
	while (!file.eof()) 
	{
		int t = (ruler - 1) * sizeof(Transaction);
		
		file.seekg(t, ios::beg);

		if (file.eof())
		{
			file.close();
			throw 3131;
		}
		file.read((char*)&Transaction, sizeof(Transaction));

		summery += Transaction.getPayment();
		if (show) 
		{
			Transaction.shortShow();
		}
		ruler++;
	}
	
	file.close();

	return summery;

}


void Handler::showAllRun(int small) 
{


	Manager temp;
	RunningRecord Running(temp, 0, "test");


	RecordInfo ADD("RunningRecord");

	ifstream file;

	file.open(ADD.getCompleteAddress(), ios::binary | ios::in);

	if (!file)
	{
		cout << "Warning ��ˮ��¼�ļ���ʧ��  " << endl;
		cout << "�����Ƿ����·��" << ADD.getCompleteAddress() << endl;
		throw 4585;
	}
	while (!file.eof())
	{
		file.read((char*)&Running, sizeof(Running));
		if (small == 1)
		{
			Running.shortShow();
		}
		else
		{
			Running.display();
		}

	}
	
	file.close();
	return;
}

void Handler::showAllVio( ) 

{
	Manager temp;
	Teacher test;
	Date d;
	ViolationRecord Violation(temp, test, 0, 0, d, "test");


	RecordInfo ADD("ViolationRecord");
	ifstream file;

	file.open(ADD.getCompleteAddress(), ios::in | ios::binary);

	if (!file)
	{
		cout << "Warning ��¼�ļ���ʧ��  " << endl;
		cout << "�����Ƿ����·��" << ADD.getCompleteAddress() << endl;
		throw 4558;
	}
	
	while (!file.eof()) 
	{
		
		file.read((char*)&Violation, sizeof(Violation));
		
		Violation.display();
	}

	file.close();

	return ;
}

void Handler::showAllToll(int small) 
{
	Manager temp;
	Student test;
	Date d;
	TransactionRecord Transaction(temp, test);


	RecordInfo SUM;
	ifstream file2;

	file2.open(SUM.getCompleteAddress(), ios::in | ios::binary);

	if (!file2)
	{
		cout << "Warning �����ļ���ʧ��  " << endl;
		cout << "�����Ƿ����·��" << SUM.getCompleteAddress() << endl;
		throw 4558;
	}
	
	
	while (!file2.eof())
	{
		file2.read((char*)&Transaction, sizeof(Transaction));
		if (small == 1)
		{
			Transaction.shortShow();
		}
		else
		{
			Transaction.display();
		}
	}
	
	file2.close();
}
