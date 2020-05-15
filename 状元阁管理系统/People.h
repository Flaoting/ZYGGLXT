#ifndef PEOPLE_H_
#define PEOPLE_H_

//#include "OperateSTD.h"

class People

    //����һ��������

{
private:
    
    static int numID;//��̬�ģ�һ����һ��ID

protected:
    
    char name[30];//����
    char gender;//�Ա�
    char phone[20];//�绰����
    int ID;//״Ԫ��Ψһʶ���,�����ļ�ʱ����и���

public:
    
    People(char* name, char sex, char* phone);
    People(char*name, char* phone,char sex='F');
    People(char* name);
    People(char* name, char sex);
    People(const People&);
    
    People();
   
    
    
    virtual ~People(){}
    
    
    People operator =(const People&);
    
    static int checkNumID();
    
    void setName(char *);
    void setGender(char sex);
    void setPhone(char *);
    void display();
    char* getName();
    char getGender();
    char* getPhone();
    int getID();

   
    friend class OperateSTD;
    friend class OperateTEA;

};
#endif