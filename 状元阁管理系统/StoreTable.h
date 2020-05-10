#ifndef  STORETABLE_H_
#define STORETABLE_H_
#include "Table.h"
#include "Lesson.h"


class StoreTable 

	//因为Table使用优先队列实现的，不能存入文件
	//这个类型的对象用于储存在文件中 
	//这两个类互为友元类，方便互相初始化

{
protected:

	Lesson lessonTable[100];		//课表数组
	int num;				//课程数

public:
	friend class Table;

	StoreTable();

	~StoreTable();

	StoreTable( Table & );

	StoreTable(const StoreTable& );



	void buildStoreTable( Table );
	int getNum();
	Lesson* getLessonTable();
	
};

#endif // ! STORETABLE_H_
