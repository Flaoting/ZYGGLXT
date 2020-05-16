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


