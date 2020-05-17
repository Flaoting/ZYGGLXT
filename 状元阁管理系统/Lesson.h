#ifndef  LESSON_H_
#define LESSON_H_
#include "Date.h"
class Lesson :public Date

	//����һ���γ��࣬��Date�����࣬�����ε����ں͵ڼ��ڵ���Ϣ

{
private:

	int ordinalNumber;//��¼���ǵڼ��ڿ�
    

public:

    Lesson();
    
    Lesson(int year, int month, int day,int ordinalNumber);//����ͨͨ�Ĺ��캯��
    
    Lesson(int month, int day,int ordinalNumber);//���ع��캯����ȱʡ��Ĺ���
    
    Lesson(const Lesson& obj);//�������캯��
    
    Lesson(const Date& obj, int num);//���ںͿγ̽������й���

    bool operator <(const Lesson& obj)const;
    
    //�������Ҫ��Ϊ�˱���ʹ�ñȽϺ�����
    //�����С�ں�����Ϊ���ںţ���Table�о���ʵ��С����

    void display();//��ʾһ��

    int getOriginalNumber();//�������ǵڼ��ڿ�

    bool operator !=(const Lesson&)const;
};
#endif 
