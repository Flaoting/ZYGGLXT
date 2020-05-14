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

	char selfName[50];
	char theOtherName[15];
	
	Lesson lessonTable[100];			//�α�����
	
	int num;							//�γ���
	int classType;

public:

	friend class Table;
	
	~StoreTable();

	StoreTable();

	StoreTable(const StoreTable& );

	StoreTable( Table  );

	void buildStoreTable( Table );
	
	void setOtherName(string name);

	int getNum();

	Lesson* getLessonTable();

	string GetTheOtherName();

	int getClassType();

};

#endif // ! STORETABLE_H_
