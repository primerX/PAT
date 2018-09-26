#include<cstdio>

struct person{
	char name[15];	//姓名
	char id[15];	//ID
	int score;		//分数 
}M, F, temp;
//M 为男生最低分, 为女生最高分

void init()
{
	M.score = 101;	//初始化男生最低分数为最大值101
	F.score = -1;	//初始化女生最高分数为 -1 
 } 

int main()
{
	init();
	int n;
	char gender;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%s %c %s %d", &temp.name, &gender, &temp.id, &temp.score);
		if(gender == 'M' && temp.score < M.score){
			M = temp;		//更新男生的最低分数 
		}else if(gender == 'F' && temp.score > F.score){
			F = temp;		//更新女生的最高分数 
		}
	}
	if(F.score == -1) printf("Absent\n");	//没有女生
	else printf("%s %s\n", F.name, F.id);
	if(M.score == 101) printf("Absent\n");	//没有男生
	else printf("%s %s\n", M.name, M.id);
	if(F.score == -1 || M.score == 101) printf("NA");
	else printf("%d", F.score - M.score); 
	return 0;
}
