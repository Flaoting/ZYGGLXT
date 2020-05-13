#ifndef  STORETABLE_H_
#define STORETABLE_H_
#include "Table.h"
#include "Lesson.h"


class StoreTable 

	//��ΪTableʹ�����ȶ���ʵ�ֵģ����ܴ����ļ�
	//������͵Ķ������ڴ������ļ��� 
	//�������໥Ϊ��Ԫ�࣬���㻥���ʼ��

{
protected:

	char theOtherName[15];
	Lesson lessonTable[100];		//�α�����
	int num;				//�γ���

public:

	friend class Table;

	StoreTable();

	~StoreTable();

	StoreTable( Table  );

	StoreTable(const StoreTable& );

	string GetTheOtherName();

	void buildStoreTable( Table );

	int getNum();
	
	Lesson* getLessonTable();
	
	void setOtherName(string name);
};

#endif // ! STORETABLE_H_
