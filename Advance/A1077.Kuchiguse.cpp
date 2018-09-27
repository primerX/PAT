#include<cstdio>
#include<cstring>

int n, minLen = 256, ans = 0;
char s[100][256];	//至多100 个字符串, 每个字符串至多 256 个字符 

int main()
{
	scanf("%d", &n);	//字符串个数
	getchar();		//接收换行符
	for(int i=0; i<n; i++)
	{
		fgets(s[i], 256, stdin);
		int len = strlen(s[i]);
		if(len < minLen) minLen = len;	//取最小长度
		for(int j=0; i<len/2; j++){		//反转字符串 s[i], 转换为求公共前缀 
			char temp = s[i][j];	//交换
			s[i][j] = s[i][len-j-1];
			s[i][len-j-1] = temp; 
		} 
	 }
	for(int i=0; i<minLen; i++){	//判断所有字符串的第 i 个字符是否全部相等
		char c = s[0][i];		//取第一个字符串的第 i 个字符
		bool same = true;
		for(int j=1; j<n; j++){		//判断其余字符串的第 i 个字符是否等于c
			if(c != s[j][i]){		//只要有一个不等，就停止枚举，说明公共前缀到此
				same = false;
				break; 
			} 
		} 
		if(same) ans++;		//若所有字符串的第 i 位相等，则计数器 ans 加 1
		else break; 
	}
	if(ans){
		for(int i=ans-1; i>=0; i--){
			printf("%c", s[0][i]);
		}
	}else{
		printf("nai");		//不存在公共前缀 
	}
	return 0;
}
