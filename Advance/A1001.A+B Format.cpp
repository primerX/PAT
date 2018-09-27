#include<cstdio>

int main()
{
	int num[10];
	int a, b, sum;
	scanf("%d %d", &a, &b);
	sum = a + b;
	if(sum < 0){	//sum 为负数时，输出负号并取 sum 的相反数 
		printf("-");
		sum = -sum;
	}
	int len = 0;	//len 存放 sum 的长度
	if(sum == 0) num[len++] = 0;	//sum 为 0 时特别处理
	//将 sum 存入数组 num[] 中，其中 sum 的低位存放到 num[] 的低位
	while(sum)
	{
		//将 sum 的末位 sum%10 存放到 num[len], 然后len++
		num[len++] = sum % 10;
		sum /= 10;	//取出 sum 的末位 
	 } 
	 for(int k=len-1; k>=0; k--)	//从高位开始输出
	 {
	 	printf("%d", num[k]);
	 	if(k > 0 && k%3 == 0) printf(",");	//每 3 位一个逗号，最后一位除外 
	  } 
	return 0;
 } 
