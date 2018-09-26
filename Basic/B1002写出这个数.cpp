#include<cstdio>
#include<cstring>

char change[10][5] = {
	"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"	
};

int main()
{
	char str[110];
	fgets(str, 110, stdin);
	int len = strlen(str);
	int sum = 0;	//sum 存放所有位数之和
	for(int i=0; i<len; i++)
	{
		sum += str[i] - '0';	//将每一位累加	
	}
	
	int num = 0, ans[10];		//num 表示 sum 的位数
	do{
		ans[num++] = sum % 10;
		sum /= 10;
	} while(sum != 0);
	for(int i=num-1; i>=0; i--)
	{
		printf("%s", change[ans[i]]);
		if(i!=0) printf(" ");
		else printf("\n");		//如果是最后一次循环，则输出换行 
	}
	return 0;
}
