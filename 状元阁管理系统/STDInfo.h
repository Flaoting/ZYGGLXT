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
	
	~STDInfo();

	STDInfo operator = (const STDInfo&);

};
#endif // ! STDINFO_H_

