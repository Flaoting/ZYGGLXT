#include "MainEntrance.h"
#include <windows.h>
#include <tchar.h>
#include <assert.h>

MainEntrance :: MainEntrance():Hander()
{
	commender = 0;
}

MainEntrance::~MainEntrance(){}

void MainEntrance::ShowThe_First()
{
	FeasibleCmd feasible;
	
	PremaryMenu* PM;
	PM = new PremaryMenu;
	PM->display();
	delete PM;
	PM = NULL;
}

void MainEntrance::ShowPre_Login() 
{
	bool inCard=false;
	LoginMenu  LM;
	do{
		if (LM.checkInDisplay())
		{
			return;
		}
		cout << "��¼Ȩ����֤ʧ�ܣ��Ƿ��ٴ���֤��" << endl;
		inCard = checkToContinue();
	} while (inCard);

	if (!inCard) 
	{
		cout << "��¼ϵͳʧ�ܣ������µ�¼ !!!" << endl;
		cout << "�����˳�ϵͳ����ӭ�����ٴ�ʹ��" << endl;
		system("pause");
		exit(0);
	}
}

int  MainEntrance::ShowMain_Menu() 
{
	MainMenu mainMenu;
	mainMenu.display();
	
	this->commender=mainMenu.getCommend();
	return this->commender;
}

