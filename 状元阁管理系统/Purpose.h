#ifndef PURPOSE_H_
#define PURPOSE_H_
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Purpose

{

private:

	char subject[7][10];
	int sum;

	//��vector�泵�ķ�ʽ�ĳ���string����ͼ�¼�����ı���

public:
	
	Purpose( vector <string>  );//����������
	
	Purpose();//�޲�������
	
	Purpose(const Purpose& obj);//��������
	

	~Purpose();//����
	


	void display();



	Purpose operator=(const Purpose&);


};

#endif