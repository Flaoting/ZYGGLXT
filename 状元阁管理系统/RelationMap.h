#ifndef RELATIONMAP_H_
#define RELATIONMAP_H_

/********************************************************************
					RelationMap
	
	���ǹ�ϵͼ�࣬ά��һ����ʦ��ѧ��Ķ�ά��ͨͼ
	���ǰ���ʦ��ѧ�����ڶԵȵ�λ�ã�֧��˫�����
	�������Ǵ������ݵ��ֻ࣬Ҫ��������޸Ĺ�ϵ����
	��Ȼ���ͼ�����ݺ�ϡ�裬��Ŀǰû��ʲô�õķ���
	����޸�ʱ�� 2020/5/12

*********************************************************************/

class RelationMap 

{
private :

	bool MAP[125][125];//����������������ٸ���

public :
	
	RelationMap();
	~RelationMap();
	
	RelationMap(const RelationMap&);
	RelationMap operator =(const RelationMap&);
	
	void display();
	
	void addRelation(int, int);
	void deleteRelation(int, int);
	void updateFile();


};

#endif // !RELATIONMAP_H_



