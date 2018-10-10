#include<cstdio>

int main()
{
	int count[10];	//记录数字 0 ~ 9 的个数
	for(int i=0; i<10; i++){
		scanf("%d", &count[i]);
	} 
	for(int i=1; i<10; i++){	//从 1~9 中选择 count 不为0的最小数字
		if(count[i] > 0){
			printf("%d", i);
			count[i]--;
			break;				//输出一个之后就break 
		} 
	}
	for(int i=0; i<10; i++){	//从0~9 输出对应个数的数字
		for(int j=0; j<count[i]; j++){
			printf("%d", i);
		} 
	} 
	return 0;
 } 
