#include<cstdio>

int main()
{
	int n, number;
	int count[5] = {0};		//用来存放5类数字的个数
	int ans[5] = {0};		//用来存放5类数字的输出结果 
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &number);	//读入数字
		if(number % 5 == 0){	//A1类 
			if(number % 2 == 0){
				ans[0] += number;
				count[0] ++;
			}
		} else if(number % 5 == 1){		//A2类 
			if(count[1] % 2 == 0){
				ans[1] += number;
			}else{
				ans[1] -= number;
			} 
			count[1]++;
		}else if(number % 5 == 2){		//A3类
			count[2]++;
			ans[2] += 1; 
		}else if(number % 5 == 3){		//A4类 
			count[3]++;
			ans[3] += number;
		}else{							//A5类 
			if(number > ans[4]){
				ans[4] = number;
			}
			count[4]++;
		}
	}
	if(count[0] == 0) printf("N ");
	else printf("%d ", ans[0]);
	if(count[1] == 0) printf("N ");
	else printf("%d ", ans[1]);
	if(count[2] == 0) printf("N ");
	else printf("%d ", count[2]);
	if(count[3] == 0) printf("N ");
	else printf("%.1f ", (double)ans[3]/count[3]);
	if(count[4] == 0) printf("N");
	else printf("%d", ans[4]);
	return 0;
}
