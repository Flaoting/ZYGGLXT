#ifndef  TEAINFO_H_
#define TEAINFO_H_
#include "STDInfo.h"
class TEAInfo :public STDInfo 
	
	//��ʦ�ļ��࣬��ѧ���ļ����������
	//û��ʲô�߼���ϵ�����ǿ����Ⱥ�Ĺ�ϵ
	//��Ҫ�ǲ�����д������
{
public:

	TEAInfo(string Name);//ֻ��������дһ��
	
	TEAInfo();//��Ȼ���Ҳ����дһ��
	~TEAInfo();
};
#endif // ! TEAINFO_H_
