#ifndef  STDAFX_H_
#define STDAFX_H_
#include <string>
#include <map>
using namespace std;

bool checkBigPassword(string s);

bool saveAccount(string name, string password);

bool checkPassword(string input);

bool checkSaveAddress(string);

string getStringWithoutShow();

string TimeStampToStandard(int );

bool checkToContinue();

void operationCancled();

string translateNumToClassType(int);

#endif