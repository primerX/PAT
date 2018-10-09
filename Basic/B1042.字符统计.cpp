#include<cstdio>
#include<cstring>

const int maxn = 1010;
int hashTable[30] = {0};		//用来记录 'a(A)'~'z(Z)' 的出现次数
char str[maxn]; 

int main()
{
	fgets(str, maxn, stdin);
	int len = strlen(str);
	for(int i=0; i<len; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){		//str[i]是小写字母
			hashTable[str[i] - 'a']++;			//str[i]出现次数加 
		}else if(str[i] >= 'A' && str[i] <= 'Z'){	//str[i]是大写字母 
			hashTable[str[i] - 'A']++;		//str[i]对应小写字母的出现次数加 1 
		} 
	}
	int k = 0;		//记录数组中最大元素的下标
	for(int i=0; i<len; i++){
		if(hashTable[i] > hashTable[k]){
			k = i;
		}
	} 
	printf("%c %d\n", 'a' + k, hashTable[k]);		//输出对应的字符和出现次数 
	return 0;
}
