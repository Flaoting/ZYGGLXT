#include "RelationMap.h"
#include <iostream>
#include <string.h>
using namespace std;

RelationMap::RelationMap() 
{
	memset(MAP, false, sizeof(MAP));

	for (int i = 1; i <= 200; i++)
	{
		for (int j = 1; j <= 200; j++)
		{
			MAP[i][j] = false;
		}
	}
	//bool���Զ�Ĭ��Ϊfalse
	//�������
}

RelationMap::~RelationMap()
{
	//������
}

RelationMap::RelationMap(const RelationMap& obj) 

{
	memset(MAP, false, sizeof(MAP));

	for (int i = 1; i <= 200; i++) 
	{
		for (int j = 1; j <= 200; j++) 
		{
			MAP[i][j] = obj.MAP[i][j];
		}
	}
}

RelationMap RelationMap::operator =(const RelationMap& obj) 
{
	for (int i = 1; i <= 200; i++)
	{
		for (int j = 1; j <= 200; j++)
		{
			MAP[i][j] = obj.MAP[i][j];
		}
	}
	return *this;
}

void RelationMap::display()
{
	for (int i = 1; i <= 200; i++)
	{
		for (int j = 1; j <= 200; j++)
		{
			cout << MAP[i][j];
		}
		cout << endl;
	}
}
 