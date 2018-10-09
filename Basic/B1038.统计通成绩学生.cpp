#include<cstdio>
#include<cstring>

int hashTable[110];		//记录每个分数出现的次数

int main()
{
	int n, score, k;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &score);	//分数
		hashTable[score]++;		// 分数score出现的次数加 1 
	}
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		scanf("%d", &score);
		printf("%d", hashTable[score]);		//查询分数出现的次数
		if(i < k-1) printf(" ");		//前k-1 个结果后面输出空格 
	} 
	return 0;
 } 
