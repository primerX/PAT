#include<cstdio>
#include<cstring>

char num[10][10] = {	//数字与单词的对应 
	"zero", "one", "two", "three", "four", "five",
	 "six", "seven", "eight","nine",};
char s[111];	//初始字符串
int digit[10];
 
int main()
{
	fgets(s, 111, stdin);
	int len = strlen(s);
	int sum = 0, numLen = 0;	//sum 为 s 的位数之和，num 计量sum 的长度
	for(int i=0; i<len; i++){
		sum += (s[i] - '0');	//累加 s 的位数,得到 sum 
	}	
	if(sum == 0) {		//如果sum为0，特判输出num[0]
		printf("%s", num[0]); 
	}else{
		while(sum != 0) {	//将sum 存放到 digit 数组中
			digit[numLen++] = sum % 10;
			sum /= 10; 
		}
		for(int i = numLen-1; i>=0; i--){	//从高位到低位输出digit 数组 
			printf("%s", num[digit[i]]);
			if(i !=0 ) printf(" ");		//最后一个单词之后没有空格 
		}
	} 
	return 0;
}
