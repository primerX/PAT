#include<cstdio>

int main()
{
	int failA = 0, failB = 0, n;
	scanf("%d", &n);
	while(n--)
	{
		int a1, a2, b1, b2;
		scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
		if(a2 == a1 + b1 && b2 != a1 + b1)		//¼×Ó®
		{
			failB++;
		 }else if(b2 == a1 + b1 && a2 != a1 + b1){ //ÒÑÓ® 
			failA++;
		 } 
	}
	printf("%d %d", failA, failB);
	return 0;
}
