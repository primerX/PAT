#include<cstdio>

int main()
{
	int n;
	long long A, B, C; 
	scanf("%d", &n);
	int cnt = 1;
	for(int i=0; i<n; i++)
	{
		scanf("%lld %lld %lld", &A, &B, &C);
		if(A + B > C){
			printf("Case #%d: true", cnt);
		}else{
			printf("Case #%d: false", cnt);
		}
		cnt++;
	}
	return 0;
 } 
