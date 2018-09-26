#include<cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int num = 0, ans[5];	//num 存放 n 的位数
	do{
		ans[num++] = n % 10;
		n /= 10;
	}while(n != 0);
	for(int i=num-1; i>=0; i--)		//从高位到低位枚举
	{
		if(i == 2)		// i 是百位
		{
			for(int j=0; j<ans[i]; j++) printf("B");	//输出ans[i]个B 
		} 
		else if(i == 1)		//如果是十位
		{
			for(int j=0; j<ans[i]; j++) printf("S");	//输出ans[i]个S 
		 }else{		//如果是个位 
		 	for(int j=1; j<=ans[i]; j++) printf("%d", j);
		 } 
	 } 
	return 0;
}
