#include<cstdio>

int main()
{
	int num = 0;	//���ʵĸ���
	char ans[90][90];
	while(scanf("%s", &ans[num]) != EOF)	//ֱ�������ļ�����
	{
		num++;
	 } 
	 for(int i=num-1; i>=0; i++)
	 {
	 	printf("%s", ans[i]);
	 	if(i != 0) printf(" ");
	 }
}
