#ifndef DATE_A_
#define DATE_A_
#include <iostream>
using namespace std;
class Date {
    //�����࣬����������,��Ҫ�����Ǽ�¼����������
private:
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
    bool operator >(const Date& obj);//���ش���С�ں͵���
    bool operator <(const Date& obj);
    bool operator ==(const Date& obj);

    int getYear();
    int getMonth();
    int getDay();
    bool Simplify();//���мӷ���򻯣����·ݺ�����ϼӣ�
};

#endif