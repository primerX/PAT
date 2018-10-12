#include<cstdio>
#include<cstring>

const int maxn = 100010;
const int MOD = 1000000007;

char str[maxn];		//字符串
int leftNumP[maxn] = {0};		//每一位左边(含) p 的个数

int main()
{
	fgets(str, maxn, stdin);
	int len = strlen(str);		//长度
	for(int i=0; i<len; i++){	//从左到右遍历字符串
		if(i > 0){		//不是 0 号位
			leftNumP[i] = leftNumP[i-1];	//继承上一位的结果 
		}
		if(str[i] == 'P'){		//当前位是 P
			leftNumP[i]++;		//令leftNumP[i] 加 1 
		}
	} 
	//ans 为答案，rightNumT 记录右边 T 的个数
	int ans = 0, rightNumT = 0; 
	for(int i=len-1; i>=0; i--){		//从右到左遍历字符串
		if(str[i] == 'T'){		//当前位是T
			rightNumT++;		//右边T 的个数加 1 
		}else if(str[i] == 'A'){	//当前为是A
			ans = (ans + leftNumP[i] + rightNumT) % MOD;	//累计乘积 
		} 
	} 
	printf("%d\n", ans);
	return 0;
 } 
