#ifndef PEOPLE_H_
#define PEOPLE_H_
#include "People.h"
#include <iostream>
using namespace std;
class People
{//����һ��������
private:
    
    static int numID;//��̬�ģ�һ����һ��ID

protected:
    
    char name[15];//����
    char gender;//�Ա�
    char phone[20];//�绰����
    const int ID;//״Ԫ��Ψһʶ���,���ɸ���

public:
    
    People(char* name, char sex, char* phone);
    People(char*name, char* phone,char sex='.');
    People(char* name);
    People(char* name, char sex);
    People(const People&);

    static int checkNumID();
    
    void setName(char *);
    void setGender(char sex);
    void setPhone(char *);
    void display();
    //virtual void showInScreen() = 0;
    
};
#endif