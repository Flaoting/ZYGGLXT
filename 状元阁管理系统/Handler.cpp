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

	time_t now;
	int unixTime = (int)time(&now);	int gap = 0;
	gap = unixTime - RUN.getTimeStamp();
	
	if (abs(gap) > 3)
	{

		if (small == 1)
		{
			RUN.shortShow();
		}
		else
		{
			RUN.display();
		}

	}
}

void Handler::showOneToll_S(int ruler, int small) 
{
	QueryRecord QR;
	TransactionRecord Toll(QR.getHidenTransactionRecord(ruler));

	time_t now;
	int unixTime = (int)time(&now);
	int gap = 0;
	gap = unixTime - Toll.getTimeStamp();
	if (abs(gap) > 3)
	{
		if (small == 1)
		{
			Toll.shortShow();
		}
		else
		{
			Toll.display();
		}
	}
	return;
}

void Handler::showOneToll(int ruler, int small) 
{




	QueryRecord QR;
	TransactionRecord Toll(QR.getHidenTransactionRecord(ruler));
	
	time_t now;
	int unixTime = (int)time(&now);
	int gap = 0;
	gap = unixTime - Toll.getTimeStamp();
	
	if (abs(gap) > 3)
	{

		if (small == 1)
		{
			Toll.shortShow();
		}
		else
		{
			Toll.display();
		}

	}
	return;
}

void Handler::showOneVio(int ruler) 
{

	QueryRecord QR;
	ViolationRecord Vio(QR.getViolationRecord(ruler));

	time_t now;
	int unixTime = (int)time(&now);
	int gap = 0;
	gap = unixTime - Vio.getTimeStamp();
	if(abs(gap)>3)
	{
	Vio.display();
	}
	return;
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
	perFile.read((char*)&teacher, sizeof(teacher));
	if (perFile.eof())
	{
		cout << "û�н�ʦ��¼�ɹ���ѯ����������ӽ�ʦ��Ϣ !!!!" << endl;
		return;
	}

	while (!perFile.eof()) 
	{

		teacher.display();
		cout << endl;
		i++;
		if (i % 2 == 0) 
		{
			cout << "���ⰴ����������������" << endl;
			system("pause");
			system("cls");
		}
		perFile.read((char*)&teacher, sizeof(teacher));
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

	perFile.read((char*)&student, sizeof(student));
	if (perFile.eof()) 
	{
		cout << "û��ѧ����¼�ɹ���ѯ�����������ѧ����Ϣ !!!!" << endl;
		return;
	}

	while (!perFile.eof())
	{
		
		student.display();
		cout << endl;
		i++;

		if (i % 2 == 0)
		{
			cout << "���ⰴ����������������" << endl;
			system("pause");
			system("cls");
		}
		
		perFile.read((char*)&student, sizeof(student));
	}

	perFile.close();
	return;
}


float  Handler::checkSummery( int show)    //�������˵ĺ�����show���Ƿ��Ҫ��չʾ���׼�¼ 
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
	
	file.read((char*)&Transaction, sizeof(Transaction));//��һ�ζ�ȡ

	if (file.eof())				//��ȡʧ���򷵻�summery
	{
		file.close();
		cout << "��ʱû�н��׼�¼�ɹ����� ������" << endl;
		return summery;
	}

	summery += Transaction.getPayment();

	if (show == 1)
	{
		Transaction.shortShow();
	}

	while (!file.eof()) 
	{
		file.read((char*)&Transaction, sizeof(Transaction));

		if (file.eof())
		{
			file.close();
			return summery;
		}
		summery += Transaction.getPayment();

		if (show==1) 
		{
			Transaction.shortShow();
		}
	
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

	file.read((char*)&Running, sizeof(Running));

	if (file.eof()) 
	{
		cout << "û����ˮ��¼�ɹ���ѯ!!! " << endl;
		return;
	}

	while (!file.eof())
	{
		if (small == 1)
		{
			Running.shortShow();
		}
		else
		{
			Running.display();
		}

		file.read((char*)&Running, sizeof(Running));
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
	

	file.read((char*)&Violation, sizeof(Violation));

	if (file.eof()) 
	{
		cout << "û�н�ѧ�¹ʼ�¼�ɹ���ѯ!!! " << endl;
		return;
	}

	while (!file.eof()) 
	{
		Violation.display();

		file.read((char*)&Violation, sizeof(Violation));
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
	
	file2.read((char*)&Transaction, sizeof(Transaction));

	if (file2.eof()) 
	{
		cout << "û�н��׼�¼�ɹ���ѯ!!! " << endl;
	}
	while (!file2.eof())
	{
		if (small == 1)
		{
			Transaction.shortShow();
		}
		else
		{
			Transaction.display();
		}

		file2.read((char*)&Transaction, sizeof(Transaction));
	
	}
	
	file2.close();
}
