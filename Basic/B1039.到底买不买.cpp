#include<cstdio>
#include<cstring>

const int maxn = 1010;
//hashTable 记录第一串中每种颜色的个数, 用 miss 记录缺少的珠子个数
int hashTable[80] = {0}, miss = 0;

//将数字和字母转换成hashTable 的下标
int change(char c)
{
	if(c >= '0' && c <= '9') return c - '0';		//数字
	if(c >= 'a' && c <= 'z') return c - 'a' + 10;		//小写字母 
	if(c >= 'A' && c <= 'Z') return c - 'A' + 36;		//大写字母 
} 

int main()
{
	char whole[maxn], target[maxn];
	fgets(whole, maxn, stdin);
	fgets(target, maxn, stdin);
	int len1 = strlen(whole);
	int len2 = strlen(target);
	for(int i=0; i<len1; i++){		//遍历第一串
		int id = change(whole[i]);	//字符-> hashTable 下标
		hashTable[id]++;		//该颜色个数加 1 
	}
	for(int i=0; i<len2; i++){
		int id = change(target[i]);
		hashTable[id]--;		//改颜色个数减一 
		if(hashTable[id] < 0){		//该颜色个数小于1
			miss++; 
		}
	} 
	if(miss > 0) printf("No %d\n", miss);		//有缺少
	else printf("Yes %d\n", len1 - len2); 
	return 0;
 } 
