#include<cstdio>

int hashTable[10001] = {0};		//用来标记数字出现了几次

int main()
{
	int n;
	int a[100001];			//a[] 为输入的数字 
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		hashTable[a[i]]++;		//数字 a[i] 出现的次数加 1 
	}
	int ans = -1;		//存放第一次出现的在序列中只有一个的数字
	for(int i=0; i<n; i++){
		if(hashTable[a[i]] == 1){		//数字 只出现了一次
			ans = a[i];
			break; 
		}
	} 
	if(ans == -1) printf("None");		//找不到只出现一次的数字
	else printf("%d\n", ans); 
	return 0;
 } 
