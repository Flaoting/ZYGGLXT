#ifndef TABLE_H_
#define TABLE_H_
#include "Lesson.h"
#include "People.h"
#include "Purpose.h"
#include "FatherTable.h"
#include <queue>
#include "StoreTable.h"


class Table : public FatherTable 

    //ѧ���Ŀα���,�̳���FatherTable��ӵ����������Ϣ�ͱ�ͷ��Ϣ 
    //���ӿγ̽�������ֹʱ�䣬�Ϳγ���Ϣ

{

protected:

    int number;//�γ̽���

    Date startDate;
    Date endDate;

    priority_queue <Lesson> lessonTimeTable;

    //����һ�����ȶ��У��������
    

public:
    
    friend class StoreTable;

    //���캯��

    Table(People*, Date startDate, Date endDate,int num);
    //��ֹʱ�䣬�������
    
    Table(People*);
    //ֻ�����ˣ�Ȼ���������α��������
    
    Table(People*, Date startDate, int x,int num);
    //��ʼʱ�䣬�γ̽���
    
    Table();
    
    Table( StoreTable& );

    void translateFromStoreTable(StoreTable&);
    void display();//չʾһ�¿α�
    
    int getNum();

    

};
#endif 



