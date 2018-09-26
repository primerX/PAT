#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100005;
//dis[i] 表示 1 号结点按顺时针方向到达“i+1"号结点的距离 
int dis[MAXN]={0}, A[MAXN]={0};		//A[i] 存放 i 号与 i+1 号顶点的距离
 
int main()
{
	int sum = 0, query, n, left, right;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &A[i]);	
		sum += A[i];		//累加sum 
		dis[i] = sum;		//预处理 dis 数组 
	}	
	scanf("%d", &query);
	for(int i=0; i<query; i++)		//query 个查询
	{
		scanf("%d %d", &left, &right);
		if(left > right) swap(left, right);
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n", min(temp, sum - temp));
	 } 
	return 0;
 } 
