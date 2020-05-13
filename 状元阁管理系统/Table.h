/******************************************************************
                 ����Table��
    
    �α���,�̳���FatherTable��ӵ����������Ϣ�ͱ�ͷ��Ϣ 
    ���ӿγ̽�������ֹʱ�䣬�Ϳγ���Ϣ����ѧ�������

    ���ӽ�ѧ���������ԭ���ǿ��Լ�¼ʦ���Ľ�ѧ��ϵ��Ҳ����ֱ������
    ���ݿα��ֱ���д��棬�����˵�������������

*******************************************************************/
#ifndef TABLE_H_
#define TABLE_H_
#include "Lesson.h"
#include "People.h"
#include "Purpose.h"
#include "FatherTable.h"
#include <queue>
#include "StoreTable.h"


class Table : public FatherTable 

{

protected:

    char theOtherName[15];

    int number;//�γ̽���

    Date startDate;
    Date endDate;

    priority_queue <Lesson> lessonTimeTable;

    //����һ�����ȶ��У��������
    
    
public:
    
    friend class StoreTable;

    //���캯��

    Table(People*, Date startDate, Date endDate,int num, char* name);
    //��ֹʱ�䣬�������
    
    Table(People*, char* name);
    //ֻ�����ˣ�Ȼ���������α��������
    
    Table(People*, Date startDate, int x,int num, char* name);
    //��ʼʱ�䣬�γ̽���
    
    Table();
    
    Table( StoreTable& );

    void ReviseTeam();

    void translateFromStoreTable(StoreTable&);

    void displaySTD();  //չʾѧ���α�

    void displayTEA();  //չʾ��ʦ�α�
    
    int getNum();
    
};
#endif 



