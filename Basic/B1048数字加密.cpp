#include<cstdio>
#include<cstring>

const int maxn = 110;
char A[maxn], B[maxn], ans[maxn] = {0};

void reverse(char s[])		//反转字符串
{
	int len = strlen(s);
	for(int i=0; i<len/2; i++){
		int temp = s[i];		//交换s[i] 与 s[len-i-1]
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp; 
	}
 } 

int main()
{
	scanf("%s %s", &A, &B);
	reverse(A);		//将 A 和 B 反转
	reverse(B);
	int lenA = strlen(A);
	int lenB = strlen(B);
	int len = lenA > lenB ? lenA: lenB;		//A和 B的较大长度 
	for(int i=0; i<len; i++)		//从低位开始
	{
		int numA = i < lenA? A[i] -'0' : 0;	//numA对应 A[i]
		int numB = i < lenB? B[i] -'0' : 0;	//numB对应 B[i] 
		if(i % 2 == 0){
			int temp = (numA + numB) % 13;
			if(temp == 10) ans[i] = 'J';
			else if(temp == 11) ans[i] = 'Q';
			else if(temp == 12) ans[i] = 'K';
			else ans[i] = temp + '0';
		}else{
			int temp = numB - numA;
			if(temp < 0) temp += 10;
			ans[i] = temp + '0';	//赋对应的字符 
		}
	 } 
	 reverse(ans);	//反转结果字符
	 puts(ans);		//输出结果 
	return 0;
}
