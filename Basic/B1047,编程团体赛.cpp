#include<cstdio>

const int maxn = 1010;
int hashTable[maxn] = {0};		//每个队伍的分数

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int team, member, score;	//队伍编号，队员编号，得分
		scanf("%d-%d %d", &team, &member, &score);
		hashTable[team] += score;		//编号为 team 的队伍加上总分 
	}
	int k, max = -1;
	for(int i=0; i<maxn; i++){		//找到hashTable 数组的最大值
		if(hashTable[i] > hashTable[max]){
			k = i;
			max = hashTable[i];
		} 
	}
	printf("%d %d\n", k, max);		//输出结果 
	return 0;
 } 
