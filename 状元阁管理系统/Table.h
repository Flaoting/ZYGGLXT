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
#include "stdafx.h"
#include "StoreTable.h"


class Table : public FatherTable 

{

protected:

    //����һ�����ȶ��У���ſγ�
    priority_queue <Lesson> lessonTimeTable;
    
    Date startDate;

    Date endDate;
    
    int number;//�γ̽���

    char theOtherName[30];//��Խ�ʦ����

    int classType;//��¼�γ�����
    
    int tableID;

public:

    
    friend class OperateTable;
    friend class StoreTable;

    //���캯��
    Table();

    Table(People*, Date startDate, Date endDate,int num, char* name,int Type);
    //��ֹʱ�䣬�������
    
    Table(People*, char* name, int Type);
    //ֻ�����ˣ�Ȼ���������α��������
    
    Table(People*, Date startDate, int x,int num, char* name,int Type);
    //��ʼʱ�䣬�γ̽���

    Table(const Table&);

    Table( StoreTable& );
    
    Table operator =(const Table&);
    

    void ReviseTeam();

    void ReviseTeamToSTD();

    void translateFromStoreTable(StoreTable&);

    void displaySTD();  //չʾѧ���α�

    void displayTEA();  //չʾ��ʦ�α�
    
    void shortShowSTD(); //���չʾѧ����ͷ��Ϣ
    
    void shortShowTEA(); //���չʾ��ʦ��ͷ��Ϣ

    void shortShortShowTEA(); //�����չʾ��Ϣ

    void clearThisTable(); //��յ�ǰ�α��ڵ�����

    int getNum();// ��ÿγ̽���

    string getSelfName();//��ñ������

    int getClassType();//������ʹ���

    string getTheOtherName();//��ö�Ӧ��Ա������

    int getTableID();//��ÿα�ı��

};
#endif 



