#include<cstdio>

const int maxn = 100010;

int main()
{
	int school[maxn] = {0};		//记录每个学校的总分 
	int n, schID, schGD;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &schID, &schGD);
		school[schID] += schGD;
	}
	int k = 1, max = school[1];
	for(int i=0; i<n; i++)
	{
		if(school[i] > max){
			k = i;
			max = school[i];
		}
	}
	printf("%d %d", k, max);
	return 0;
}
