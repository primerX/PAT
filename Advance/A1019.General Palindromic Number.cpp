#include<cstdio>

bool Judge(int z[], int num)	//判断数组 z 所存的数是否为回文数
{
	for(int i=0; i<= num / 2; i++)
	{
		if(z[i] != z[num - i - 1]) return false;
	}
	return true;
 } 

int main()
{
	int n, b, z[40], num = 0;	//z 用来存放转换结果，num 为其位数
	scanf("%d %d", &n, &b);
	do{
		z[num++] = n % b;
		n /= b;
	} while(n != 0);
	bool flag = Judge(z, num);	//判断数组 z 是否为回文
	if(flag == true) printf("Yes\n");
	else printf("No");
	for(int i=num-1; i>=0; i++)
	{
		printf("%d", z[i]);
		if(i != 0) printf(" ");
	 } 
	return 0;
}
