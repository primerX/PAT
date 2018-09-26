#include<cstdio>

int main()
{
	int a[110];
	int n, m;
	scanf("%d %d", &n, &m);
	m = m % n; 			//保证 m<n
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int count = 0;
	for(int i=n-m; i<n; i++)
	{
		printf("%d", a[i]);
		count++;		//输出的个数加1
		if(count < n) printf(" "); 
	}
	for(int i=0; i<n-m; i++)
	{
		printf("%d", a[i]);
		count++;
		if(count < n) printf(" ");
	}
	return 0;
}
