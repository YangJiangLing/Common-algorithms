//�ѣ�������
//C++
//Yang Jiangling

/*
����ѣ�ÿһ���ڵ���������������ڵ� 
 
1������ѽṹ
	���������һ����Ҷ�ӽڵ㵽���ڵ㣬��ÿһ����Ҷ�ӽڵ�cur������A���� 

2��A����
	�������������������ֱ��Ƕѽṹ
	�����Ƚ������ӽڵ���һ���󣬼�����LorR�ڵ�
	�����Ƚ�LorR�ڵ��cur�ڵ�Ĵ�С
		���ߴ󡪡���curΪ���������Ѿ���һ����
		ǰ�ߴ󡪡�����cur��LorR��ֵ����ʱcur�ڵ��Ѿ��������ӽڵ㶼��
					���Ǳ��������Ǹ��ӽڵ�������������ܲ����Ƕѣ�
					���Զ�����ڵ����A�������������ֱ��Ҷ�ӽڵ㡣��
					
3��������
 	�������Ǵ��������еġ�
	��������Ѷ�Ӧ��С�������� 
	���������ڵ㣨����λ��0�������һ��Ҷ�ӽڵ㣨����λ��i������ֵ��
			��ʱ���ڵ���Ҫ����A������ʹ������������Ѷ��壬���Ľڵ����Ϊi 
*/
#include<iostream>

using namespace std;

void makeHeap(int arr[],int n);
void heapSort(int *arr,int n);
void funcA(int arr[],int n,int cur);

int main() 
{
	int arr[]={13,56,76,23,67,98,3,46,82,44};
	int n=sizeof(arr)/sizeof(int);
	for(int i=0;i<n;i++) 
		cout<<arr[i]<<' ';
	cout<<endl;
	
	makeHeap(arr,n);
	for(int i=0;i<n;i++) 
		cout<<arr[i]<<' ';
	cout<<endl;
	
	heapSort(arr,n);
	for(int i=0;i<n;i++) 
		cout<<arr[i]<<' ';
	cout<<endl;
}

void makeHeap(int arr[],int n)
{
	for(int i=(n-2)/2;i>=0;i--)
		funcA(arr,n,i);
}

void heapSort(int *arr,int n)
{
	for(int i=n-1;i>=1;i--)
	{
		int temp=arr[i];
		arr[i]=arr[0];
		arr[0]=temp;
		
		funcA(arr,i,0);
	}
}

void funcA(int arr[],int n,int cur)
{
	if(n<=1)
		return;
	
	if(cur>(n-2)/2) //�����Ҷ�ӽڵ㣬ֱ�ӽ��� 
		return;
	
	int leftORright=cur*2+1;//left
	if(cur*2+2<n && arr[cur*2+2]>arr[leftORright] )//�ҽڵ���ڣ����ұ���ڵ�� 
		leftORright=cur*2+2; 
	
	if(arr[cur]<arr[leftORright])
	{
		int temp=arr[cur];
		arr[cur]=arr[leftORright];
		arr[leftORright]=temp;
		
		if(leftORright<=(n-2)/2) 
			funcA(arr,n,leftORright);
	}
}



