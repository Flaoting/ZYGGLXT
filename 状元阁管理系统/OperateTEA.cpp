#include "OperateTEA.h"
#include "PeoNum.h"
#include "PerInfo.h"

OperateTEA::OperateTEA(){}

OperateTEA::~OperateTEA(){}

OperateTEA::OperateTEA(const OperateTEA& obj) 
{
	this->teacher = obj.teacher;
}



void OperateTEA::getInfoFromScreen()

//�ѱ����������TEA ������Ϣ
{

	AddTEAMenu  ATM;

	ATM.display();
	teacher = ATM.getTeacher();
	string name(teacher.getName());

	TEAInfo TI(name);
	
	saveAddress = TI;
}



bool OperateTEA::saveThisFile()

//�����ļ�
{
	setTeasID(this->teacher);

	ofstream file(saveAddress.getCompleteAddress(), ios::out | ios::binary);

	if (!file)

	{
		cout << "��ʦ��Ϣ�ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;
		return 0;
	}

	file.write((char*)&teacher, sizeof(teacher));
	file.close();

	PerInfo PI("TotalTeacher");//��������Ϣ�����ַ

	ofstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary | ios::app|ios::out);

	if (!perFile)
	{
		cout << "��ʦ��Ϣ���ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;

		return 0;

	}
	perFile.write((char*)&teacher, sizeof(teacher));

	perFile.close();
	
	cout << "Success  ��ʦ��Ϣ����ɹ�!" << endl;
	return true;
}



bool OperateTEA::readPreFile()

//���ļ��ж�ȡ�ļ���Ϣ

{
	string thisName = "test";
	cout << "������Ҫ��ѯ��ʦ������:  ";
	cin >> thisName;
	cout << endl;

	saveAddress.setName(thisName);
	
	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)

	{
		cout << "��ʦ��Ϣ�ļ���ʧ�ܣ�����·���������Ƿ���ȷ��" << endl;
		return 0;
	}

	file.read((char*)&teacher, sizeof(teacher));
	file.close();
	return 1;

}

bool OperateTEA::readPreFile(string name)

//���ļ��ж�ȡ�ļ���Ϣ

{
	string thisName = name ;
	saveAddress.setName(thisName);

	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)

	{
		cout << "��ʦ��Ϣ�ļ���ʧ�ܣ�����·���������Ƿ���ȷ��" << endl;
		return 0;
	}

	file.read((char*)&teacher, sizeof(teacher));
	file.close();
	return 1;

}

bool OperateTEA::readPreFile(int oridinal) 
	//�ӽ�ʦ�ܱ��ж�����ʦ������
	//���������ǵڼ�����Ϣ
{
	PerInfo PI("TotalTeacher");//��������Ϣ�����ַ

	ifstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary | ios::in);

	if (!perFile)
	{
		cout << "��ʦ��Ϣ���ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;
		cout << "��ǰ·���� " << saveAddress.getCompleteAddress() << endl;
		return 0;

	}

	short t = (oridinal-1) * sizeof(this->teacher);
	
	perFile.seekg(t, ios::beg);
	
	if (perFile.eof()) 
	{
		return false;
	}
	
	perFile.read((char*)&teacher, sizeof(teacher));
	
	perFile.close();
	
	return true;

}

void OperateTEA::setTeasID(People& obj)

{
	//����ID
	PeoNum PN;

	obj.ID = PN.returnNum();

}



bool OperateTEA::updateTeacherInfo(string  TEAname)
{

	try 
	{
		saveAddress.setName(TEAname);

		fstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary | ios::out);

		if (!file)
		{
			cout << "��ʦ��Ϣ�ļ���ʧ�ܣ�����·���������Ƿ���ȷ��" << endl;
			cout << "��ǰ��·���� " << saveAddress.getCompleteAddress() << endl;
			return 0;
		}

		file.read((char*)&teacher, sizeof(teacher));

		getChangeInfo();

		if (catchElection())		//���������ѧ���������͸���һ���ļ��� 
		{
			file.close();
			TEAInfo PreAddress = this->saveAddress;

			this->saveAddress.setName(this->teacher.getName());
			if (rename(PreAddress.getCompleteAddress().c_str(), this->saveAddress.getCompleteAddress().c_str()) < 0)
			{
				cout << "Warning �ļ�����ʧ��" << endl;
				cout << "ԭ�ļ�λ����  " << PreAddress.getCompleteAddress() << endl;
				cout << "���ļ�λ����  " << this->saveAddress.getCompleteAddress() << endl;
				cout << "�������ʾ�����ֶ��޸��ļ����� ,��л����������ϣ�" << endl;

				file.open(PreAddress.getCompleteAddress(), ios::in | ios::binary | ios::out);

				file.seekp(0, ios::beg);  //ָ�������ͷ

				file.write((char*)&teacher, sizeof(teacher)); // д���޸ĺ����Ϣ

				file.close();

				cout << "Success  ѧ����Ϣ�޸ĳɹ�" << endl << endl;

				return 1;
			}
			file.open(saveAddress.getCompleteAddress(), ios::in | ios::binary | ios::out);
			//������������ļ���ֻ��Ҫ���жԸ�������ļ�����ˢ��

		}

		file.seekp(0, ios::beg);  //ָ�������ͷ

		file.write((char*)&teacher, sizeof(teacher)); // д���޸ĺ����Ϣ

		file.close();

		cout << "Success  ��ʦ��Ϣ�޸ĳɹ�" << endl << endl;

		return 1;	
	
	}
	catch (int goal)
	{
		cout << "Warning  ���ź��������޸�ʧ�� ������" << endl;
		cout << "���޸���������Ϣ��������������Ϣ�������ļ�����ʧ��" << endl;
		cout << "�������  " << goal << endl;
		cout << "��ǰ�ļ�·��" << this->saveAddress.getCompleteAddress() << endl;
		cout << "���������ļ��Ƿ��쳣��" << endl;
		cout << "����δ���������ϵ������Ա..." << endl;
		system("pause");
	}
	


}



