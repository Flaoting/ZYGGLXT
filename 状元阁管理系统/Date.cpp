#include "Date.h"

//������������߻��õ��ĺ���

int monthHowDays(int year, int month);
bool isRunYear(int x);



Date::Date(int year, int month, int day) 

{
    this->year = year;
    this->month = month;
    this->day = day;
    Simplify();
}

Date::Date(int month, int day) 
{
    this->month = month;
    this->day = day;
    this->year = 2020;
    Simplify();
}

Date::Date()
{
    year = 2020;
    month = 1;
    day = 1;
}

Date::Date(const Date& obj) 
{
    year = obj.year;
    month = obj.month;
    day = obj.day;
}



void Date::display() 
{
    cout << "���ڣ� " << year;
    cout << setw(4) << month;
    cout << setw(4) << day<<"   ";
}



int Date :: operator -(const Date& obj)

//����Date�е������������զ�����ˣ��ȵȵ�

{

    if (*this < obj) return -1;//���ж����ڴ�С��Ҫ��С�ļ�ȥ��ľͷ���-1;

    int ans = 0;//��¼�ж�����

    for (int i = obj.year; i <= year; i++) //ѭ����
    {
        if (i == obj.year)
        {// ��һ�ν���ѭѭ����Ļ�
            for (int j = obj.month; j <= 12; j++)//ѭ���·�
            {
                if (j == obj.month && j < month)
                {//ѭ���ĵ�һ���£�����û�����������·�
                    for (int k = obj.day; k <= monthHowDays(i, j); k++)
                        ans++;
                    //��һ�쿪ʼ���ӵ��µ�
                }
                else if (i == year && j == obj.month && j == month)
                {//ͬһ�����ڵĻ�,Ŀ����
                    for (int k = obj.day; k <= this->day; k++)
                        ans++;
                    //���ӵ��յ�
                    return ans;
                }
                else if (j < month)
                {//������j++ ��ѭ�������¸��£�����û��Ŀ����
                    for (int k = 1; k <= monthHowDays(i, j); k++)
                        ans++;
                    // ��һ�żӵ��µ�
                }
                else if (i == year && j == month && j != obj.month) {
                    //��Ŀ����,������j++������Ҫ�ӵ����һ���£�
                    for (int k = 1; k <= this->day; k++)
                        ans++;
                    return ans;
                    //��һ�żӵ�Ŀ������
                }
                else if (j == obj.month) {
                    for (int k = obj.day; k <= monthHowDays(i, j); k++)
                        ans++;
                }
                else
                {
                    for (int k = 1; k <= monthHowDays(i, j); k++)
                        ans++;
                }
            }
        }

        else if (i != obj.year)
        {
            //���п������ʱ
            for (int j = 1; j <= 12; j++)//ѭ���·�
            {
                if (j == month && i == year)
                {//����Ŀ���·�
                    for (int k = 1; k <= this->day; k++)
                        ans++;
                    return ans;
                    //���ӵ��յ�
                }
                else
                {
                    for (int k = 1; k <= monthHowDays(i, j); k++)
                        ans++;
                }
            }
        }
    }

    //ȫ��������
    return ans;
}


Date Date::operator +(int x) {//x�Ƕ��ٽڿΣ�����Ҫ--
    x--;
    day += x;

    while (Simplify());//����������ֱ����ȫ��

    return *this;
}


Date Date::operator =(const Date& obj) {
    year = obj.year;
    month = obj.month;
    day = obj.day;
    return *this;
}



bool Date ::operator >(const Date& obj)const {
    int a = year - obj.year;
    if (a > 0)return 1;
    if (a < 0)return 0;
    if (a == 0) {
        int b = month - obj.month;
        if (b > 0)return 1;
        if (b < 0)return 0;
        if (b == 0) {
            int c = day - obj.day;
            if (c > 0)return 1;
            if (c < 0)return 0;
            if (c == 0)return 0;
        }
    }
    return 0;

}

bool Date ::operator ==(const Date& obj)const 

{

    if (year == obj.year && month == obj.month && day == obj.day) 
    {
        return 1;
    }
       
    return 0;
}

bool Date ::operator <(const Date& obj)const {
    int a = year - obj.year;
    if (a > 0)return 0;
    if (a < 0)return 1;
    if (a == 0) {
        int b = month - obj.month;
        if (b > 0)return 0;
        if (b < 0)return 1;
        if (b == 0) {
            int c = day - obj.day;
            if (c > 0)return 0;
            if (c < 0)return 1;
            if (c == 0)return 0;
        }
    }
    return 0;
}

bool Date ::operator<=(const Date& obj)const 

{

    if (*this == obj) 
    {
        return 1;
    }

    if (*this < obj) 
    {
        return 1;
    }

    return 0;

}

bool Date ::operator>=(const Date& obj)const

{
    if (*this == obj)
    {
        return 1;
    }

    if (*this > obj)
    {
        return 1;
    }

    return 0;

}



Date Date::operator++()

//����ǰ��++

{
    this->day++;
    Simplify();
    return *this;

}

Date Date::operator++(int) 
//���غ���++
{
    Date temp(*this);
    this->day++;
    Simplify();
    return temp;
}

Date Date::operator--(int) 

//���غ���--

{
    Date temp(*this);
    this->day--;
    Simplify();
    return temp;

}

Date Date::operator--()

//����ǰ��--

{
    this->day--;
    Simplify();
    return *this;
}




int Date::getYear() { return year; }
int Date::getMonth() { return month; }
int Date::getDay() { return day; }



bool Date::Simplify() {
    if (month > 12)
    {
        year += 1;
        month -= 12;
    }
    int a = monthHowDays(year, month);//��ȡ������м���
    if (day > a)
    {
        day -= a;
        month += 1;
    }
    a = monthHowDays(year, month);
    if (day > a || month > 12)return 1;//û����ȫ��
    return 0;//��ȫ����
}



bool isRunYear(int x) {
    //�ж��Ƿ�Ϊ����ĺ������Ƿ���1�����Ƿ���0��
    if (x % 4 != 0) return 0;
    else if (x % 4 == 0) {
        if (x % 100 == 0 && x % 400 != 0) {
            return 0;
        }
        else return 1;
    }
}



int monthHowDays(int year, int month) {
    //�ж�������м���
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else if (month == 2) {
        if (isRunYear(year))
            //���������
            return 29;

        else
            //��������Ļ�
            return 28;
    }
}









