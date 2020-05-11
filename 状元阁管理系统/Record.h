#ifndef  RECORD_H_
#define RECORD_H_
#include "Manager.h"
#include <time.h>

/************************************************************************

	��¼�࣬���ɸ��ּ�¼��
	����

		1.ѧ��������¼
		2.������Ա��¼
		3.������ˮ��¼
		4.֧�����ʼ�¼

**************************************************************************/

class Record

{
protected:

	Manager operatorManager;		//������
	int timeStamp;					//ϵͳʱ�������¼����ʱ��ʱ��


public:

	//ֻ�ܺ��ι��죬����ȱʡ����Ϊ������Ա����ȷ�������
	
	Record(Manager &) ;

	virtual ~Record() ;

	Record(const Record&);

	virtual Record operator =(const Record&);

	virtual int getTimeStamp();

};


#endif // ! RECORD_H_
