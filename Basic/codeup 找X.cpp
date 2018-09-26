#include<cstdio>

const int MAXN = 500;

int main()
{
	int n, goal, index = -1;
	int number[MAXN];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &number[i]);
	}
	scanf("%d", &goal);
	for(int i=0; i<n; i++)
	{
		if(number[i] == goal) index = i;
	}
	printf("%d", index);
	return 0;
}
