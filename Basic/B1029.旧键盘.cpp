#include<cstdio>
#include<cstring>

int main()
{
	char str1[100], str2[100];
	bool HashTable[128] = {false};		//HashTable数组用来标记字符是否被输出
	fgets(str1, 100, stdin);
	fgets(str2, 100, stdin);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i=0; i<len1; i++){		//遍历第一个字符串中的每个字符
		int j;
		char c1, c2;
		for(j=0; j<len2; j++){		//遍历第二个字符串中的每个字符
			c1 = str1[i];
			c2 = str2[j];
			if(c1 >= 'a' && c1 <= 'z') c1 -= 32;	//如果是小写字母则变为大写
			if(c2 >= 'a' && c2 <= 'z') c2 -= 32;
			if(c1 == c2) break;		//如果c1 在第二个字符串中出现，则跳出 
		} 
		if(j==len2 && HashTable[c1] == false){
			printf("%c", c1);		//在第二个字符串中未出现c1, 且c1 未被输出过
			HashTable[c1] = true; 
		}
	} 
 } 
