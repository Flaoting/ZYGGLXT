#ifndef DATE_A_
#define DATE_A_
#include <iostream>
#include <iomanip>
using namespace std;


class Date {
    //�����࣬����������,��Ҫ�����Ǽ�¼����������

protected:
    int year;
    int month;
    int day;

public:

    Date();
    Date(int year, int month, int day);//����ͨͨ�Ĺ��캯��
    Date(int month, int day);//���ع��캯����ȱʡ��Ĺ���
    Date(const Date& obj);//�������캯��

    void display();//��ʾһ��
    
    int operator - (const Date& obj);//����+ - = ����������������������ڼ�������������

    Date operator + (int x);

    Date operator =(const Date& obj);//��ֵ�ţ���λ��ֵ

    bool operator >(const Date& obj)const;//���ش���С�ں͵���

    bool operator <(const Date& obj)const;

    bool operator ==(const Date& obj)const;

    bool operator <= (const Date& obj)const;

    bool operator >=(const Date& obj)const;

    Date operator ++ (int);//���غ���++

    Date operator ++ ();//����ǰ��++

    Date operator --(int );//���غ���--

    Date operator --();//����ǰ��--

    int getYear();

    int getMonth();

    int getDay();

    bool Simplify();//���мӷ���򻯣����·ݺ�����ϼӣ�

};

#endif