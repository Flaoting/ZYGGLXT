#ifndef TABLE_H_
#define TABLE_H_
#include "Lesson.h"
#include "People.h"
#include "Purpose.h"
#include <queue>



class Table 

    //�α��࣬ÿ���α��¼ѧ����ID �� ���� 

{

protected:

    int number;//�γ̽���

    Date startDate;

    Date endDate;

    priority_queue <Lesson> lessonTimeTable;

    //����һ�����ȶ��У��������
    
    char name[20];//����������
    
    int ID;//�����ߵ�״Ԫ��Ψһʶ���

public:
    
    //���캯��
    Table(People*, Date startDate, Date endDate,int num);//��ֹʱ�䣬�������
    
    Table(People*);//ֻ�����ˣ�Ȼ���������α��������
    
    Table(People*, Date startDate, int x,int num);//��ʼʱ�䣬�γ̽���
    
    Table();
    
    void display();//չʾһ�¿α�

};
#endif 



