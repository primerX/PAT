#include<cstdio>
#include<cstring>

int main()
{
	char str[1010];
	fgets(str, 1010, stdin);	//读入一行 
	int len = strlen(str);
	
	int count[10] = {0};	//记录0~9 出现的次数
	for(int i=0; i<len; i++)
	{
		count[str[i] - '0']++;	//将str[i] 对应数字的 count 值加1 
	}
	for(int i=0; i<10; i++)		//枚举 0~9
	{
		if(count[i] != 0){
			printf("%d:%d", i, count[i]);
		}
	 } 
	return 0;
}
