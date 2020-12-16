//�˻ʺ�
//���ݷ���������ȣ����н��
//C++
//Yang Jiangling
/*
������row�е�i��λ��
	�����Ƿ���У� 
		�����С������ǵ�i+1<nλ�û��߻��ݣ���û����һ��λ�ã� 
		���С����Ƿ���Ҷ�ӽڵ㣿 
			�ǡ�����¼��break�����ݣ����ÿ�����һ��λ�ã� 
			�񡪡�������һ�� 
*/

#include<iostream> 
#include<vector> 
using namespace std;

void func(const int n);
void funcIn(const int n, const int row, int *vec);
void PRINT( const int * const result);

int n=8;
vector<int*> results;

int main()
{
	func(n); 
	
	cout<<"Count of solutions: " <<results.size()<<endl;
	for(int i=0;i<results.size();i++)
	{
		cout<<"%"<<i<<endl;
		PRINT(results[i]);
		cout<<endl;
	}
}

void func(const int n)
{
	int *vec=new int[n];//���ڼ�¼���е�λ�� 
	funcIn(n,0,vec);
}

void funcIn(const int n, const int row, int *vec)//�ܹ�n�У����ǵ�row�У�0~row-1��λ�õļ�¼ 
{
	
	for(int i=0;i<n;i++)//��row��ѡ���i��λ���Ƿ���У� 
	{
		int j;
		for(j=0;j<row;j++)//��λ��i��ǰ��ÿһ�е�λ�ñȽ� 
		{
			if(i==vec[j]||i+(row-j)==vec[j]||i-(row-j)==vec[j])//��ͬһ�к�б���ϣ�break��������һ��λ�� 
				break;
		}
		
		if(j==row)//���� 
		{
			vec[row]=i;//��¼ 
			if(row==n-1)//�����һ�� 
			{
				//��¼�˽�� 
				int *result=new int[n];
				copy(vec,vec+n,result);
				results.push_back(result);
				
				break; 
			}
			else//�������һ�У�������һ�� 
				funcIn(n,row+1,vec);
		}
	}
}

void PRINT( const int * const result)
{
	for(int i=0;i<n;i++)//row	
	{
		for(int j=0;j<*(result+i);j++)
			cout<<'_';
		cout<<'#';
		for(int j=*(result+i)+1;j<n;j++)
			cout<<'_';
		cout<<endl;
	}
}
