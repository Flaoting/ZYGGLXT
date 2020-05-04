#ifndef TABLE_H_
#define TABLE_H_
#include "Lesson.h"
#include "People.h"
#include "Purpose.h"
#include "FatherTable.h"
#include <queue>



class Table : public FatherTable 

    //学生的课表类,继承了FatherTable，拥有所有者信息和表头信息 
    //增加课程节数，起止时间，和课程信息
{

protected:

    int number;//课程节数

    Date startDate;

    Date endDate;

    priority_queue <Lesson> lessonTimeTable;

    //这是一个优先队列，存放日期
    

public:
    
    //构造函数
    Table(People*, Date startDate, Date endDate,int num);//起止时间，推入队列
    
    Table(People*);//只传入人，然后进行输入课表，推入队列
    
    Table(People*, Date startDate, int x,int num);//开始时间，课程节数
    
    Table();
    
    void display();//展示一下课表


};
#endif 



