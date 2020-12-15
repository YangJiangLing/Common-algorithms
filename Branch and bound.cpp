//��������
//��֧�޽�,��������ȣ� 
//C++
//Yang Jiangling
//���д�����ָ�� 
//����: weights, values, wtLmt
//���: the sequence of putting items

/*
1������
	��������������Ʒ 
2������
	������ֵ��������item����Ŷ�Ӧ��ʹ����pair�ṹ��vector����
	����Ҫ��vector����ʹ����sort�����������˱Ƚ����õĺ��� 
3�����ȶ�UB�ߵĽڵ������չ
	����ʹ�������ȼ����У������˱Ƚ����õ��ࣨ������ 
	
4���㷨 
	����ÿһ��ȡ��UB��ߵĽڵ� 
		�����Ƿ������չ�����ӽڵ㣿 
			�ɡ������ӽڵ���Ҷ�ӽڵ㣿 
				�ǡ������ӽڵ���Ը��´𰸣�
					�ǡ����ȸ��£�Ȼ��ʼ�µ�ѭ�����ҽڵ㲻�ÿ����ˣ� 
				�񡪡�UB�Ƿ����LB�� 
					�ǡ����������ӽڵ���Ϣ���������
		�������ӽڵ��Ƿ���Ҷ�ӽڵ㣿 
			�ǡ����Ƿ���Ը��´𰸣� 
				�ǡ�������
			�񡪡��ж� UB�Ƿ����LB
				�ǡ����������ӽڵ���Ϣ���������
*/
#include<iostream> 
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct node
{
	int w;
	int v;
	double uB;
	int layer; //��չ��ǰ�ڵ�ʱ����Ҫ���ǵ���Ʒ��� 
	vector<int> layerList;
	
	node(){	}
	
	node(int _w, int _v, double _uB, int _layer)
	:w(_w), v(_v), uB(_uB), layer(_layer)
	{	}
	
	void operator= (node _node)
	{
		w=_node.w;
		v=_node.v;
		uB=_node.uB;
		layer=_node.layer;
		layerList=_node.layerList;
	}
};

bool compFunc(pair<double, int> left, pair<double, int> right);
class compClass_priQue
{
public:
	bool operator()(node left, node right);
};

int main()
{
	//1������
	int weights[]={5,7,3,4};
	int values[]={25,42,12,40};
	int wtLmt=10;
	
	//���� 
	int itemTtlNmb=sizeof(weights)/sizeof(int);
	node resultNode;
	resultNode.v=-1;//lB
	
	//2����ֵ�����ȵ�����
	vector<pair<double, int> > rateNsnVector;//��ֵ�����Ⱥ�ԭ��Ʒ��� 
	for(int i=0;i<itemTtlNmb;i++) 
		rateNsnVector.push_back(pair<double, int>(values[i]/1.0/weights[i],i) );
	
	sort(rateNsnVector.begin(),rateNsnVector.end(),compFunc);
	
	for(int i=0;i<itemTtlNmb;i++) 
		cout<<rateNsnVector[i].first<<':'<<rateNsnVector[i].second<<endl;

	//3��ʹ�����ȼ����У�ÿ��ȡ��uB��ߵĽڵ���չ 
	priority_queue<node, vector<node>, compClass_priQue> nodeQueue;
	node curNode(0,0,wtLmt*rateNsnVector[0].first,0);
	nodeQueue.push(curNode);
	
	//cout<<nodeQueue.top()<<endl<<endl;
	//4�� 
	while(!nodeQueue.empty())
	{
		node curNode=nodeQueue.top();//��Ҷ�ӽڵ� 
		nodeQueue.pop();
		
		if(curNode.uB<=resultNode.v)//���нڵ㶼��ֵ����չ 
			break;
				
		//�������ӽڵ���������ڼ���item����������
		int newW=curNode.w+weights[rateNsnVector[curNode.layer].second];
		if(newW<=wtLmt)
		{	
			int newV=curNode.v+values[rateNsnVector[curNode.layer].second];
			if(curNode.layer==itemTtlNmb-1)//�����Ҷ�ӽڵ�
			{
				if(newV>resultNode.v)//��Ƚ�newV��lB 
				{
					curNode.w=newW;
					curNode.v=newV;
					curNode.layerList.push_back(curNode.layer);
					resultNode=curNode;
					continue; 
				}
			}
			else//����Ҷ�ӽڵ� 
			{
				//�Ƿ������ӵ����� 
				double newUB= newV+(wtLmt-newW)*rateNsnVector[curNode.layer+1].first;
				if(newUB>resultNode.v)
				{						
					node left= curNode;
					left.w=newW;
					left.v=newV;
					left.layerList.push_back(left.layer);
					left.layer++; 
					left.uB=newUB;
					nodeQueue.push(left);
				}
			}
		}
		
		//���ӽڵ� 
		if(curNode.layer==itemTtlNmb-1)//�����Ҷ�ӽڵ�
		{
			if(curNode.v>resultNode.v)
				resultNode=curNode;
		}
		else
		{
			curNode.layer++; 
			curNode.uB= curNode.v+(wtLmt-curNode.w)*rateNsnVector[curNode.layer].first;
			if(curNode.uB>resultNode.v)
				nodeQueue.push(curNode);
		}
	}
	
	for(int i=0;i<resultNode.layerList.size();i++)
		cout<<rateNsnVector[resultNode.layerList[i]].second<<endl;
}


bool compFunc(pair<double, int> left, pair<double, int> right)
{
	return left.first>right.first;
}

bool compClass_priQue::operator()(node left, node right)
{
	return left.uB>right.uB;
}
