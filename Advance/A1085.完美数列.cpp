#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;

int main()
{
	int n, p, a[maxn];
	scanf("%d %d", &n, &p);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]); 
	}
	sort(a, a + n);		//从小到大排序
	int i = 0, j = 0, count = 1;
	while(i<n && j<n){
		//j 不断右移,知道恰好满足条件
		while(j < n && a[j] <= (long long)a[i] * p){
			count = max(count, j - i + 1);		//更新计数器count
			j++; 
		} 
		i++;		//i 右移一位 
	} 
	printf("%d\n", count);
	return 0;
 } 
