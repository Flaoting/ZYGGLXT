#ifndef  STDAFX_H_
#define STDAFX_H_
#include <string>
#include <map>
using namespace std;


								
bool checkBigPassword(string s);			//����ϴ���Ȩ��

bool saveAccount(string name, string password); //

bool checkPassword(string input);

bool checkSaveAddress(string);

string getStringWithoutShow();			//����ʾ��Ļ��ȡ�ַ���

string TimeStampToStandard(int );		//��ʱ���ת��Ϊ��׼ʱ��

bool checkToContinue();					//ѯ���Ƿ����

void operationCancled();				//����ȡ��

string translateNumToClassType(int);	//����תΪ�γ�����

char checkGender();						//��ȡ�Ա�

string trnaslateVioCode(int, int);		//Υ�����ת��Ϊ��������

#endif


