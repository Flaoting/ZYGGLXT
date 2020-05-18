#include "ViolationRecord.h"



ViolationRecord::ViolationRecord(Manager& obj,Teacher& tea ,
	int first, int second, Date d, string remark)
	:Record(obj),OccurTime(d),VioTeacher(tea)
{

	this->FirstVioCode = first;
	this->SecondCVioCode = second;
	strcpy_s(this->Remarks, remark.c_str());

}

ViolationRecord::ViolationRecord(const ViolationRecord& obj) 
	:Record(obj),OccurTime(obj.OccurTime),VioTeacher(obj.VioTeacher)
{
	this->FirstVioCode = obj.FirstVioCode;
	this->SecondCVioCode = obj.SecondCVioCode;
	strcpy_s(this->Remarks, obj.Remarks);
}


ViolationRecord:: ~ViolationRecord()
{
	//�����������������
}



ViolationRecord ViolationRecord::operator =(const ViolationRecord& obj)


{
	Record::operator=(obj);
	this->VioTeacher = obj.VioTeacher;
	this->OccurTime = obj.OccurTime;
	this->FirstVioCode = obj.FirstVioCode;
	this->SecondCVioCode = obj.SecondCVioCode;
	return *this;
}

void ViolationRecord::display() 
{
	string What = trnaslateVioCode(this->FirstVioCode, this->SecondCVioCode);
	string When = TimeStampToStandard(this->timeStamp);
	cout << "��ѧ�¹ʼ�¼����ʱ��" << When << endl;
	cout << "��ʦ���� :  " << this->VioTeacher.getName() << endl;
	cout << "����ʱ�� :  ";
	this->OccurTime.display();
	cout << endl;
	
	cout << "��ѧ�¹� :  " << What << endl;
	cout << "�¹ʱ�ע �� " << this->Remarks << endl;
	cout << "�Ƿ��ѯ��ʦ������Ϣ���¼����Ա��Ϣ" << endl;
	if (checkToContinue())
	{
		cout << "��ǰ��ʦ��Ϣ����:  " << endl;
		this->VioTeacher.display();
		cout << "���ɼ�¼����Ա��Ϣ���� :  " << endl;
		this->operatorManager.display();

	}
	return;
}



