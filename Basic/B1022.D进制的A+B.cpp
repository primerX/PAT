#include<cstdio>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int sum = a + b;
	int ans[31], num = 0;	//ans 用来存放 D 进制的每一位
	do{		//进制转换 
		ans[num++] = sum % c;
		sum /= c;
	} while(sum != 0);
	for(int i=num-1; i>=0; i--)		//从高位到低位进行输出
	{
		printf("%d", ans[i]);
	 } 
	return 0;
}
