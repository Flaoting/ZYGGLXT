#ifndef  STDINFO_H_
#define STDINFO_H_
#include <string>
#include "BaseFile.h"

class  STDInfo : public BaseFile 

	//����ѧ����Ϣ�ļ���
	//�б���λ�ú��������ͣ�Ҳ���ļ�����
{

public:

	STDInfo(string Name);
	
	STDInfo();
	
	STDInfo(const STDInfo&);

	virtual ~STDInfo();


	STDInfo operator = (const STDInfo&);

	void setName(string Name);


};
#endif // ! STDINFO_H_

