#ifndef TABLE_H_
#define TABLE_H_
#include "Date.h"
#include "People.h"
#include "Purpose.h"
#include <queue>
class Table {
protected:
    Purpose sub;//��Ŀ�������ʵ����Ҫ
    int number;//�γ̽���
    Date startDate;
    Date endDate;
    priority_queue <Date> classTable;//һ�����ȶ��У����ڴ������
    //char whoseTable;�α�����˭,??����ʲô����
    char name[20];//����������
    int ID;//�����ߵ�״Ԫ��Ψһʶ���

public:
    //���캯��
    Table(People*, Date startDate, Date endDate);//��ֹʱ�䣬�������
    Table(People*);//ֻ�����ˣ�Ȼ���������α��������
    Table(People*, Date startDate, int x);//��ʼʱ�䣬�γ̽���
    Table();
    void display();//չʾһ�¿α�

};
#endif 