bool MainEntrance::DealFirt_Comd(int Comd ) 
{

	/*******************************************************************************

		�ȼ���¼״̬�����û�е�¼������ѡ�������ҪȨ�޵Ĺ��ܣ������ѵ�¼
		���Ѿ���¼����ֱ��ѡ����


	********************************************************************************/

	if (Comd == 0)
	{
		return false;
	}

	if (Comd == 9) 
	{
		cout << "״Ԫ�������� : �����������ڲ�����ͨ�� " << endl << endl;
		return false;
	}

	if (!this->Hander.getStatus()&&Comd !=4&&Comd!=6&&Comd!=7&&Comd!=8)
	{
		cout << "����δ��ô���ܵ�Ȩ��,�����Ƚ��е�¼����ʹ�ô����!" << endl;
		cout << "�Ƿ����ڽ��е�¼?";
		
		if (!checkToContinue()) 
		{
			operationCancled();
			return 0;
		}

		Comd = 8;
	}

	switch (Comd) 
	{
		case 1:
		{
			cout << "״Ԫ�������� : ������ʹ��ѧԱ�������� " << endl<<endl;
			system("pause");
			this->Hander.addSTD();//
			cout << "��  ��  ��  ��" << endl;
			break;

		}
		case 2: 
		{
			cout << "״Ԫ�������� : ������ʹ��ѧԱ���ι��� " << endl<<endl;
			system("pause");
			this->Hander.addTAB();
			cout << "��  ��  ��  ��" << endl;
			break;
		}
		case 3: 
		{
			cout << "״Ԫ�������� : ������ʹ��ѧԱ���ι��� " << endl << endl;;
			system("pause");
			this->Hander.addToll();
			cout << "��  ��  ��  ��" << endl;
			break;
		}
		case 4: 
		{
			int temp = 0;
			string name;
			
			OperateTable operateTable;
			operateTable.clearHidenTable();

			while (temp <= 0 || temp > 3)
			{
				cout << "1. ��ѯ��ʦ�Ŀα� " << endl;
				cout << "2. ��ѯѧ���Ŀα� " << endl;
				cout << "��������ѡ���� :  ";
				cin >> temp;
			}

			if (temp == 1)
			{
				cout << "�������ʦ���� :  ";
			}
			else if (temp == 2)
			{
				cout << "������ѧ������ :  ";
			}
			
			cin >> name;
			int cnt = 1;
			if (!operateTable.readPreFile(name, 1))
			{
				cout << "��ȡ " << name << " �Ŀα�ʧ�ܣ�" << endl;
				return 0;
			}

			do
			{
				Table table;
				table = operateTable.getTable();
				if (temp == 1)
				{
					table.displayTEA();
				}
				else if (temp == 2)
				{
					table.displaySTD();
				}
				
				cnt++;
				cout << "�Ƿ�鿴 " << name << " ����һ���α�";
				if (!checkToContinue())
				{
					cout << "��ѯ�α����!  " << endl;
					break;
				}

			} while (operateTable.readPreFile(name, cnt));

			cout << "��ѯ�α����!  " << endl;
			break;
		}

		case 5: 
		{
			cout << "״Ԫ�������� : ������ʹ���޸Ŀα��� " << endl << endl;
			this->Hander.setTable();
			cout << "�� �� ��  ��  ��  ��" << endl;
			break;
		}
		case 6: 
		{
			int temp = 0;
			string name;
			OperateTable operateTable;

			operateTable.clearHidenTable();
			temp = 0;

			while (temp <= 0 || temp > 2 )
			{
				cout << "1. ���ɽ�ʦ�Ŀ��ӻ��α� " << endl;
				cout << "2. ��ѯѧ���Ŀ��ӻ��α� " << endl;
				cout << "��������ѡ���� :  ";
				cin >> temp;
			}
			if (temp == 1) 
			{
				cout << "�������ʦ���� :  ";
			}
			else if (temp == 2)
			{
				cout << "������ѧ������ :  ";
			}
			cin >> name;

			int cnt = 1;
			
			if (!operateTable.readPreFile(name, 1))
			{
				cout << "��ȡ " << name << " �Ŀα�ʧ�ܣ�" << endl;
				return 0;
			}

			bool flag = false;

			do
			{
				if (temp == 1)
				{
					operateTable.transformTTToCSV();
					if (!flag) 
					{
						flag = true;
						cout << "���� " << name << " �Ŀ��ӻ��α�ɹ���" << endl;
						cout << "��ǰ��·��" << operateTable.getAddress() << "�²鿴" << endl << endl;
					}
					
				}
				else if (temp == 2) 
				{
					operateTable.transformSTToCSV();
					if (!flag)
					{
						flag = true;
						cout << "���� " << name << " �Ŀ��ӻ��α�ɹ���" << endl;
						cout << "��ǰ��·��" << operateTable.getAddress() << "�²鿴" << endl << endl;
					}
				}
				cnt++;

			} while (operateTable.readPreFile(name, cnt));

			break;
		}

		case 7: 
		{
			cout << "�˲��ֹ��ܽ��ڽ�ʦ�������Լ��ĸ��˽��ܺ�����" << endl;
			cout << "������״Ԫ��������վ ...";
			if (!checkToContinue())
			{
				operationCancled();
				return 0;
			}
			//��һ�����õ���վ
			ShellExecute(NULL, _T("open"), _T("explorer.exe"), _T("https://github.com/Flaoting/ZYGGLXT"), NULL, SW_SHOW);
			
			break;
		}

		case 8: 
		{
			int i = 0;
			do 
			{
				i++;
				if (i > 3)
				{
					break;
				}
				cout << "���������й���Ա��¼,��ע����Χ������ȫ!" << endl;
				if (!checkToContinue())
				{
					operationCancled();
					return 0;
				}
				string name, SSH;

				cout << "���������Ա���� :  ";
				cin >> name;
				cout << "���������Ա���� :  ";
				SSH = getStringWithoutShow();
				if (Hander.LoginManager(name, SSH)) 
				{
					return 1; //��¼�ɹ��ͷ���
				}
				cout << "�Ƿ������¼?";

			} while (checkToContinue());
			break;
		}

	}
	return 1;
}


int  MainEntrance::ShowInde_Menu() 
{
	InsideMenu insideMenu;
	insideMenu.display();

	this->commender = insideMenu.getCommend();
	return this->commender;
}