/*************************************************************
		����Ļչʾ���ڵ���Ϣ��������޸���Ϣ�Ĵ�����ʲô
**************************************************************/
void OperateTEA::getChangeInfo()
{
	system("cls");
	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\t��ʦ������Ϣ�޸�" << endl;
	cout << "���潫չʾ��ǰ��Ϣ,�����˶Բ���¼ҪҪ�޸ĵ���Ϣ" << endl;
	system("pause");
	cout << "��ǰ��ʦ��Ϣ��  :   " << endl << endl;
	this->teacher.display();

}


/*************************************************************
		����Ļչʾ���ڵ���Ϣ��
		��ȡѡ����룬�������޸ĵĺ���
		char* name, char sex, char* phone, char* QQ, Purpose subj, int salary=60
**************************************************************/
bool OperateTEA::catchElection()

{
	cout << "�� ѡ �� �� Ҫ �� �� �� �� Ϣ " << endl;
	cout << "1. ��  ��   2. ��  ��   3. �ֻ�����  " << endl;
	cout << "4. QQ  ��   5. ��  Ŀ   6. Ĭ��ʱн  " << endl;
	
	int election = 0;

	bool goon = true;
	bool setname = false;

	while (goon)
	{
		election = 0;

		while (election <= 0 || election > 6)
		{
			cout << "��������Ҫ�޸���Ϣ�Ĵ���(1-6)" << endl;
			cin >> election;
		}
		if (election == 1)
		{
			setname = true;
		}

		if (!doChangeInfo(election))
		{
			cout << "��ǰ��Ϣ�޸�ʧ��,��������Ϊѡ�����Ϣ������������ϸ���" << endl;
		}

		cout << "�Ƿ�����޸�������Ϣ ��" << endl;
		if (!checkToContinue())
		{
			goon = false;
		}

	}
	return setname;
}



bool OperateTEA::doChangeInfo(int election)
{
	switch (election)
	{

	case 1:
	{
		string name;
		char TEAName[25];
		cout << "�������޸ĺ������ :  ";
		cin >> name;
		strcpy_s(TEAName, name.c_str());
		this->teacher.setName(TEAName);
		return true;
	}

	case 2:
	{
		char gender;
		cout << "�������޸ĺ���Ա� :  ";
		gender = checkGender();
		this->teacher.gender = gender;
		return true;
	}

	case 3:
	{
		string phone;
		char TEAPhone[25];

		cout << "�������޸ĺ�ĵ绰���� :  ";
		cin >> phone;

		strcpy_s(TEAPhone, phone.c_str());
		this->teacher.setPhone(TEAPhone);

		return true;
	}

	case 4:
	{
		string QQ;
		char TEAQQ[25];
		cout << "�������޸ĺ��QQ���� :  ";
		cin >> QQ;
		strcpy_s(TEAQQ, QQ.c_str());
		this->teacher.setQQ(TEAQQ);
		return true;
	}

	case 5:
	{
		this->teacher.sub = catchPurpose();			//��ȡ������Ŀ
	}

	case 6:
	{
		int salary = 60;
		cout << "�������޸ĺ��ʱн(������) :  " << endl;
		cin >> salary;
		cout << endl;
		this->teacher.setSalary(salary);
		return true;
	}

	default:
	{
		cout << "�޸�ʧ��" << endl;
		return false;
	}

	}

}



/*************************************************************
		��ȡ��Ŀ�ķ���
**************************************************************/
Purpose OperateTEA::catchPurpose()

{
	vector<string> list;
	int a = 1;
	cout << "�������ѧ��Ŀ���� :  ";
	cin >> a;
	cout << endl;
	string ttt;
	cout << "������ֱ�����γ����ƣ��м��ÿո���� (��:���� ��ѧ)" << endl;

	for (int i = 1; i <= a; i++)
	{
		cout << "������� " << i << " ����Ŀ :  ";
		cin >> ttt;
		list.push_back(ttt);
	}
	if (a == 0)
	{
		ttt = "�޿�Ŀ";
		list.push_back(ttt);

	}
	Purpose pur(list);
	return pur;

}



Teacher OperateTEA::getTeacher() 

{

	return this->teacher;

}



