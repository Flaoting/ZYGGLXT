#include "OperateSTD.h"
#include "PeoNum.h"
#include "AddSTDMenu.h"
#include "PerInfo.h"
#include <io.h>
#include <fcntl.h>
#include <fstream>


OperateSTD::OperateSTD() {}



OperateSTD::~OperateSTD(){}



void OperateSTD::getInfoFromScreen()

//�ѱ����������STD ������Ϣ

{
	AddSTDMenu  ASM;

	ASM.display();
	stud =  ASM.getStudent();
	string name(stud.getName());

	STDInfo SI(name);
	saveAddress = SI;
}



bool OperateSTD::saveThisFile() 
{
	setStdsID(this->stud);

	ofstream file(saveAddress.getCompleteAddress(), ios::out | ios::binary);

	if (!file) 
	
	{
		cout << "ѧ��������Ϣ�ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;
		return 0;
	}
	
	file.write((char*)&stud, sizeof(stud));
	file.close();

	PerInfo PI("TotalStudent");//��������Ϣ�����ַ
	
	ofstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary |ios::app|ios::out);
	
	if (!perFile) 
	{
		cout << "ѧ����Ϣ���ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;

		cout << "��ǰ·���� :  " << PI.getCompleteAddress() << endl;
		
		return 0;

	}
	perFile.write((char*)&stud, sizeof(stud));
	perFile.close();
	cout << "ѧ��" << this->stud.getName() << " ����Ϣ����ɹ�" << endl;
	cout << "����·��Ϊ :  " << saveAddress.getCompleteAddress() << endl;
	return 1;
}



bool OperateSTD::readPreFile( ) 
	
	//������Ϣ��������˽������

{
	string thisName="test";
	cout << "\t������Ҫ��ѯѧ��������:  ";
	cin >> thisName;
	cout << endl;
	saveAddress.setName(thisName);

	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)

	{
		cout << "ѧ����Ϣ�ļ���ʧ�ܣ�����·���������Ƿ���ȷ��" << endl;
		return 0;
	}

	file.read((char*)&stud, sizeof(stud));
	file.close();
	//student.display();
	return 1;

}

bool OperateSTD::readPreFile(string STDname)
{
	saveAddress.setName(STDname);

	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)
	{
		cout << "ѧ����Ϣ�ļ���ʧ�ܣ�����·���������Ƿ���ȷ��" << endl;
		cout << "��ǰ��·���� " << saveAddress.getCompleteAddress() << endl;
		return 0;
	}
	file.read((char*)&stud, sizeof(stud));
	
	file.close();
	return 1;
}

bool OperateSTD::readPreFile(int oridinal)
//��ѧ���ܱ��ж�����ʦ������
//���������ǵڼ�����Ϣ
{
	PerInfo PI("TotalStudent");//��������Ϣ�����ַ

	ifstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary | ios::in);

	if (!perFile)
	{
		cout << "ѧ����Ϣ���ļ���ʧ�ܣ�����·���Ƿ���ȷ��" << endl;
		cout << "��ǰ·���� " << saveAddress.getCompleteAddress() << endl;
		return 0;

	}

	short t = (oridinal - 1) * sizeof(this->stud);

	perFile.seekg(t, ios::beg);

	if (perFile.eof())
	{
		return false;
	}

	perFile.read((char*)&this->stud, sizeof(this->stud));

	perFile.close();

	return true;

}

Student OperateSTD::getStudent() 

{
	return this->stud;
}



void OperateSTD::setStdsID(People& obj) 

{
	//����ID
	PeoNum PN;

	obj.ID = PN.returnNum();

}



bool OperateSTD::updateStudentInfo(string  STDname) 
{

	saveAddress.setName(STDname);

	fstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary|ios::out);

	if (!file)
	{
		cout << "ѧ����Ϣ�ļ���ʧ�ܣ�����·���������Ƿ���ȷ��" << endl;
		cout << "��ǰ��·���� " << saveAddress.getCompleteAddress() << endl;
		return 0;
	}

	file.read((char*)&stud, sizeof(stud));
	
	getChangeInfo();

	if (catchElection())		//���������ѧ���������͸���һ���ļ��� 
	{   
		file.close();
		STDInfo PreAddress = this->saveAddress;

		this->saveAddress.setName(this->stud.getName());
		if(rename(PreAddress.getCompleteAddress().c_str(), this->saveAddress.getCompleteAddress().c_str())<0)
			cout <<"����ʧ��";
		file.open(saveAddress.getCompleteAddress(), ios::in | ios::binary | ios::out);
	}
	
		file.seekp(0, ios::beg);  //ָ�������ͷ

		file.write((char*)&stud, sizeof(stud)); // д���޸ĺ����Ϣ

		file.close();

		cout << "Success  ѧ����Ϣ�޸ĳɹ�" << endl<<endl;

		return 1;
	


}



/*************************************************************
		����Ļչʾ���ڵ���Ϣ��������޸���Ϣ�Ĵ�����ʲô
**************************************************************/
void OperateSTD:: getChangeInfo()   
{
	system("cls");
	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\tѧ��������Ϣ�޸�" << endl;
	cout << "���潫չʾ��ǰ��Ϣ,�����˶Բ���¼ҪҪ�޸ĵ���Ϣ" << endl;
	system("pause");
	cout << "��ǰѧ����Ϣ��  :   " << endl<<endl;
	this->stud.display();
	
}


/*************************************************************
		����Ļչʾ���ڵ���Ϣ��
		��ȡѡ����룬�������޸ĵĺ���
**************************************************************/
bool OperateSTD::catchElection()

{
	cout << "�� ѡ �� �� Ҫ �� �� �� �� Ϣ " << endl;
	cout << "1. ��  ��   2. ��  ��   3. �ֻ�����  " << endl;
	cout << "4. ��  ��   5. ��  Ŀ   6. ��������  " << endl;
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

		doChangeInfo(election);
		cout << "�Ƿ�����޸�������Ϣ ��" << endl;
		if (!checkToContinue()) 
		{
			goon = false;
		}

	}
	return setname;
}



bool OperateSTD::doChangeInfo(int election)
{
	switch (election)
	{
		
		case 1: 
		{
			string name;
			char STDName[25];
			cout << "�������޸ĺ������ :  ";
			cin >> name;
			strcpy_s(STDName, name.c_str());
			this->stud.setName(STDName);
			return true;
		}
		
		case 2:
		{
			char gender;
			cout << "�������޸ĺ���Ա� :  ";
			gender = checkGender();
			this->stud.gender = gender;
			return true;
		}
		
		case 3: 
		{
			string phone;
			char STDPhone[25];
			
			cout << "�������޸ĺ�ĵ绰���� :  ";
			cin >> phone;
			
			strcpy_s(STDPhone, phone.c_str());
			this->stud.setPhone(STDPhone);

			return true;
		}
		
		case 4:
		{
			int pay;
			cout << "�������޸ĺ�Ķ��� :  ";
			cin >> pay;
			this->stud.downPayment = pay;
			return true;
		}
		
		case 5:
		{
			this->stud.sub = catchPurpose();			//��ȡ������Ŀ
		}
		
		case 6:
		{
			string requirement;
			cout << "�������޸ĺ����������" << endl;
			cout << "������ :  ";
			cin >> requirement;
			strcpy_s(this->stud.requirement, requirement.c_str());
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
Purpose OperateSTD::catchPurpose()

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

