#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100005;
//dis[i] ��ʾ 1 �Ž�㰴˳ʱ�뷽�򵽴i+1"�Ž��ľ��� 
int dis[MAXN]={0}, A[MAXN]={0};		//A[i] ��� i ���� i+1 �Ŷ���ľ���
 
int main()
{
	int sum = 0, query, n, left, right;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &A[i]);	
		sum += A[i];		//�ۼ�sum 
		dis[i] = sum;		//Ԥ���� dis ���� 
	}	
	scanf("%d", &query);
	for(int i=0; i<query; i++)		//query ����ѯ
	{
		scanf("%d %d", &left, &right);
		if(left > right) swap(left, right);
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n", min(temp, sum - temp));
	 } 
	return 0;
 } 