bool MainEntrance::DealSecn_Comd(int Comd)
{

	if (Comd == 12) 
	{
		if (this->Hander.checkSSH())
		{
			cout << "״Ԫ�������� : ������ʹ�ý������Ա����ҳ�� " << endl << endl;
			return true;
		}
		return false;
	}

	if (Comd == 0) 
	{
		return false;
	}

	if (!this->Hander.getStatus() &&Comd!=1&& Comd != 2 && Comd != 3 && Comd != 5 && Comd != 6&& Comd != 7&&Comd != 9&& Comd != 10)
	{
		cout << "����δ��ô���ܵ�Ȩ��,�����Ƚ��е�¼����ʹ�ô����!" << endl;
		cout << "����Ϊ��������һ����" << endl;
		return false;
	}
	
	switch (Comd) 
	{
		
		case 1:
		{
			int temp = 0;
			
			cout << "״Ԫ�������� : ������ʹ�ý���ע�����Աҳ�� " << endl << endl;
			
			while (temp <= 0 || temp > 2) 
			{
				cout << "1. ע���µĹ���Ա " << endl;
				cout << "2. �޸ĵ�ǰ��¼����Ա��Կ" << endl;
				cout << "��ѡ����Ҫʹ�õĹ��� :  ";
				cin >> temp;
			}

			if (temp == 1) 
			{
				RegisterManagerMenu RMM;
				RMM.display();
				cout << "�� �� �� �� Ա �� �� !!!" << endl;
			}

			else if (temp == 2)
			{
				this->Hander.changeMAGSSH();
				
			}
			break;
		}

		case 2:
		{
		
			OperateTEA operateTEA;
			Teacher test;
			
			if (!operateTEA.readPreFile()) 
			{
				return 0;
			}
			test = operateTEA.getTeacher();
			
			test.display();
			cout << "�� ʦ " << test.getName() << " �� Ϣ չ ʾ �� ��" << endl;

			break;
		
		}

		case 3: 
		{
			OperateSTD operateSTD;
			Student std;
			
			if (!operateSTD.readPreFile()) 
			{
				return 0;
			}
			
			std = operateSTD.getStudent();
			std.display();
			cout << "ѧ �� " << std.getName() << " �� Ϣ չ ʾ �� ��" << endl;
			break;
		}

		case 4:
		{
			OperateTEA operateTEA;
			operateTEA.getInfoFromScreen();
			operateTEA.saveThisFile();
			cout << "�� �� �� ʦ �� Ϣ �� �� " << endl;
			break;
		}

		case 5: 
		{
			cout << "״Ԫ�������� : ������ʹ���޸Ľ�ʦ��Ϣ�Ĺ��� " << endl << endl;
			OperateTEA operateTEA;
			string name;
			do 
			{
				cout << "������Ҫ���Ľ�ʦ������ :  ";
				cin >> name;
				
				operateTEA.updateTeacherInfo(name);

				cout << "�Ƿ�Ҫ�����޸�������ʦ����Ϣ��  ";

			} while (checkToContinue());

			break;
		}

		case 6: 
		{
			cout << "״Ԫ�������� : ������ʹ���޸�ѧ����Ϣ�Ĺ��� " << endl << endl;
			OperateSTD operateSTD;
			string name;
			do
			{
				cout << "������Ҫ����ѧ�������� :  ";
				cin >> name;

				operateSTD.updateStudentInfo(name);

				cout << "�Ƿ�Ҫ�����޸�����ѧ������Ϣ��  ";

			} while (checkToContinue());
			break;
		}

		case 7:
		{
			OperateTEA operateTEA;
			string name;
			Teacher tea;
			cout << "״Ԫ��������  ������ʹ�ò�ѯ��ʦ���ʱ�Ĺ���!!!" << endl;
			do 
			{

				cout << "������Ҫ��ѯ�Ľ�ʦ���� :  ";
				cin >> name;
				if (!operateTEA.readPreFile(name)) 
				{
					cout << "��ʦ " << name << "�ĸ�����Ϣ����ʧ��" << endl;
				}
				else 
				{

					tea = operateTEA.getTeacher();
					SalaryTable salaryTable(tea);
					int temo=0;
					while (temo <= 0 || temo > 2) 
					{
						cout << endl;
						cout << "1. չʾ���ʱ���ϸ��Ϣ" << endl;
						cout << "2. չʾ���ʱ��Ҫ��Ϣ" << endl;
						cout << "��ѡ����Ҫʹ�õĹ��� :  ";
						cin >> temo;
					}
				
					if(temo==1)
					{
						salaryTable.showAllTable();
					}

					else if (temo == 2)
					{
					salaryTable.briefShow();
					}
					cout << "��ʦ "<<name<<" �Ĺ��ʱ�չʾ���"<<endl;
				}
				cout << "�Ƿ�Ҫ������ѯ������ʦ�Ĺ��ʱ�";
			} while (checkToContinue());
			break;
		}

		case 8: 
		{
			this->Hander.checkSSH();
			do 
			{
				this->Hander.addVio();
				cout << "�� ѧ �� �� �� ¼ �� �� " << endl;
				cout << "�Ƿ������ӽ�ѧ�¹ʣ�  ";
			} while (checkToContinue());
			break;
		}

		case 9: 
		{
			cout << "�γ̵������� :  " << endl;
			cout << setw(10) <<"�γ�����"
				<< setw(5) << "�γ̵���" << setw(10) << "Ԫ/Сʱ/��" << endl;
			ConClassPrice CCP;
			map<int, ClassPrice> Price = CCP.getMapFromCon();

			for (int i = 1; i <= 6; i++) 
			{
				auto it = Price.find(i);

				ClassPrice CP(-1, -1, -1, "test");

				if (it != Price.end())
				{
					CP = (*it).second;
					cout << setw(10) << translateNumToClassType(i)
						<<setw(5) << CP.getInPrice()<<setw(10) << "Ԫ/Сʱ/��" << endl;
				}
			}
			break;
		}

		case 10:
		{
			do 
			{
			this->Hander.addRun();
			
			cout << "�Ƿ���������ˮ�� ?";

			} while (checkToContinue());
			break;
		}

		case 11:
		{
			cout << "״Ԫ�������� : ������ʹ�ò�ѯϵͳ��¼�Ĺ���" << endl;
			cout << "״Ԫ�������� : �������Ҫ��֤����Ա��Կ  " << endl;

			while (!this->Hander.checkSSH())
			{
				cout << "�� Կ �� ֤ ʧ �� " ;
				cout << "�� �� �� �� �� �� ��";
				if (!checkToContinue()) 
				{
					operationCancled();
					return 0;
				}
			}

			int temp = 0, smaller = 1;
			int start = 1, end = 20;

			do 
			{
				
				do
				{
					cout << "1. ��ѯһ����Χ�ڵ�������¼" << endl;
					cout << "2. ��ѯһ����Χ����ˮ��" << endl;
					cout << "3. ��ѯһ����Χ�ڽ�ѧ�¹�" << endl;
					cout << "4. ��ѯ����������¼" << endl;
					cout << "5. ��ѯ������ˮ��" << endl;
					cout << "6. ��ѯ���н�ѧ�¹�" << endl;
					cout << "��ѡ����Ҫʹ�õĹ��� :  ";
					cin >> temp;
				} while (temp <= 0 || temp > 6);


				if (temp == 1 || temp == 2 || temp == 3)
				{
					cout << "�������¼�Ӷ�������ʼ :  ";
					cin >> start;
					cout << "�������¼������������ :  ";
					cin >> end;
				}

				cout << "�Ƿ�ı�Ĭ�ϵ���ʾģʽ(���ģʽ)";
				if (checkToContinue())
				{
					cout << "1. ���ģʽ " << endl;
					cout << "2. ��ϸģʽ " << endl;
					cout << "��ѡ����ʾģʽ :  ";
					cin >> smaller;
				}
				
				switch (temp)
				{
					case 1:
					{
						cout << "����չʾ���еĽ��׼�¼ " << endl;
						
						for (int i = start; i <= end; i++)
						{
							this->Hander.showOneToll(i, smaller);
						}

						break;
					}

					case 2:
					{
						cout << "����չʾ���е���ˮ�˼�¼ " << endl;
						
						for (int i = start; i <= end; i++)
						{
							this->Hander.showOneRun(i, smaller);
						}
						
						break;
					}
					case 3:
					{

						cout << "����չʾ���еĽ�ѧ�¹ʼ�¼ " << endl;

						for (int i = start; i <= end; i++)
						{
							this->Hander.showOneVio(i);
						}

						break;
					}

					case 4:
					{
						this->Hander.showAllToll(smaller);
						cout << "����������¼չʾ���" << endl;
						break;
					}

					case 5:
					{
						this->Hander.showAllRun(smaller);
						cout << "������ˮ��¼չʾ���" << endl;
						break;
					}

					case 6:
					{
						this->Hander.showAllVio();
						cout << "���н�ѧ�¹ʼ�¼չʾ���" << endl;
						break;
					}
				}

			} while (checkToContinue());
		}
	}
}

