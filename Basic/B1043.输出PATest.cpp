#include<cstdio>
#include<cstring>

const int maxn = 10010;
//字符串，字典
char str[maxn], dict[6] = {'P', 'A', 'T', 'e', 's', 't'};
int hashTable[6];		//用来记录 PATest 这 6 个字符的个数 

int main()
{
	fgets(str, maxn, stdin);
	int len = strlen(str);
	int sum = 0; 
	for(int i=0; i<len; i++){		//遍历字符串 
		for(int j=0; j<6; j++){		//遍历dict 字典
			if(str[i] == dict[j]){	//str[i] 在字典中的下标为 i 
				hashTable[j]++;		//个数加 1
				sum++;			//需要输出的字符个数加 1 
			} 
		}
	}
	while(sum > 0)		//当输出的字符个数变成 0 时退出
	{
		for(int i=0; i<6; i++){		//遍历 hashTable 数组
			printf("%c", dict[i]);
			hashTable[i]--;		//个数减一
			sum--;			//需要输出的字符个数减 1 
		}
	 } 
	return 0;
}
