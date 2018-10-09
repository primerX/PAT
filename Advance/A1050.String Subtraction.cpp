#include<cstdio>
#include<cstring>

const int max_len = 10005;
char a[max_len], b[max_len];
bool hashTable[128];		//记录字符是否在第二个字符串里出现过

int main()
{
	fgets(a, max_len, stdin);
	fgets(b, max_len, stdin);
	int lenA = strlen(a);
	int lenB = strlen(b);
	for(int i=0; i<lenB; i++){
		hashTable[b[i]] = true;		//第二个字符串里的字符table设置为true 
	}
	for(int i=0; i<lenA; i++){
		if(hashTable[a[i]] == false){		//如果在第二个字符串中没出现过
			printf("%c", a[i]); 
		}
	}
	return 0;
 } 
