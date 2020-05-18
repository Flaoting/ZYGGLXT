#ifndef  STORETABLE_H_
#define STORETABLE_H_
#include "Table.h"
#include "Lesson.h"
#include "TabNum.h"

class StoreTable 

	//��ΪTableʹ�����ȶ���ʵ�ֵģ����ܴ����ļ�
	//������͵Ķ������ڴ������ļ��� 
	//�������໥Ϊ��Ԫ�࣬���㻥���ʼ��

{
protected:

	char ownerName[20];			//����������
	int ownerID;				//������ID

	char selfName[50];
	char theOtherName[30];
	
	Lesson lessonTable[100];			//�α�����
	
	int num;							//�γ���
	int classType;

	int tableID;						//�α���

	
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

	void setTableID();					//���Ŀα�ı�ţ��ڴ����ļ���ʱ�����

	void setTableID( const  StoreTable &);
};

#endif // ! STORETABLE_H_