int  MainEntrance::ShowMang_Menu() 
{
	if (!this->Hander.getStatus()) 
	{
		cout << "����δ��ô���ܵ�Ȩ��,�����Ƚ��е�¼����ʹ�ô����!" << endl;
		cout << "����Ϊ��������һ����" << endl;
		return 0;
	}

	system("cls");
	cout << "*************************************************************************" << endl << endl << endl;
	cout << "\t\t״Ԫ�����ϵͳ" << endl << endl << endl;
	cout << "\t1. ��ѯ���н�ʦ��Ϣ  2. �޸��ļ�����λ��   3. һ��ͳ��������   " << endl << endl;
	cout << "\t4. ��ѯ����ѧ����Ϣ  5. ��ʼ���γ̵���     6.�޸Ŀγ̵��� " << endl << endl;
	cout << endl<<endl;
	cout << "*************************************************************************" << endl << endl;
	
	int com=0;
	
	do 
	{
		cout << "��������Ҫʹ�ù��ܵı�� :  ";
		cin >> com;
	} while (com < 0 || com > 6);


	this->commender = com;
	
	if (com == 0)
	{
		return com;
	}
	
	switch (com) 
	{
		case 1: 
		{
			cout << "����չʾ���н�ʦ�ĸ�����Ϣ" << endl;

			this->Hander.showAllTEA();
			cout << "չ ʾ �� �� " << endl;
			break;

		}
		case 2: 
		{

			BaseFile BF;
			cout << "�������޸��ļ��Ĵ���λ��" << endl;
			BF.changeSaveAddress();
			cout << "�� �� �� ��" << endl;
			break;
		}

		case 3: 
		{
			int cnt = 0,tem = 0;
			while(!this->Hander.checkSSH()&&cnt<3) 
			{
				cnt++;
				cout << "�����֤ʧ�ܣ��Ƿ��������" << endl;
				if (!checkToContinue()) 
				{
					operationCancled();
					return -1;
				}

			}

			cout << "�����������˵���չʾ.... " << endl;
			cout << "�Ƿ�Ҫ��Ҫ��չʾÿ�ʽ��׼�¼?";
			if (checkToContinue()) 
			{
				tem = 1;
			}
			tem=(int)this->Hander.checkSummery(tem);

			cout << "����֤���׼�¼�������������� " << tem << " Ԫ" << endl;
			system("pause");
			break;
		}
		case 4: 
		{
			cout << "����չʾ����ѧ���ĸ�����Ϣ" << endl;

			this->Hander.shouwAllSTD();
			break;
		}
		case 5: 
		{
			cout << "״Ԫ����ʾ������������ʼ���γ̵��ۣ���ע�⣬���е�λ���� Ԫ/Сʱ/��" << endl;
			
			ConClassPrice CCP;
			CCP.initClassPrice();
			cout << "�� ʼ �� �� �� " << endl;
			break;
		}


		case 6: 
		{
			cout << "״Ԫ����ʾ�����������޸Ŀγ̵��ۣ���ע�⣬���е�λ���� Ԫ/Сʱ/��" << endl;

			ConClassPrice CCP;
			CCP.initClassPrice();
			cout << " �� �� �� �� " << endl;
			break;
		}

	}
	return 1;

}





