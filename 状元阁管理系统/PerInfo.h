#ifndef PERINFO_H_
#define PERINFO_H_
#include "STDInfo.h"

/*��Ա����Ϣ�����࣬���봫��string���г�ʼ��*/

class PerInfo :public STDInfo
{
public:
	
	PerInfo( string name);
	
	virtual ~PerInfo();

	PerInfo(const PerInfo&);

	PerInfo operator = (const PerInfo &);

	void setName(string Name);
};

#endif // !PERINFO_H_

