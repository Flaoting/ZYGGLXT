#include "Lesson.h"
#include "Date.h"



Lesson::Lesson()
{
	Date::Date();
	ordinalNumber = 0;
}

Lesson::Lesson(int year, int month, int day, int ordinalNumber):Date(year,month,day)

//����ͨͨ�Ĺ��캯��

{
	Date::Date(year, month, day);
	string expect1;
	try 
	{
		if (ordinalNumber > 5 || ordinalNumber <= 0)
		{
			expect1 = "�γ�ʱ�������쳣!!!";
			throw expect1;
		}


	}
	catch (string goal)
	{
		cout << goal << endl;
	}

	this->ordinalNumber = ordinalNumber;
	
}

Lesson::Lesson(int month, int day, int ordinalNumber):Date( month, day)

//���ع��캯����ȱʡ��Ĺ���

{
	Date::Date(month, day);
	string expect1;
	try
	{
		if (ordinalNumber > 5 || ordinalNumber <= 0)
		{
			expect1 = "��ʱ�������쳣!!!";
			throw expect1;
		}	
	}
	catch (string goal)
	{
		cout << goal << endl;
	}

	this->ordinalNumber = ordinalNumber;
	
}

Lesson::Lesson(const Lesson& obj) : Date(obj)

//�������캯��
{

	Date::Date(obj);
	//cout << "Lesson ����"<<endl;
	this->ordinalNumber = obj.ordinalNumber;

}

Lesson::Lesson(const Date& obj, int num):Date(obj)

{
	this->ordinalNumber = num;
	Date::Date(obj);
	string expect1;
	try
	{
		if (ordinalNumber > 5 || ordinalNumber <= 0)
		{
			expect1 = "�γ����������쳣!!!";
			throw expect1;
		}
	}
	catch (string goal)
	{
		cout << goal << endl;
	}

	
	
	//cout << "���ڹ��캯����" << endl;
}

void Lesson::display()

//��ʾһ��

{
	Date::display();
	cout <<"�� "<< ordinalNumber <<"��"<< endl;
}

bool Lesson::operator <(const Lesson& obj)const

	//�������Ҫ��Ϊ�˱���ʹ�ñȽϺ���
	//�����С�ں�����Ϊ���ںţ�������Table���ʵ��С����
	//�Ӷ�ʵ�ֿɱ������˳���Ǵ�С���ڵ�������

{
	int a = year - obj.year;

	if (a > 0)return 1;
	if (a < 0)return 0;
	
	if (a == 0) 
	{
		int b = month - obj.month;
		
		if (b > 0)return 1;
		if (b < 0)return 0;
		
		if (b == 0) 
		{
			int c = day - obj.day;
		
			if (c > 0)return 1;
			
			if (c < 0)return 0;
			
			if (c == 0)return 0;
		}
	}

	if (this->ordinalNumber >= obj.ordinalNumber) 
		//�γ̽����ıȽϣ�Ч����ǰ������⿴��һ��ע��	
	{
		return 1;
	}
	//�����Ƿ���0
	return 0;
}

int Lesson::getOriginalNumber() 
{
	return this->ordinalNumber;
}

bool Lesson::operator !=(const Lesson& obj)const 
{
	if (this->day != obj.day)
	{
		return true;
	}
	if (this->month != obj.month)
	{
		return true;
	}
	if (this->ordinalNumber != obj.ordinalNumber)
	{
		return true;
	}

	return false;


}

