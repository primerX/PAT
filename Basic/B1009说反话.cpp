#include<cstdio>

int main()
{
	int num = 0;	//单词的个数
	char ans[90][90];
	while(scanf("%s", &ans[num]) != EOF)	//直到读到文件结束
	{
		num++;
	 } 
	 for(int i=num-1; i>=0; i++)
	 {
	 	printf("%s", ans[i]);
	 	if(i != 0) printf(" ");
	 }
}
