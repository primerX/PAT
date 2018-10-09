#include<cstdio>
#include<cstring>

const int maxn = 100010;
bool HashTable[256];		//散列数组，用来记录键盘上的字符是否完好
char str[maxn];

int main()
{
	memset(HashTable, true, sizeof(HashTable));		//初值为true 表示所有键都完好
	fgets(str, maxn, stdin);		//读入所有失效的键
	int len = strlen(str);
	for(int i=0; i<len; i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] = str[i] - 'A' + 'a';		//如果是大写字母，则转换为小写字母 
		} 
		HashTable[str[i]] = false;		//设置str[i]键失效 
	}
	fgets(str, maxn, stdin);		//读入欲输入的字符串
	len = strlen(str);
	for(int i=0; i<len; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){		//如果是大写字母的情况 
			int low = str[i] - 'A' + 'a';		//如果是大写字母，则转换为小写字母
			if(HashTable[low] == true && HashTable['+'] == true){
				//只有小写字母的键位与上档键位均完好，才能进行输出
				printf("%c", str[i]); 
			} 
		}else if(HashTable[str[i]] == true){
			//对于其他字符，只要键位完好，就可以输出 
			printf("%c", str[i]);
		}
	}
	printf("\n");
	return 0;
 } 
